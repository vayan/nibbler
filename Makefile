##
## Makefile for  in /home/vailla_y/Projet/myscript
## 
## Made by yann vaillant
## Login   <vailla_y@epitech.net>
## 
## Started on  Thu Feb 23 22:09:58 2012 yann vaillant
## Last update Thu Mar 15 13:12:51 2012 yann vaillant
##


##GLOBAL##
INCLUDE=-Iinclude
SRC_LIB_COMMON= src/food.cpp \
				src/map.cpp \
				src/snake.cpp
OBJ_LIB_COMMON=$(SRC_LIB_COMMON:.cpp=.o)

##LIB OPENGL##
NAME_LIB_OPGL=lib_nibbler_opengl.so
SRC_LIB_OPGL=opengl/draw.cpp
OBJ_LIB_OPGL=$(SRC_LIB_OPGL:.cpp=.o)

LDFLAGS += -ldl
CXXFLAGS += -fPIC -Iinclude
CXX = g++

$(NAME_LIB_OPGL): $(OBJ_LIB_OPGL) $(OBJ_LIB_COMMON)
	$(CXX) -shared -o $(NAME_LIB_OPGL) $(OBJ_LIB_OPGL) $(OBJ_LIB_COMMON)

##LIB NCURSES##
NAME_LIB_NCURSES=lib_nibbler_ncurses.so
SRC_LIB_NCURSES=ncurses/draw.cpp
OBJ_LIB_NCURSES=$(SRC_LIB_NCURSES:.cpp=.o)

LDFLAGS += -ldl -lncurses
CXXFLAGS += -fPIC -Iinclude
CXX = g++

$(NAME_LIB_NCURSES): $(OBJ_LIB_NCURSES) $(OBJ_LIB_COMMON)
	$(CXX) -shared -o $(NAME_LIB_NCURSES) $(OBJ_LIB_NCURSES) $(OBJ_LIB_COMMON)

##GENERAL##
CC = g++
NAME= nibbler
SRC= $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJ= $(SRC:.c=.o)
CFLAGS= -W -Wall -Wextra -g -lSDL -lSDL_image -lGL -lGLU -ldl -fPIC

all: $(NAME_LIB_OPGL) $(NAME_LIB_NCURSES) $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(INCLUDE) 

clean:
	#rm -f *~
	#rm -f *#
	#rm -f src/*~
	#rm -f src/*# 
	#rm -f $(OBJ_LIB_OPGL)
	#rm -f $(OBJ_LIB_COMMON)
	#rm -f OBJ

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_LIB_OPGL)
	rm -rf $(NAME_LIB_NCURSES)

re: fclean all