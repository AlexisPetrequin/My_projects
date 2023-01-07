##
## EPITECH PROJECT, 2019
## Makefile infinadd
## File description:
## No file there, just an epitech header example
##

SRC	=		my_putchar.c					\
			my_putstr.c						\
			my_compute_power_rec.c			\
			my_compute_square_root.c		\
			my_getnbr.c						\
			my_isalpha.c					\
			my_isneg.c						\
			my_is_prime.c					\
			my_lowercase.c					\
			my_print_params.c				\
			my_print_prime_sup.c			\
			my_put_nbr.c					\
			my_revstr.c						\
			my_showmem.c					\
			my_showstr.c					\
			my_show_word_array.c			\
			my_sort_int_array.c				\
			my_strcapitalize.c				\
			my_strcat.c						\
			my_strcmp.c						\
			my_strcpy.c						\
			my_strdup.c						\
			my_str_islower.c				\
			my_str_isnum.c					\
			my_str_isprintable.c			\
			my_str_isupper.c				\
			my_strlen.c						\
			my_strncat.c					\
			my_strncmp.c					\
			my_strncpy.c					\
			my_strstr.c						\
			my_strupcase.c					\
			my_swap.c						\
			my_calc.c						\
			my_cpy.c						\
			my_str_modif.c					\
			my_modstr.c						\
			my_numstr.c						\
			my_number.c						\
			my_str_infnbr.c					\
			my_cnbr_int.c					\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc -o $(NAME) $(OBJ)

clean:
	@rm $(OBJ)

fclean: clean
	@rm -f	$(NAME) $(OBJ)

.PHONY: clean fclean
