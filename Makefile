##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## launch lib Makefile and compile evalexpr
##

NAME	=	project_Zt

SRC	=	$(wildcard *.cpp)

CXX=g++

CFLAGS += -I include/ -W -Wall -Wextra -L lib -lmy -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJ	=	$(SRC:.cpp=.o)

RM = rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib/my
	$(CXX) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	(cd ./lib/my; make clean)
	$(RM) $(OBJ)

fclean:	clean
	(cd ./lib/my/; make fclean)
	$(RM) $(NAME)

re:	fclean all
