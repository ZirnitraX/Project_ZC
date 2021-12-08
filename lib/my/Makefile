##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.cpp)

OBJ	=	$(SRC:.cpp=.o)

NAME	=	libmy.a

RM	=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp libmy.a ../libmy.a
clean:
	rm -rf *.o

fclean:	clean
	$(RM) $(OBJ)
	$(RM) ../libmy.a
	$(RM) libmy.a

re:	fclean	all
