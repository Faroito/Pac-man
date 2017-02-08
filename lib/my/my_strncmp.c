/*
** my_strncmp.c for my_strncmp in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Oct 11 15:32:41 2016 Timothée Couble
** Last update Wed Nov 23 13:41:49 2016 Timothée Couble
*/

#include "../../include/my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	d;
  int	c;

  i = 0;
  d = 0;
  c = 0;
  n = n - 1;
  while (i < n && c == 0)
    {
      if (s1[i] != s2[i])
	{
	  c = 1;
	  d = s1[i] - s2[i];
	  return (d);
	}
      i = i + 1;
    }
  if (c == 0)
    {
      return (0);
    }
}
