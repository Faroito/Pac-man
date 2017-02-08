/*
** my_str_isupper.c for my_str_isupper in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct 12 08:12:36 2016 Timothée Couble
** Last update Wed Nov 23 13:40:54 2016 Timothée Couble
*/

#include "../../include/my.h"

int	my_str_isupper(char *str)
{
  int   count;
  int   n;

  n = 0;
  count = 0;
  while (str[count] != '\0')
    {
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
