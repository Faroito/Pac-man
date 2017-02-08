/*
** my_str_isalpha.c for my_str_isalpha in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct 12 07:34:42 2016 Timothée Couble
** Last update Wed Nov 23 13:40:14 2016 Timothée Couble
*/

#include "../../include/my.h"

int     my_str_isalpha(char *str)
{
  int   count;
  int	n;

  n = 0;
  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] > 96 && str[count] < 123)
	{
	  n = n + 1;
	}
      if (str[count] > 63 && str[count] < 91)
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
