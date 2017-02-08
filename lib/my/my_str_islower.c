/*
** my_str_islower.c for my_str_islower in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct 12 08:09:25 2016 Timothée Couble
** Last update Wed Nov 23 13:40:26 2016 Timothée Couble
*/

#include "../../include/my.h"

int     my_str_islower(char *str)
{
  int   count;
  int   n;

  n = 0;
  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] > 96 && str[count] < 123)
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
