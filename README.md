# USBKeychain

## Credits
This key has been inspired by this project : https://codeandlife.com/2012/03/03/diy-usb-password-generator/
It makes an extensive use of the V-USB library distributed here (under GNU GPL2 or GPL3) : http://www.obdev.at/vusb/ 

## Purpose
The USB key has been designed to generate, store, type and delete a password using an unexpensive Atmel Attiny85 chip. It mimics the behavior of an USB keyboard, which makes it (almost) universal and driverless.

## Operating instructions
### Using the key's button
A short press on the button allow the key to type the stored password.
A long press (5 seconds) on the button resets the stored password.
### Using commandline
For more complex operations, the python script commandline.py must be used while the key is plugged.

## Building the key
Refer to the following drawing to build the key. Then flash it with the given driver (e. g. using ISP).
![Diagram](https://github.com/clsergent/USBKeychain/blob/master/Images/Diagram.jpg)


Check the Wiki pages for more information
