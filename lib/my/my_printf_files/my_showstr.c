/*
** my_showstr.c for my_showstr in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Nov 17 15:29:20 2016 Timothée Couble
** Last update Wed Nov 23 14:16:33 2016 Timothée Couble
*/

#include "../../include/my_printf.h"

void	show_str(char str)
{
  if (str >= 8)
    {
      show_str(str / 8);
    }
  str = str % 8;
  my_putchar(str + 48);
}

void	my_show(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    {
      if (32 <= str[n] && str[n] != 127)
	my_putchar(str[n]);
      else
	{
	  my_putchar('\\');
	  if (str[n] == 7)
	    my_putstr("00");
	  else
	    my_putchar('0');
	  show_str(str[n]);
	}
      n = n + 1;
    }
}

void	my_showstr(va_list args, int *justify, int length)
{
  char	*str;

  str = va_arg(args, char *);
  if (justify[0] == 1)
    {
      my_show(str);
      print_justify(calc_justify(my_strlen(str), justify), 0);
    }
  else
    {
      if (justify[2] > 0 && justify[0] == 0)
	print_justify(calc_justify(my_strlen(str), justify), 0);
      my_show(str);
    }
}
