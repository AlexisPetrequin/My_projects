##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	205.cpp	\
			iq.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	205IQ

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re