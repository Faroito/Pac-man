/*
** my_putchar.c for my_putchar in /home/timothee.couble/CPool_Day07/lib
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct 12 08:42:18 2016 Timothée Couble
** Last update Wed Nov 23 14:03:27 2016 Timothée Couble
*/

#include "../../include/my_printf.h"
#include <unistd.h>
#include <stdarg.h>

void	my_put_char(va_list args, int *justify, int length)
{
  char	c;

  c = va_arg(args, int);
  if (justify[0] == 1)
    {
      my_putchar(c);
      my_putchar(' ');
    }
  else
    {
      if (justify[2] > 0 && justify[0] == 0)
	my_putchar(' ');
      my_putchar(c);
    }
}
