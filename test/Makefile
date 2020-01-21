PROGNAME=life-test
OBJS=$(patsubst %.c, %.o, $(wildcard *.c))

CFLAGS=-I../src -I../unity -I. -std=c99 -Wall -Werror
CXXFLAGS=-I../src -I../unity -I.
VPATH=../src

LIBS=-L../unity -lunity
SUT=life.o

all: $(PROGNAME)
	./$(PROGNAME)

$(PROGNAME): $(OBJS) $(SUT)
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f $(PROGNAME)