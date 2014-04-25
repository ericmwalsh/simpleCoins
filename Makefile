all: main betterMain bestMain
OBJECTS = Coins.o main betterMain bestMain

bestMain: Coins.o bestMain.cc
	g++ Coins.o bestMain.cc -o bestMain

betterMain: Coins.o betterMain.cc
	g++ Coins.o betterMain.cc -o betterMain

main: Coins.o main.cc
	g++ Coins.o main.cc -o main

Coins.o: Coins.cc Coins.h
	g++ -c Coins.cc

clean:
	rm $(OBJECTS)