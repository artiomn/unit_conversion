#
# Created by Bleeding(cl)2006
#

CC = gcc
CFLAGS = -O3
STRIP = strip
PREFIX = /usr
P_NAME = uc
INSTALL = install -s -g bin -o root
DIRN = $(notdir ${PWD})

C_OBJ = uc.o digits.o functions.o meters.o inches.o inch_to_metric.o metric_to_inch.o temp.o text.o

.PHONY: all clean distr help install rebuild uninstall
.SILENT: help

all: $(P_NAME)

$(P_NAME) : ${C_OBJ}
	${CC} ${CFLAGS} ${C_OBJ} -o ${P_NAME}


$(C_OBJ) : functions.h config.h

uc.o : uc.c convarray.h

digits.o : digits.h 

functions.o : config.h convarray.h functions.h

meters.o : meters.h

inches.o : inches.h

inch_to_metric.o : inch_to_metric.h

metric_to_inch.o : metric_to_inch.h

temp.o : temp.h

text.o : text.h

clean:
	rm -rf ${C_OBJ} ${P_NAME}

rebuild: clean uc

install: $(PREFIX)/bin/$(P_NAME)

$(PREFIX)/bin/$(P_NAME) : $(P_NAME)
	${INSTALL} ${P_NAME} ${PREFIX}/bin/${P_NAME}
#	${STRIP} ${PREFIX}/bin/${P_NAME}

uninstall:
	rm -f ${PREFIX}/bin/${P_NAME}

help:
	echo 'make target '
	echo ' Targets: '
	echo ' all|uc - Build binary.'
	echo ' clean - Clean build directory.'
	echo ' distr - Create bz2 archive.'
	echo ' rebuild = make clean build.'
	echo ' install - Install binary.'
	echo ' uninstall - Remove binary.'
	echo ' help - Show this help.'
	echo 'Build and install binary: '
	echo ' make && make install'

distr:
	rm -f ${P_NAME}.tbz
	mkdir ${P_NAME}_src
	cp -dpr *.c *.h Makefile translit README_rus ${P_NAME}_src
	tar --group=users --owner=user -cf - ${P_NAME}_src | bzip2 -c --best -> ${P_NAME}.tbz
	rm -rf ${P_NAME}_src
