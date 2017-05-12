#
#  Makefile for timetable.c
#

all: timestable

timestable: timestable.c
	gcc -Wall -o timestable timestable.c
	
clean:
	rm timestable
