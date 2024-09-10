CC = gcc
CFLAGS = -Wall -c $(DEBUG)
LFLAG = -Wall $(DEBUG)
DEBUG = -g
OBJS = Vu_Duyen_Assn2.o Vu_baconCode.o 

assn2exe: Vu_Duyen_Assn2.o Vu_baconCode.o
	gcc -g Vu_Duyen_Assn2.o Vu_baconCode.o -o assn2exe

Vu_Duyen_Assn2.o: Vu_Duyen_Assn2.c Vu_baconCode.c Vu_baconCode.h
	gcc -c -g Vu_Duyen_Assn2.c

Vu_baconCode.o: Vu_baconCode.c Vu_baconCode.h
	gcc -c -g Vu_baconCode.c

clean:
	rm -f *.o assn2exe