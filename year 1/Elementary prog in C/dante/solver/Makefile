##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	solver.c		\
		cleaner.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_putchar.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
