##
## Makefile for Makefile in /home/timothee.couble/Default
## 
## Made by Timothée Couble
## Login   <timothee.couble@epitech.net>
## 
## Started on  Tue Nov  8 14:50:00 2016 Timothée Couble
## Last update Wed Feb  8 13:41:59 2017 Timothée Couble
##

SRC		=	ai_phantoms/my_phantoms.c	\
			ai_phantoms/my_phantoms_door.c	\
			ai_phantoms/my_phantoms_path.c	\
			ai_phantoms/my_phantoms_turn.c	\
			fonctions/my_print_map.c	\
			fonctions/init.c		\
			fonctions/my_end_msg.c		\
			fonctions/fonctions.c		\
			main_program/my_pac_man.c	\
			main_program/my_player.c	\
			main_program/main.c

OBJ		=       $(SRC:.c=.o)

CFLAGS          +=      -W -Wall -Wextra -pedantic

NAME		=       my_pac_man

RM		=       rm -f

GCC		=       gcc -o

LIB		=       lib/my/libmy.a -lncurses

all:	$(NAME)

$(NAME):        $(OBJ)
	$(GCC) $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
