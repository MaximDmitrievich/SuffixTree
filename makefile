FLAGS=-g -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -O2
CC=g++

all: node suffixtree main clear

main: main.cpp
	$(CC) $(FLAGS) -c main.cpp
	$(CC) $(FLAGS) -o SuffixTree node.o suffixtree.o main.o

node: node.cpp
	$(CC) $(FLAGS) -c node.cpp

suffixtree: suffixtree.cpp
	$(CC) $(FLAGS) -c suffixtree.cpp

clear:
	rm -f *.o
	rm -f *.stackdump
