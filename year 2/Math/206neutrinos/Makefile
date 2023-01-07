##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME		= 206neutrinos

SRC		= 206.cpp \
		  neutrinos.cpp \

OBJ		= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
