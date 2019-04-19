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

//correspondance is done by substracting 32 to the ASCII character (95 characters)
const PROGMEM uint8_t ASCII_to_scan[] = {
44,    //44, ASCII 32 SPACE
158,    //30 + (1<<7), ASCII 33 !
180,    //52 + (1<<7), ASCII 34 "
160,    //32 + (1<<7), ASCII 35 #
161,    //33 + (1<<7), ASCII 36 $
162,    //34 + (1<<7), ASCII 37 %
164,    //36 + (1<<7), ASCII 38 &
52,    //52, ASCII 39 SINGLE QUOTE
166,    //38 + (1<<7), ASCII 40 (
167,    //39 + (1<<7), ASCII 41 )
165,    //37 + (1<<7), ASCII 42 *
174,    //46 + (1<<7), ASCII 43 +
54,    //54, ASCII 44 APOSTROPHY
45,    //45, ASCII 45 -
55,    //55, ASCII 46 .
56,    //56, ASCII 47 /
39,    //39, ASCII 48 0
30,    //30, ASCII 49 1
31,    //31, ASCII 50 2
32,    //32, ASCII 51 3
33,    //33, ASCII 52 4
34,    //34, ASCII 53 5
35,    //35, ASCII 54 6
36,    //36, ASCII 55 7
37,    //37, ASCII 56 8
38,    //38, ASCII 57 9
179,    //51 + (1<<7), ASCII 58 :
51,    //51, ASCII 59 ;
182,    //54 + (1<<7), ASCII 60 <
46,    //46, ASCII 61 =
183,    //55 + (1<<7), ASCII 62 >
184,    //56 + (1<<7), ASCII 63 ?
159,    //31 + (1<<7), ASCII 64 @
132,    //4 + (1<<7), ASCII 65 A
133,    //5 + (1<<7), ASCII 66 B
134,    //6 + (1<<7), ASCII 67 C
135,    //7 + (1<<7), ASCII 68 D
136,    //8 + (1<<7), ASCII 69 E
137,    //9 + (1<<7), ASCII 70 F
138,    //10 + (1<<7), ASCII 71 G
139,    //11 + (1<<7), ASCII 72 H
140,    //12 + (1<<7), ASCII 73 I
141,    //13 + (1<<7), ASCII 74 J
142,    //14 + (1<<7), ASCII 75 K
143,    //15 + (1<<7), ASCII 76 L
144,    //16 + (1<<7), ASCII 77 M
145,    //17 + (1<<7), ASCII 78 N
146,    //18 + (1<<7), ASCII 79 O
147,    //19 + (1<<7), ASCII 80 P
148,    //20 + (1<<7), ASCII 81 Q
149,    //21 + (1<<7), ASCII 82 R
150,    //22 + (1<<7), ASCII 83 S
151,    //23 + (1<<7), ASCII 84 T
152,    //24 + (1<<7), ASCII 85 U
153,    //25 + (1<<7), ASCII 86 V
154,    //26 + (1<<7), ASCII 87 W
155,    //27 + (1<<7), ASCII 88 X
156,    //28 + (1<<7), ASCII 89 Y
157,    //29 + (1<<7), ASCII 90 Z
47,    //47, ASCII 91 [
49,    //49, ASCII 92 BACKSLASH
48,    //48, ASCII 93 ]
163,    //35 + (1<<7), ASCII 94 ^
173,    //45 + (1<<7), ASCII 95 _
53,    //53, ASCII 96 `
4,    //4, ASCII 97 a
5,    //5, ASCII 98 b
6,    //6, ASCII 99 c
7,    //7, ASCII 100 d
8,    //8, ASCII 101 e
9,    //9, ASCII 102 f
10,    //10, ASCII 103 g
11,    //11, ASCII 104 h
12,    //12, ASCII 105 i
13,    //13, ASCII 106 j
14,    //14, ASCII 107 k
15,    //15, ASCII 108 l
16,    //16, ASCII 109 m
17,    //17, ASCII 110 n
18,    //18, ASCII 111 o
19,    //19, ASCII 112 p
20,    //20, ASCII 113 q
21,    //21, ASCII 114 r
22,    //22, ASCII 115 s
23,    //23, ASCII 116 t
24,    //24, ASCII 117 u
25,    //25, ASCII 118 v
26,    //26, ASCII 119 w
27,    //27, ASCII 120 x
28,    //28, ASCII 121 y
29,    //29, ASCII 122 z
175,    //47 + (1<<7), ASCII 123 {
177,    //49 + (1<<7), ASCII 124 |
176,    //48 + (1<<7), ASCII 125 }
181,    //53 + (1<<7), ASCII 126 ~
};

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

