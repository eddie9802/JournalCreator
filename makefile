OBJS = JournalCreator.cpp

CC = g++

OBJ_NAME = ./out/program

COMPILERFLAGS = -std=c++17 -g


all: $(OBJS)
	$(CC) $(OBJS) $(COMPILERFLAGS) -o $(OBJ_NAME)