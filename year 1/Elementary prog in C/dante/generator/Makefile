##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	generator.c		\
		mazeperfect.c	\
		maze.c			\
		init.c			\
		my_putstr.c		\
		my_getnbr.c		\
		my_putchar.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
