all: main

main: main.o Individual.o BinaryNode.o
	g++ main.o Individual.o BinaryNode.o

main.o: main.cpp
	g++ -c main.cpp

Individual.o: Individual.h Individual.cpp
	g++ Individual.h Individual.cpp -c Individual.o

BinaryNode.o: BinaryNode.h BinaryNode.cpp
	g++ BinaryNode.h BinaryNode.cpp -c BinaryNode.o