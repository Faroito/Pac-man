/*
** my_square_root.c for my_square_root in /home/timothee.couble/CPool_Day05
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Mon Oct 10 22:25:01 2016 Timothée Couble
** Last update Wed Nov 23 13:38:59 2016 Timothée Couble
*/

#include "../../include/my.h"

int	my_square_root(int nb)
{
  int	count;

  count = 0;
  while (count * count < nb)
    {
      count = count + 1;
      if (count * count == nb)
	{
	  return (count);
	}
      else if (count * count > nb)
	{
	  return (0);
	}
    }
}
