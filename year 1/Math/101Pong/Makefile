##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	calc.c		\
		display.c	\
		
OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C ./lib/my/
	@gcc -o $(NAME) $(OBJ) -L./lib/my/ -lmy -lm

clean:
	@rm -f $(OBJ)
	@make -C ./lib/my/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./lib/my/ fclean

re: fclean all

.PHONY: clean fclean
