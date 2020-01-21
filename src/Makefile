
OBJS=$(patsubst %.c, %.o, $(wildcard *.c))

CXXOBJS=$(patsubst %.cpp, %.o, $(wildcard *.cpp))


CFLAGS=-std=c99

.PHONY: all clean

# all: 
	# arduino-cli compile

clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.hex
