/*
** my.h for my.h in /home/timothee.couble/Default/include
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Nov  8 14:52:59 2016 Timothée Couble
** Last update Thu Dec 15 14:52:55 2016 Timothée Couble
*/

#ifndef MY_H_
# define MY_H_

#include "pac_man.h"

void    my_putchar(char c);
int     my_isneg(int nb);
void    my_put_nbr(int nb);
int     my_swap(int *a, int *b);
void    my_putstr(char *str);
int     my_strlen(char *str);
int     my_getnbr(char *str);
int     my_power_rec(int nb, int power);
int     my_square_root(int nb);
int     my_is_prime(int nombre);
int     my_find_prime_sup(int nb);
char    *my_revstr(char *str);
char    *my_strstr(char *str, char *to_find);
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int n);
int     my_showmem(char *str, int size);
char    *my_strcat(char *dest, char *src);
char    *my_strncat(char *dest, char *src, int nb);
int	my_printf(char *s, ...);

#endif /* !MY_H_ */
