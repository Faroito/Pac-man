/*
** my_strupcase.c for my_strupcase in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Oct 11 18:20:42 2016 Timothée Couble
** Last update Wed Nov 23 13:42:24 2016 Timothée Couble
*/

#include "../../include/my.h"

char	*my_strupcase(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] > 96 && str[count] < 123)
	{
	  str[count] = str[count] - 32;
	}
      count = count + 1;
    }
  return (str);
}
