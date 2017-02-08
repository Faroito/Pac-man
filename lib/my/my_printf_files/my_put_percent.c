/*
** my_put_percent.c for my_put_percent in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Nov 17 15:30:36 2016 Timothée Couble
** Last update Wed Nov 23 14:15:58 2016 Timothée Couble
*/

#include "../../../include/my_printf.h"
#include <stdarg.h>

void	my_put_percent(va_list args, int *justify, int length)
{
  if (justify[0] == 1)
    {
      my_putchar('%');
      my_putchar(' ');
    }
  else
    {
      if (justify[2] > 0 && justify[0] == 0)
	my_putchar(' ');
      my_putchar('%');
    }
}
