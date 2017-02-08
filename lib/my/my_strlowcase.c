/*
** my_strlowcase.c for my_strlowcase in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Oct 11 18:20:42 2016 Timothée Couble
** Last update Wed Nov 23 13:41:21 2016 Timothée Couble
*/

#include "../../include/my.h"

char	*my_strlowcase(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] > 64 && str[count] < 91)
	{
	  str[count] = str[count] + 32;
	}
      count = count + 1;
    }
  return (str);
}
