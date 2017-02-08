/*
** my_strcat.c for my_strcat in /home/timothee.couble/CPool_Day07
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Oct 11 15:21:24 2016 Timothée Couble
** Last update Wed Nov 23 13:39:17 2016 Timothée Couble
*/

#include "../../include/my.h"

char	*my_strcat(char *dest, char *src)
{
  int	count_dest;
  int	count_src;
  char	temp;

  count_dest = 0;
  count_src = 0;
  while (dest[count_dest] != '\0')
    {
      count_dest = count_dest + 1;
    }
  while (src[count_src] != '\0')
    {
      dest[count_dest] = src[count_src];
      count_dest = count_dest + 1;
      count_src = count_src + 1;
      if (src[count_src] == '\0')
	{
	  dest[count_dest] = '\0';
	}
    }
  return (dest);
}
