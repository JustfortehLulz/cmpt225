CC = g++
FILES = main.cpp Deque.cpp
OUT_EXE = main

build: main.cpp Deque.cpp
		g++ -o main main.cpp Deque.cpp

clean:
		rm -f *.o 

rebuild: clean build