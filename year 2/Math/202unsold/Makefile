##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	202.cpp		\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	202unsold

all:	$(NAME)

$(NAME):	$(OBJ)
	@g++ -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
