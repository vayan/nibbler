##
## Makefile for  in /home/vailla_y/Projet/myscript
## 
## Made by yann vaillant
## Login   <vailla_y@epitech.net>
## 
## Started on  Thu Feb 23 22:09:58 2012 yann vaillant
## Last update Mon Mar 12 19:29:59 2012 yann vaillant
##

##COMMON##
CC = g++
NAME= nibler
INCLUDE= -Iinclude
SRC= $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJ= $(SRC:.c=.o)
CFLAGS= -W -Wall -Wextra -g -lSDL -lSDL_image -lGL -lGLU -Wswitch

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(INCLUDE) 

clean:
	rm -f *~
	rm -f *#
	rm -f src/*~
	rm -f src/*# 

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)