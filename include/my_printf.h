/*
** my_printf.h for my_printf in /home/timothee.couble/Default
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Nov 23 13:50:46 2016 Timothée Couble
** Last update Wed Nov 23 13:53:05 2016 Timothée Couble
*/

#include <stdarg.h>
#include "my.h"

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

void    my_put_char(va_list args, int *justify, int length);
void    my_put_fnbr(va_list args, int *justify, int length);
void    my_put_str(va_list args, int *justify, int length);
void    my_put_octal(va_list args, int *justify, int length);
void    my_put_binary(va_list args, int *justify, int length);
void    my_put_hexa(va_list args, int *justify, int length);
void    my_put_caps_hexa(va_list args, int *justify, int length);
void    my_put_unsigned_nbr(va_list args, int *justify, int length);
void    my_showstr(va_list args, int *justify, int length);
void    my_put_percent(va_list args, int *justify, int length);
void    (*tab[12])(void *);
int     number(char *s, int i);
int     calc_justify(long long nb, int *justify);
void    print_justify(int nb, int type);
int     find_flags(char *s, int i);
int     *find_width(char *s, int i, int *justify);
int     find_specifer(char *s, int i);
int     find_length(char *s, int i);
void    add_specifer(void  (*specifer[12])(va_list, int *, int));
int     *add_justify(int *justify);
short   to_short(long long nb);
char    to_char(long long nb);
int     to_int(long long nb);
long    to_long(long long nb);
long long       choose_length(long long nb, int length);
unsigned short  unsigned_short(unsigned long long nb);
unsigned short  unsigned_short(unsigned long long nb);
unsigned char   unsigned_char(unsigned long long nb);
unsigned int    unsigned_int(unsigned long long nb);
unsigned long   unsigned_long(unsigned long long nb);
unsigned long long      unsigned_length(unsigned long long nb, int length);

#endif /* !MY_PRINTF_H_ */
