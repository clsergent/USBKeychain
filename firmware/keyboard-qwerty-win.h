//
//  keyboard.h
//
//  Created by clsergent on 13/05/2018.
//

#ifndef keyboard_h
#define keyboard_h

/* data from http://www.usb.org/developers/hidpage/. */
/* USB report descriptor (length: 63)*/
const PROGMEM char usbHidReportDescriptor[USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH] = {
        0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
        0x09, 0x06,                    // USAGE (Keyboard)
        0xa1, 0x01,                    // COLLECTION (Application)
        0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
        0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
        0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
        0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
        0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
        0x75, 0x01,                    //   REPORT_SIZE (1)
        0x95, 0x08,                    //   REPORT_COUNT (8)
        0x81, 0x02,                    //   INPUT (Data,Var,Abs)
        0x95, 0x01,                    //   REPORT_COUNT (1)- necessary for microsoft...
        0x75, 0x08,                    //   REPORT_SIZE (8)- necessary for microsoft...
        0x81, 0x03,                    //INPUT (Cnst,Var,Abs)- necessary for microsoft...
        0x95, 0x05,                    //   REPORT_COUNT (5)
        0x75, 0x01,                    //   REPORT_SIZE (1)
        0x05, 0x08,                    //   USAGE_PAGE (LEDs)
        0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
        0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
        0x91, 0x02,                    //OUTPUT (Data,Var,Abs)
        0x95, 0x01,                    //   REPORT_COUNT (1)
        0x75, 0x03,                    //   REPORT_SIZE (3)
        0x91, 0x03,                    //OUTPUT (Cnst,Var,Abs)
        0x95, 0x06,                    //   REPORT_COUNT (SIMULTANEOUS_KEYSTROKES) - 6 for microsoft...
        0x75, 0x08,                    //   REPORT_SIZE (8)
        0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
        0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
        0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
        0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
        0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
        0x81, 0x00,                    //INPUT (Data,Ary,Abs)
        0xc0                           // END_COLLECTION
};

//const PROGMEM char usbHidReportDescriptor[USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH] = {
//        0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
//        0x09, 0x06,                    // USAGE (Keyboard)
//        0xa1, 0x01,                    // COLLECTION (Application)
//        0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
//        0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
//        0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
//        0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
//        0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
//        0x75, 0x01,                    //   REPORT_SIZE (1)
//        0x95, 0x08,                    //   REPORT_COUNT (8)
//        0x81, 0x02,                    //   INPUT (Data,Var,Abs)
//        0x95, 0x01,                    //   REPORT_COUNT (1)
//        0x75, 0x08,                    //   REPORT_SIZE (8)
//        0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
//        0x95, 0x05,                    //   REPORT_COUNT (5)
//        0x75, 0x01,                    //   REPORT_SIZE (1)
//        0x05, 0x08,                    //   USAGE_PAGE (LEDs)
//        0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
//        0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
//        0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
//        0x95, 0x01,                    //   REPORT_COUNT (1)
//        0x75, 0x03,                    //   REPORT_SIZE (3)
//        0x91, 0x02,                    //   OUTPUT (Cnst,Var,Abs)
//        0x95, SIMULTANEOUS_KEYSTROKES, //   REPORT_COUNT (SIMULTANEOUS_KEYSTROKES)
//        0x75, 0x08,                    //   REPORT_SIZE (8)
//        0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
//        0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
//        0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
//        0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
//        0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
//        0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
//        0xc0                           // END_COLLECTION
//};

#define ASCII_BACKSPACE 8
#define ASCII_TAB 9
#define ASCII_LINEFEED 10
#define ASCII_ESCAPE 27

#define SCAN_BACKSPACE 42
#define SCAN_TAB 43
#define SCAN_LINEFEED 40
#define SCAN_ESCAPE 41

#define MOD_CONTROL_LEFT    (1<<0)
#define MOD_SHIFT_LEFT      (1<<1)
#define MOD_ALT_LEFT        (1<<2)
#define MOD_GUI_LEFT        (1<<3)
#define MOD_CONTROL_RIGHT   (1<<4)
#define MOD_SHIFT_RIGHT     (1<<5)
#define MOD_ALT_RIGHT       (1<<6)
#define MOD_GUI_RIGHT       (1<<7)

#define KEY_A       4
#define KEY_B       5
#define KEY_C       6
#define KEY_D       7
#define KEY_E       8
#define KEY_F       9
#define KEY_G       10
#define KEY_H       11
#define KEY_I       12
#define KEY_J       13
#define KEY_K       14
#define KEY_L       15
#define KEY_M       16
#define KEY_N       17
#define KEY_O       18
#define KEY_P       19
#define KEY_Q       20
#define KEY_R       21
#define KEY_S       22
#define KEY_T       23
#define KEY_U       24
#define KEY_V       25
#define KEY_W       26
#define KEY_X       27
#define KEY_Y       28
#define KEY_Z       29
#define KEY_1       30
#define KEY_2       31
#define KEY_3       32
#define KEY_4       33
#define KEY_5       34
#define KEY_6       35
#define KEY_7       36
#define KEY_8       37
#define KEY_9       38
#define KEY_0       39

#define KEY_ENTER   40

#define KEY_SPACE   44

#define KEY_F1      58
#define KEY_F2      59
#define KEY_F3      60
#define KEY_F4      61
#define KEY_F5      62
#define KEY_F6      63
#define KEY_F7      64
#define KEY_F8      65
#define KEY_F9      66
#define KEY_F10     67
#define KEY_F11     68
#define KEY_F12     69

#define KEY_ARROW_LEFT 0x50

#endif /* keyboard_h */

