//
//  main.h
//  
//  Created by clsergent on 13/05/2018.
//

//FUSE SET (16Khz PLL) : avrdude -c usbtiny -p attiny85

#define LED_PB PORTB4
#define BUTTON_PB PINB3

#define initPB DDRB |= (1<<LED_PB) & ~(1<<BUTTON_PB)

#define switchLED_OFF PORTB &= ~(1<<LED_PB)
#define switchLED_ON PORTB |= (1<<LED_PB)
#define blinkLED PORTB ^= (1<<LED_PB)

#define BUTTON_STATE (PINB & (1<<BUTTON_PB))
#define BUTTON_PRESSED 0
#define BUTTON_RELEASED 1
#define BUTTON_RESET 2
#define BUTTON_TIMER 500 // x10ms = 5s

#define MESSAGE_SIZE 90
#define MESSAGE_READY 1
#define MESSAGE_SENT 0
#define MESSAGE_VOID MESSAGE_SENT

#define PASSWORD_SIZE 40

#define OPTION_TRUE 0x01
#define OPTION_FALSE 0x00

#define AUTOREAD_TRUE OPTION_TRUE
#define AUTOREAD_FALSE OPTION_FALSE

#define LINEFEED_TRUE OPTION_TRUE
#define LINEFEED_FALSE OPTION_FALSE

#define HELP "e:s echo s | "  \
             "n new | "\
             "r read | "\
             "w:b:i write b at i | " \
             "d delete | "\
             "l:i length i | "\
             "f:i linefeed i"

typedef struct {
	uint8_t flag;
	uint16_t timer;
} button_t;

button_t button;

typedef struct {
    uint8_t len;
    uint8_t data[PASSWORD_SIZE];
} password_t;

password_t EEMEM password;
uint8_t EEMEM linefeed;
uint8_t EEMEM autoread;

const uint8_t PROGMEM help[] = HELP;

typedef struct {
    uint8_t modifiers;
    uint8_t reserved; 
    uint8_t keycode[6]; //only one keystroke at a time (otherwise, use SIMULTANEOUS_KEYSTROKES and an array)
} keyboard_report_t;

typedef struct {
    uint8_t flag;
    uint8_t len;
    uint8_t data[MESSAGE_SIZE];
} message_report_t;

void updateUSB();
void initUSB();

void toKeyCode(uint8_t chr, keyboard_report_t *report);

void sendKeyPress(keyboard_report_t *report);
void sendKeyPress2(uint8_t keycode, uint8_t modifiers);
void sendKeyStroke(keyboard_report_t *report);

void sendString(uint8_t *data, uint8_t len);
void sendString_P(const uint8_t *data, uint8_t len);
void sendString_E(uint8_t *data, uint8_t len);

void prepareReport(uint8_t *data, uint8_t len);
void prepareReport_P(const uint8_t *data, uint8_t len);
void sendReport();

uint8_t randomChar();

void initPassword();
void deletePassword();
uint8_t readPasswordLen();
void writePasswordLen(uint8_t len);
void readPassword(uint8_t *data, uint8_t *len);
void writePassword(uint8_t *data, uint8_t len);

uint8_t readOption(uint8_t *option);
void writeOption(uint8_t *option, uint8_t value);

void initButton();
void startButtonTimer();
void clearButtonTimer();
