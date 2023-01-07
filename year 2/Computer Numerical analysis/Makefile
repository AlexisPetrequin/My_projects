##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	main.cpp		\
			groundhog.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	groundhog

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re