##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	lemin.c					\
		codefile/my_strcat.c	\
		codefile/my_strlen.c	\
		strtostrgrid.c			\
		printgestion.c			\
		codefile/my_putstr.c	\
		codefile/my_putchar.c	\
		codefile/my_strcmp.c	\
		codefile/my_number.c	\
		initstruct.c			\
		initstruct2.c			\


OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
