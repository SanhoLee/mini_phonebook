#ref:  https://www.tuwlab.com/ece/27193
CC=gcc
CFLAGS=-g -Wall
OBJS=main.o global.o menu.o string_.o
TARGET=runTHIS

all : ${TARGET}

clean:
	rm -f *.o
	rm -r ${TARGET}


${TARGET}:${OBJS}
	${CC} -o $@ ${OBJS}

main.o : global.h menu.h string_.h main.c
global.o : global.h global.c
menu.o : menu.h menu.c
string_.o : string_.h string_.c