#! /bin/bash

cc=gcc
CF=-c -lpthread
DF=-DDEBUG

App: main.o mainMenu.o init.o openDevice.o writeDevice.o readDevice.o releaseDevice.o exitApps.o 
	${cc} -o App main.o mainMenu.o init.o openDevice.o writeDevice.o readDevice.o releaseDevice.o exitApps.o

main.o: main.c headers.h declaration.h
	${cc} ${CF} ${DF} main.c
mainMenu.o: mainMenu.c headers.h declaration.h
	${cc} ${CF} ${DF} mainMenu.c
init.o: init.c headers.h declaration.h
	${cc} ${CF} ${DF} init.c
openDevice.o: openDevice.c headers.h declaration.h
	${cc} ${CF} ${DF} openDevice.c
writeDevice.o: writeDevice.c headers.h declaration.h
	${cc} ${CF} ${DF} writeDevice.c
readDevice.o: readDevice.c headers.h declaration.h
	${cc} ${CF} ${DF} readDevice.c
releaseDevice.o: releaseDevice.c headers.h declaration.h
	${cc} ${CF} ${DF} releaseDevice.c
exitApps.o: exitApps.c headers.h declaration.h
	${cc} ${CF} ${DF} exitApps.c


clean:
	rm *.o App
