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

#define KEY_A       20
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
#define KEY_M       51
#define KEY_N       17
#define KEY_O       18
#define KEY_P       19
#define KEY_Q       4
#define KEY_R       21
#define KEY_S       22
#define KEY_T       23
#define KEY_U       24
#define KEY_V       25
#define KEY_W       29
#define KEY_X       27
#define KEY_Y       28
#define KEY_Z       26
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

//correspondance is done by substracting 32 to the ASCII character (95 characters)
const PROGMEM uint8_t ASCII_to_scan[] = {
    44, 0,                         //ASCII 32 SPACE
    37, 0,                         //ASCII 33 !
    32, 0,                         //ASCII 34 "
    100, MOD_SHIFT_LEFT,           //ASCII 35 #
    48, 0,                         //ASCII 36 $
    52, MOD_SHIFT_LEFT,            //ASCII 37 %
    30, 0,                         //ASCII 38 &
    33, 0,                         //ASCII 39 SINGLE QUOTE
    34, 0,                         //ASCII 40 (
    45, 0,                         //ASCII 41 )
    48, MOD_SHIFT_LEFT,            //ASCII 42 *
    56, MOD_SHIFT_LEFT,            //ASCII 43 +
    16, 0,                         //ASCII 44 COMMA
    46, 0,                         //ASCII 45 -
    54, MOD_SHIFT_LEFT,            //ASCII 46 .
    55, MOD_SHIFT_LEFT,            //ASCII 47 /
    39, MOD_SHIFT_LEFT,            //ASCII 48 0
    30, MOD_SHIFT_LEFT,            //ASCII 49 1
    31, MOD_SHIFT_LEFT,            //ASCII 50 2
    32, MOD_SHIFT_LEFT,            //ASCII 51 3
    33, MOD_SHIFT_LEFT,            //ASCII 52 4
    34, MOD_SHIFT_LEFT,            //ASCII 53 5
    35, MOD_SHIFT_LEFT,            //ASCII 54 6
    36, MOD_SHIFT_LEFT,            //ASCII 55 7
    37, MOD_SHIFT_LEFT,            //ASCII 56 8
    38, MOD_SHIFT_LEFT,            //ASCII 57 9
    55, 0,                         //ASCII 58 :
    54, 0,                         //ASCII 59 ;
    53, 0,                         //ASCII 60 <
    56, 0,                         //ASCII 61 =
    53, MOD_SHIFT_LEFT,            //ASCII 62 >
    16, MOD_SHIFT_LEFT,            //ASCII 63 ?
    100, 0,                        //ASCII 64 @
    20, MOD_SHIFT_LEFT,            //ASCII 65 A
    5, MOD_SHIFT_LEFT,             //ASCII 66 B
    6, MOD_SHIFT_LEFT,             //ASCII 67 C
    7, MOD_SHIFT_LEFT,             //ASCII 68 D
    8, MOD_SHIFT_LEFT,             //ASCII 69 E
    9, MOD_SHIFT_LEFT,             //ASCII 70 F
    10, MOD_SHIFT_LEFT,            //ASCII 71 G
    11, MOD_SHIFT_LEFT,            //ASCII 72 H
    12, MOD_SHIFT_LEFT,            //ASCII 73 I
    13, MOD_SHIFT_LEFT,            //ASCII 74 J
    14, MOD_SHIFT_LEFT,            //ASCII 75 K
    15, MOD_SHIFT_LEFT,            //ASCII 76 L
    51, MOD_SHIFT_LEFT,            //ASCII 77 M
    17, MOD_SHIFT_LEFT,            //ASCII 78 N
    18, MOD_SHIFT_LEFT,            //ASCII 79 O
    19, MOD_SHIFT_LEFT,            //ASCII 80 P
    4, MOD_SHIFT_LEFT,             //ASCII 81 Q
    21, MOD_SHIFT_LEFT,            //ASCII 82 R
    22, MOD_SHIFT_LEFT,            //ASCII 83 S
    23, MOD_SHIFT_LEFT,            //ASCII 84 T
    24, MOD_SHIFT_LEFT,            //ASCII 85 U
    25, MOD_SHIFT_LEFT,            //ASCII 86 V
    29, MOD_SHIFT_LEFT,            //ASCII 87 W
    27, MOD_SHIFT_LEFT,            //ASCII 88 X
    28, MOD_SHIFT_LEFT,            //ASCII 89 Y
    26, MOD_SHIFT_LEFT,            //ASCII 90 Z
    34, MOD_SHIFT_LEFT | MOD_ALT_LEFT,            //ASCII 91 [
    55, MOD_SHIFT_LEFT | MOD_ALT_LEFT,            //ASCII 92 BACKSLASH
    45, MOD_SHIFT_LEFT | MOD_ALT_LEFT,            //ASCII 93 ]
    47, 0,                         //ASCII 94 ^
    46, MOD_SHIFT_LEFT,            //ASCII 95 _
    49, 0,            //ASCII 96 `
    20, 0,            //ASCII 97 a
    5, 0,             //ASCII 98 b
    6, 0,             //ASCII 99 c
    7, 0,             //ASCII 100 d
    8, 0,             //ASCII 101 e
    9, 0,             //ASCII 102 f
    10, 0,            //ASCII 103 g
    11, 0,            //ASCII 104 h
    12, 0,            //ASCII 105 i
    13, 0,            //ASCII 106 j
    14, 0,            //ASCII 107 k
    15, 0,            //ASCII 108 l
    51, 0,            //ASCII 109 m
    17, 0,            //ASCII 110 n
    18, 0,            //ASCII 111 o
    19, 0,            //ASCII 112 p
    4, 0,             //ASCII 113 q
    21, 0,            //ASCII 114 r
    22, 0,            //ASCII 115 s
    23, 0,            //ASCII 116 t
    24, 0,            //ASCII 117 u
    25, 0,            //ASCII 118 v
    29, 0,            //ASCII 119 w
    27, 0,            //ASCII 120 x
    28, 0,            //ASCII 121 y
    26, 0,            //ASCII 122 z
    34, MOD_ALT_LEFT, //ASCII 123 {
    15, MOD_SHIFT_LEFT | MOD_ALT_LEFT,            //ASCII 124 |
    45, MOD_SHIFT_LEFT | MOD_ALT_LEFT,            //ASCII 125 }
    17, MOD_ALT_LEFT,            //ASCII 126 ~
};

#endif /* keyboard_h */

