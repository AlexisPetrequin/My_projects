##
## EPITECH PROJECT, 2021
## B-MAT-400-STG-4-1-209poll-alexis.petrequin
## File description:
## Makefile
##

NAME		= 209poll

SRC		= 209.cpp \

OBJ		= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
