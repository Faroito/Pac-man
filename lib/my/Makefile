##
## Makefile for Makefile in /home/timothee.couble/CPool_Day10
## 
## Made by Timothée Couble
## Login   <timothee.couble@epitech.net>
## 
## Started on  Fri Oct 14 10:33:40 2016 Timothée Couble
## Last update Wed Dec  7 09:21:07 2016 Timothée Couble
##

SRC	=	my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_power_rec.c	\
		my_printf.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_printf_files/add_parameters.c	\
		my_printf_files/change_length.c	\
		my_printf_files/find_parameters.c	\
		my_printf_files/justify.c	\
		my_printf_files/my_put_char.c	\
		my_printf_files/my_put_fnbr.c	\
		my_printf_files/my_put_binary.c	\
		my_printf_files/my_put_caps_hexa.c	\
		my_printf_files/my_put_hexa.c	\
		my_printf_files/my_put_octal.c	\
		my_printf_files/my_put_percent.c	\
		my_printf_files/my_put_pointer.c	\
		my_printf_files/my_put_str.c	\
		my_printf_files/my_put_unsigned_nbr.c	\
		my_printf_files/my_showstr.c	\
		my_printf_files/number.c	\
		my_printf_files/unsigned_length.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

AR	=	ar rc

RM	=	rm -f

all:	libr clean

libr:	$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all libr clean
