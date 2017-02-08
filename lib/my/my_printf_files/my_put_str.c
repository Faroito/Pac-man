/*
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Fri Oct  7 15:00:11 2016 Timothée Couble
** Last update Wed Nov 23 14:16:19 2016 Timothée Couble
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void	my_put_str(va_list args, int *justify, int length)
{
  char	*str;
  int	i;

  str = va_arg(args, char *);
  if (justify[0] == 1)
    {
      my_putstr(str);
      print_justify(calc_justify(my_strlen(str), justify), 0);
    }
  else
    {
      if (justify[2] > 0 && justify[0] == 0)
	print_justify(calc_justify(my_strlen(str), justify), 0);
      my_putstr(str);
    }
}
