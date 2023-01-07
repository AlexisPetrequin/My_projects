##
## EPITECH PROJECT, 2019
## Makefile infinadd
## File description:
## No file there, just an epitech header example
##

SRC	=		110borwein.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	110borwein

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) -lm

clean:
	@rm $(OBJ)

fclean: clean
	@rm -f	$(NAME) $(OBJ)

.PHONY: clean fclean
