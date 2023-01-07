##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	= 	my_getnbr.c			\
		my_putchar.c			\
		my_putnbr.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_strcat.c			\
		map_gestion.c			\
		connected.c			\
		fill_all.c			\
		sign.c				\
		attack.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
	$(NAME)
