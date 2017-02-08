/*
** my_strncat.c for my_strncat in /home/timothee.couble/CPool_Day07
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct 12 09:25:19 2016 Timothée Couble
** Last update Wed Nov 23 13:41:37 2016 Timothée Couble
*/

#include "../../include/my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int   count_dest;
  int   count_src;
  char  temp;

  count_dest = 0;
  count_src = 0;
  while (dest[count_dest] != '\0')
    {
      count_dest = count_dest + 1;
    }
  while (src[count_src] != src[nb])
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
