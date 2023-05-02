##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile for tetris
##

SRC	=	src/main.c	\
		src/tetris.c	\
		src/help.c	\
		src/param_handler.c	\
		src/debug.c	\
		src/display_game.c	\
		src/get_files.c	\
		src/get_shape_attributes.c	\
		src/shape_drop.c	\
		src/check_file.c	\
		src/get_param.c	\
		src/init_map.c	\
		src/detect_touching.c	\
		src/display_shape.c	\
		src/display_tetri.c	\
		src/detect_loss.c	\
		src/conditions.c	\
		src/rotation.c	\
		src/down.c	\
		src/display_info.c	\
		src/init.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-Llib/my/ -lmy

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-Iinclude/

CCRITERION	= 	--coverage -lcriterion

NAME	=	tetris

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFML) -lcurses

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C lib/my
	$(RM) $(NAME)

re: fclean all

.PHONY : all re clean tests_run fclean
