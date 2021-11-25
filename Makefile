OBJS = spiral.cpp

LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

CC = g++

NAME = spiral

all:
	$(CC) -o $(NAME) $(OBJS) $(LINKER_FLAGS)
	./spiral
	rm ./spiral
