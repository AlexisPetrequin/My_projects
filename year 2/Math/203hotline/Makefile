##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC		= 	main.cpp	\
			hotline.cpp	\

OBJ		= $(SRC:.cpp=.o)

NAME		= 203hotline

all:		$(NAME)

$(NAME):	$(OBJ)
		@g++ -o $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: clean fclean