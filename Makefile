CC=msp430-gcc
CFLAGS= -Os -O
FILES=$(shell ls *.c)

all: hello
clean:
	rm *.elf		
