##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makesfiles
##

SRC	=	src/displays/display_window.c	\
		src/displays/display_wizard.c	\
		src/displays/display_extras.c	\
		src/displays/display_menus.c	\
		src/displays/display_life.c		\
		src/displays/display_lose.c		\
		src/displays/display_goos.c		\
		src/main/error_handler.c		\
		src/events/check_event.c		\
		src/misc/game_sound.c			\
		src/misc/mouse_pos.c			\
		src/misc/game_goos.c			\
		src/misc/game_sett.c			\
		src/play/play_game.c			\
		src/main/main.c

NAME 	=	my_defender

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -W -Iincludes

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

LIB		=	-L lib -lib -lm

all:	$(NAME)

make_lib:
	make -C lib all

$(NAME):	make_lib	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CSFML) $(LIB)

clean:
	make -C lib clean
	rm -f $(OBJ)

fclean:	clean
	make -C lib fclean
	rm -f $(NAME)

re: 	fclean all
