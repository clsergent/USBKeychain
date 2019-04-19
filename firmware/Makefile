MCU=attiny85
AVRDUDEMCU=t85
F_CPU= 16500000

# binaries
CC=avr-gcc
MICRO=/usr/local/bin/micronucleus
OBJ2HEX=/usr/local/CrossPack-AVR/bin/avr-objcopy
AVRDUDE=/usr/local/CrossPack-AVR/bin/avrdude

# sources
SUBSRC= ./usbdrv
C_SRC:= $(wildcard $(SUBSRC)/*.c) $(wildcard *.c)
S_SRC:= $(wildcard $(SUBSRC)/*.S)
OBJ:= $(C_SRC:.c=.o) $(S_SRC:.S=.o)

# flags
CFLAGS=-Wall -Os -I$(SUBSRC) -I. -DDEBUG_LEVEL=0 -mcall-prologues -mmcu=$(MCU) -DF_CPU=$(F_CPU)
AFLAGS=-p $(AVRDUDEMCU) -c usbasp -b 10000

#target
file?=main
TARGET=$(file)

# symbolic targets:
help:
	@echo "This Makefile has no default rule. Use one of the following:"
	@echo "make build ....... to build main.hex"
	@echo "make flash ..... to flash the firmware (use this on metaboard)"
	@echo "make clean ..... to delete objects and hex file"
	@echo "make fuse  ..... to set the fuses for USB support"


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -x assembler-with-cpp -c $< -o $@

main: $(OBJ) $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET).elf $(OBJ)
	$(OBJ2HEX) -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex
	avr-size $(TARGET).hex

clean:
	rm -f $(TARGET).o $(TARGET).elf $(SUBSRC)/*.o

build: main clean

flashM:
	$(MICRO) $(TARGET).hex

flash:
	$(AVRDUDE) $(AFLAGS) -U flash:w:$(TARGET).hex

fuse:
	$(AVRDUDE) $(AFLAGS) -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m

all: build flash
