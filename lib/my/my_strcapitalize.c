/*
** my_strcapitalize.c for my_strcapitalize in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Oct 11 18:20:42 2016 Timothée Couble
** Last update Wed Nov 23 13:39:07 2016 Timothée Couble
*/

#include "../../include/my.h"

char	*my_strlowcase_2(char *str)
{
  int   count;

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

char	*my_strcapitalize(char *str)
{
  int	count;
  int	i;

  i = 0;
  count = 0;
  my_strlowcase_2(str);
  while (str[count] != '\0')
    {
      if (str[count] > 31 && str[count] < 48)
	{
	  i = 0;
	}
      if (str[count] > 47 && str[count] < 58)
	{
	  i = 1;
	}
      if (str[count] > 96 && str[count] < 123 && i < 1)
	{
	  i = 1;
	  str[count] = str[count] - 32;
	}
      count = count + 1;
    }
  return (str);
}
