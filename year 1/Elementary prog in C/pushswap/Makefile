##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	pushswap.c		\
		my_putstr.c		\
		my_number.c		\
		my_putchar.c	\
		error.c			\
		test.c			\
		
OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
