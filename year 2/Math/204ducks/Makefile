##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	204.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	204ducks

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re