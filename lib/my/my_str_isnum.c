/*
* * my_str_isnum.c for my_str_isnum in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct 12 08:04:34 2016 Timothée Couble
** Last update Wed Nov 23 13:40:35 2016 Timothée Couble
*/

#include "../../include/my.h"

int	my_str_isnum(char *str)
{
  int   count;
  int   n;

  n = 0;
  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] > 47 && str[count] < 58)
	{
	  n = n + 1;
	}
      count = count + 1;
    }
  if (count == n)
    {
      return (1);
    }
  else
    {
      return (0);
    }
}
