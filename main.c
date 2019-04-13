//
//  main.c
//  
//  Created by Clair-Loup Sergent on 13/05/2018.
//


#include <avr/io.h>
#include <avr/interrupt.h>

#include <avr/eeprom.h>
#include <avr/pgmspace.h>

#include <util/delay.h>
#include <avr/wdt.h>

#include <string.h>

//#define USB_PUBLIC static
#include "./usbdrv/usbdrv.h"
#include "./keyboard-azerty-mac.h"
#include "./main.h"

//----- transmission variables ------

static uint8_t requestIdleRate; // repeat rate for keyboards
static uint8_t requestLen;

#define SPECIAL_FLAG 3

static keyboard_report_t keyboardReportStruct = {0,0,{0,0,0,0,0,0}};
static message_report_t messageReportStruct;

keyboard_report_t *keyboardReport = &keyboardReportStruct;
message_report_t *messageReport = &messageReportStruct;

/*----- usb requests handling -----*/

USB_PUBLIC uchar usbFunctionSetup(uchar data[8]) {
    usbRequest_t *rq = (usbRequest_t *)((void *)data);
    if ((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS) {
        /* class request type */
        switch (rq->bRequest) {
            case USBRQ_HID_GET_REPORT:
                usbMsgPtr = (void *)keyboardReport; // we only have this one
                keyboardReport->modifiers = 0;
                keyboardReport->keycode[0] = 0;
                return sizeof(*keyboardReport);
            case USBRQ_HID_SET_REPORT: // if wLength == 1, should be LED state
                return USB_NO_MSG;//(rq->wLength.word == 1) ? USB_NO_MSG : 0;
            case USBRQ_HID_GET_IDLE: // send idle rate to PC as required by spec
                usbMsgPtr = &requestIdleRate;
                return 1;
            case USBRQ_HID_SET_IDLE: // save idle rate as required by spec
                requestIdleRate = rq->wValue.bytes[1];
                return 0;
        }
    }
    else if ((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_VENDOR) {
        switch (rq->bRequest) {
            case SPECIAL_FLAG:
                requestLen= (uint8_t)rq->wLength.word;
                return USB_NO_MSG; //pass to usbFunctionWrite
            default:
                return 0;
        }
    }
    return 0;
}

//receive data from the host using this scheme <1byte key>[:optional argument]
/*command are
    e = echo --> argument is echoed (debug)
    n =  new --> new random paswword is generated
    r = read --> send the password
    w = write --> write the given char at the given position in password (and eventually update password length) (arg = position:char)
    d = delete --> delete the password
    l = set the password maximum length (still shorter than PASSWORD_MAX_SIZE)
    f = set wether to add a linefeed at the end of any string
*/

usbMsgLen_t usbFunctionWrite(uint8_t * data, uchar len) {
    switch (data[0]) {
        case '0':
            switchLED_OFF;
            return len;
        case '1':
            switchLED_ON;
            return len;
        case 'e':
            if (len >= 3) {
                prepareReport(&data[2], len-2);
            }
            return len;
        case 'n':
            initPassword();
            return len;
        case 'r':
            readPassword(messageReport->data, &(messageReport->len));
            messageReport->flag = MESSAGE_READY;
            return len;
        case 'w':
            if (len == 5) {
                eeprom_write_byte(&(password.data[data[2]]), data[4]);
//                if (readPasswordLen() < (data[2] + 1)) {
//                    writePasswordLen(data[2] + 1);
//                }
            }
            return len;
        case 'l':
            if (len == 3) {
                writePasswordLen(data[2]);
            }
            return len;
        
        case 'f':
            if (len == 3) {
                writeOption(&linefeed, data[2]);
                return len;
            }
        case 'd':
            deletePassword();
            return len;
        case 'h':
            prepareReport_P(help, sizeof(help));
            return len;
		case 'a':
			writeOption(&autoread, data[2]);
			return len;
    }
    return len;
}

void initUSB() {
    wdt_enable(WDTO_2S);
    cli();
    usbDeviceDisconnect();
    wdt_reset();
    _delay_ms(250);
    wdt_reset();
    usbDeviceConnect();

    usbInit();

    sei();
    
    sendKeyPress2(0, 0); //first keypress is not taken into account
    switchLED_ON; //keyPress blink LED, so it must be turned on again
    
}

void updateUSB() {
    wdt_reset();
    usbPoll();
}

/*----- keyboard handling -----*/

//void toKeyCode(uint8_t chr, keyboard_report_t *report) {
//    if (chr < 32) {   //ASCII codes < 32 are handled "by hand" to reduce memory consuption as only 4 codes are useful
//        switch (chr) {
//            case ASCII_BACKSPACE:
//                report->keycode[0] = SCAN_BACKSPACE;
//                break;
//            case ASCII_TAB:
//                report->keycode[0] = SCAN_TAB;
//                break;
//            case ASCII_LINEFEED:
//                report->keycode[0] = SCAN_LINEFEED;
//                break;
//            case ASCII_ESCAPE:
//                report->keycode[0] = SCAN_ESCAPE;
//                break;
//            default:    //unused ASCII codes are not handled at all
//                report->keycode[0]= 0;
//        }
//    } else {
//        report->keycode[0]= pgm_read_byte_near(ASCII_to_scan + (chr - 32));
//    }
//
//    report->modifiers = report->keycode[0] >> 7 ? MOD_SHIFT_LEFT : 0;
//    report->keycode[0] &= 0b01111111;
//}

void toKeyCode(uint8_t chr, keyboard_report_t *report) {
    if (chr < 32) {   //ASCII codes < 32 are handled "by hand" to reduce memory consuption as only 4 codes are useful
        switch (chr) {
            case ASCII_BACKSPACE:
                report->keycode[0] = SCAN_BACKSPACE;
                break;
            case ASCII_TAB:
                report->keycode[0] = SCAN_TAB;
                break;
            case ASCII_LINEFEED:
                report->keycode[0] = SCAN_LINEFEED;
                break;
            case ASCII_ESCAPE:
                report->keycode[0] = SCAN_ESCAPE;
                break;
            default:    //unused ASCII codes are not handled at all
                report->keycode[0]= 0;
        }
    } else {
        report->modifiers = pgm_read_byte_near(ASCII_to_scan + 2*(chr - 32)+1);
        report->keycode[0]= pgm_read_byte_near(ASCII_to_scan + 2*(chr - 32)) & 0b01111111;
    }
}

//sendKeyPress: sends a key press only, with modifiers - no release
void sendKeyPress(keyboard_report_t *report) {
    while (!usbInterruptIsReady()) {
        updateUSB();
    }
    usbSetInterrupt((void *)report, sizeof(*report));
    blinkLED;
}

void sendKeyPress2(uint8_t keycode, uint8_t modifiers) {
    keyboardReport->modifiers = modifiers;
    keyboardReport->keycode[0] = keycode;
    sendKeyPress(keyboardReport);
}

//sendKeyStroke: sends a key press AND release with modifiers
void sendKeyStroke(keyboard_report_t *report) {
    sendKeyPress(report);
    // This stops endlessly repeating keystrokes:
    sendKeyPress2(0,0);
}

void sendString(uint8_t *data, uint8_t len) {
    uint8_t i;
    for (i= 0; i < len; i++) {
        toKeyCode(data[i], keyboardReport);
        sendKeyStroke(keyboardReport);
    }
    if (readOption(&linefeed) == LINEFEED_TRUE) {
        toKeyCode(ASCII_LINEFEED, keyboardReport);
        sendKeyStroke(keyboardReport);
    }
}

/*---- messageReport handling ----*/

//fill messageReport and mark it as ready
void prepareReport(uint8_t *data, uint8_t len) {
    memcpy(messageReport->data, data, len);
    messageReport->len = len;
    messageReport->flag = MESSAGE_READY;
}

//fill messageReport with data from PROGMEM and mark it as ready
void prepareReport_P(const uint8_t *data, uint8_t len) {
    memcpy_P(messageReport->data, data, len);
    messageReport->len = len;
    messageReport->flag = MESSAGE_READY;
}

//send messageReport if it is ready
void sendReport() {
    if (messageReport->flag == MESSAGE_READY) {
        sendString(messageReport->data, messageReport->len);
        messageReport->flag = MESSAGE_SENT;
    }
}


/*---- password handling ----*/

//return a random character amongst the ones useable for a password
uint8_t randomChar() {
    return (TCNT0 ^ TCNT1 )% 95 + 32; //choosing in ASCII (except first value wich is space --> %94 +33)
}

void initPassword() {
    uint8_t i;
    for (i=0; i< PASSWORD_SIZE; i++) {
        eeprom_write_byte(&(password.data[i]), randomChar());
    }
}

void deletePassword() {
    uint8_t i;
    for (i=0; i< PASSWORD_SIZE; i++) {
        eeprom_write_byte(&(password.data[i]), 0);
    }
	writePasswordLen(0);
}

uint8_t readPasswordLen() {
    uint8_t len;
    len = eeprom_read_byte(&(password.len));
    return len <=PASSWORD_SIZE ? len: PASSWORD_SIZE;
}

void writePasswordLen(uint8_t len) {
	if (len > 0) {
		switchLED_ON;
	} else {
		switchLED_OFF;
	}
    eeprom_write_byte(&(password.len), len <= PASSWORD_SIZE ? len: PASSWORD_SIZE);
}

void readPassword(uint8_t *data, uint8_t *len) {
    *len = readPasswordLen();
    eeprom_read_block(data, password.data, *len <= PASSWORD_SIZE ? *len: PASSWORD_SIZE);
}

void writePassword(uint8_t *data, uint8_t len) {
    writePasswordLen(len);
    if (len > 0) {
        eeprom_write_block(data, password.data, len <= PASSWORD_SIZE ? len: PASSWORD_SIZE);
    }
}

void sendPassword() {
	readPassword(messageReport->data, &(messageReport->len));
	messageReport->flag = MESSAGE_READY;
}

/*-------- autoread option handling ----------*/
//choose wether to send the password during the boot sequence

uint8_t readOption(uint8_t *option) {
	return eeprom_read_byte(option);
}

void writeOption(uint8_t *option, uint8_t value) {
	if (value == OPTION_TRUE) {
		eeprom_write_byte(option, OPTION_TRUE);
	} else {
		eeprom_write_byte(option, OPTION_FALSE);
	}
}

/*-------- pushbutton handling ---------*/
//a timer is set everytime the button is pressed. If it reach zero before the button is released, the password is cleared (no backup!)
void initButton() {
	OCR0A = 161; // OCR0A(161) * TCCR0B (1024) / CPU = 0.01s
	clearButtonTimer();
}

void startButtonTimer() {
	button.flag = BUTTON_PRESSED;
	button.timer = BUTTON_TIMER;
	TCNT0 = 0;
	TIMSK |= (1<<OCIE0A);
    TCCR0B = (1 << CS02) | (1 << CS00);//prescaler = 1024
}

void clearButtonTimer() {
	button.flag = BUTTON_RELEASED;
	TIMSK &= ~(1<<OCIE0A);
    TCCR0B = (1 << CS01);//prescaler = 8 (used for randomn pickup)
}

ISR(TIMER0_COMPA_vect) {
	cli();
	if ((button.flag == BUTTON_PRESSED) && !button.timer--) {
		button.flag = BUTTON_RESET;
		switchLED_OFF;
	}
	TCNT0 = 0;
	sei();
}

int main(void) {
    initPB;
    initButton();
    initUSB();

	//switch LED OFF if no password is stored
	if (readPasswordLen() == 0) {
		switchLED_OFF;
	}
	else { //send the password during the boot sequence
		switchLED_ON;
		if (readOption(&autoread) == AUTOREAD_TRUE) {
			sendPassword();
		}
	}

	while(1) {
		if (!BUTTON_STATE && (button.flag == BUTTON_RELEASED)) { //button is being pressed
			startButtonTimer();
		}

		if (BUTTON_STATE && (button.flag != BUTTON_RELEASED)) { //button is being released
			if (button.flag == BUTTON_RESET) {
				deletePassword();
            } else {
                sendPassword();
            }
            clearButtonTimer();
        }
        updateUSB();
        sendReport();
    }

	return 0;
}



