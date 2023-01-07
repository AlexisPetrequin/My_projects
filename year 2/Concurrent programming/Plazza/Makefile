##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	main.cpp			\
			engine.cpp			\
			engine_annexe.cpp	\
			parse.cpp			\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	plazza

all:	$(NAME)

$(NAME):$(OBJ)
	g++ $(OBJ) -o $(NAME) -g -lm -lpthread

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re