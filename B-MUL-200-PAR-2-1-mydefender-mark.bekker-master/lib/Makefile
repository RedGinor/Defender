##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makesfiles
##

SRC	=	ib/str/ib_strlen.c		\
		ib/str/ib_strcmp.c		\
		ib/str/ib_strcpy.c		\
		ib/str/ib_revstr.c		\
		ib/num/ib_atoi.c		\
		ib/num/ib_itoa.c		\
		ib/arr/ib_rev_str_arr.c	\
		ib/arr/ib_rev_int_arr.c	\
		ib/arr/ib_str_size.c	\
		ib/arr/ib_sort_int.c	\
		ib/arr/ib_sort_str.c	\
		ib/print/ib_putnbr.c	\
		ib/print/ib_putstr.c	\
		ib/csfml/sprite/create_sprite.c		\
		ib/csfml/sprite/destroy_sprite.c	\
		ib/csfml/sprite/move_sprite.c		\
		ib/csfml/sprite/display_sprite.c	\
		ib/csfml/sprite/play_sound.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libib.a

all: 	lib

lib:	$(OBJ)
	ar rc $(NAME) -o $(OBJ)
	mkdir -p ../includes
	scp ib/ib.h ../includes
	scp ib/sprite.h ../includes

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../includes/ib.h
	rm -f ../includes/sprite.h
	rm -f $(NAME)

re: 	fclean all
