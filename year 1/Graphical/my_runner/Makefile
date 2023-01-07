##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	teststruct.c	\
		drawsprites.c	\
		fillvectors.c	\
		window.c		\
		
OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-window -l csfml-system

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
