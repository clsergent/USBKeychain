#!/usr/bin/env python3

import sys
import usb1
import argparse

def send(data):
    """send the given data to USBKeychain."""
    context = usb1.USBContext()
    handle = context.openByVendorIDAndProductID(0x16c0, 0x27db, skip_on_error=True)
    if handle is None:
        print('No valid USBKeychain was found.')
        sys.exit(1)

    handle.controlWrite(request_type=usb1.TYPE_VENDOR|usb1.RECIPIENT_OTHER|usb1.ENDPOINT_OUT,
                   request=3, value=0, index=0, data=bytearray(data, 'utf8'), timeout=5000)
    handle.close()

def initParser(parser):
    group = parser.add_mutually_exclusive_group()
    
    group.add_argument('-e', '--echo', dest='echo', metavar='string', nargs=1, type= str,
                        help='echoes the given argument USBKeychain.')
    
    group.add_argument('-n', '--new', dest='new', metavar='length', nargs=1, type=int,
                        help='generate a new random password of the given length in USBKeychain.')
    
    group.add_argument('-r', '--read', dest='read', action='store_true',
                        help='read the password stored in USBKeychain.')
    
    group.add_argument('-w', '--write', dest='write', metavar='password', nargs=1, type= str,
                        help='write the given password in USBKeychain.')
    
    group.add_argument('-d', '--delete', dest='delete', action='store_true',
                        help='delete the password stored in USBKeychain.')
    
    group.add_argument('-l', '--len', dest='len', metavar='length', nargs=1, type= int,
                        help='set the length of the password stored in USBKeychain.')
    
    group.add_argument('-L', '--led', dest='led', nargs=1, type= str, choices=['0','1'],
                        help='set LED of USBKeychain.')
    
    group.add_argument('-H', '--Help', dest='Help', action='store_true',
                        help='get help from USBKeychain.')
    
    group.add_argument('-f', '--feed', dest='feed', nargs=1, type= int, choices=[0,1],
                        help='adds or not a linefeed at the end of the password stored in USBKeychain.')

    group.add_argument('-a', '--auto', dest='auto', nargs=1, type= int, choices=[0,1],
                        help='automatically send the password or not at boot time.')

    group.add_argument('-x', '--debug', dest='debug', nargs=1, type= int,
                   help='Debug tool - reserved use')
    

def parse(args):
    """parse commandline arguments"""
    if args.read:
        send('r')
        
    if args.write:
        for pos, value in enumerate(args.write[0]):
            send('w:{0}:{1}'.format(chr(pos), value, 'utf8'))
        args.len = [len(args.write[0])]

    if args.debug:
        send('w:{0}:{1}'.format(chr(0), chr(args.debug[0]), 'utf8'))
        args.len = [1]
        
    if args.echo:
        send('e:{0}'.format(args.echo[0]))
        
    if args.new:
        send('n')
        args.len = args.new
    
    if args.len:
        send('l:{0}'.format(chr(args.len[0])))
        
    if args.delete:
        send('d')
    
    if args.led:
        send(args.led[0])
    
    if args.Help:
        send('h')
    
    if args.feed:
        send('f:{0}'.format(chr(args.feed[0])))

    if args.auto:
        send('a:{0}'.format(chr(args.auto[0])))

def run():
    """run the script"""
    parser = argparse.ArgumentParser(description='Control over USBKeychain.')
    initParser(parser)
    parse(parser.parse_args())

if __name__ == '__main__':
    run()
    

