##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = g++

RM = rm -f

CXXFLAGS 	+= 	-Iinclude/ -I../games/include/ -I../include/
CXXFLAGS 	+= 	-W -Wextra -Wall -Werror -std=c++14

NAME_OPENGL 	= 	reader

SRCS_OPENGL 	=	src/LibOpenGL.cpp \
			src/OpenGLCube.cpp \
			src/OpenGLSquare.cpp \
			src/OpenGLImage.cpp \
			src/Map.cpp \
			src/main.cpp

OBJS_OPENGL = $(SRCS_OPENGL:.cpp=.o)

all: $(NAME_OPENGL)

$(NAME_OPENGL): $(OBJS_OPENGL)
	$(CC) $(OBJS_OPENGL) -o $(NAME_OPENGL) -lSDL -lSDL_image -lGLU -lGL

clean:
	$(RM) $(OBJS_OPENGL)

fclean: clean
	$(RM) $(NAME_OPENGL)

re: fclean all

.PHONY: all clean fclean re
