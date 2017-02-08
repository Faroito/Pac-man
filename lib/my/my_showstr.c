/*
** my_showstr.c for my_showstr in /home/timothee.couble/CPool_Day07/lib
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct 12 10:21:11 2016 Timothée Couble
** Last update Wed Nov 23 13:38:35 2016 Timothée Couble
*/

#include "../../include/my.h"

int	show_str(char str)
{
  my_putchar(92);
  if (str == 7)
    my_putstr("07");
  else if (str == 8)
    my_putstr("08");
  else if (str == 9)
    my_putstr("09");
  else if (str == 10)
    my_putstr("0a");
  else if (str == 11)
    my_putstr("0b");
  else if (str == 12)
    my_putstr("0c");
  else if (str == 13)
    my_putstr("0d");
  return (str);
}

int	my_showstr(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    {
      if (str[n] <= 6 || 14 <= str[n])
	{
	  my_putchar(str[n]);
	}
      else
	{
	  show_str(str[n]);
	}
      n = n + 1;
    }
  return (0);
}
