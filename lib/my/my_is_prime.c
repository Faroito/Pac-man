/*
** my_is_prime.c for my_is_prime in /home/timothee.couble/CPool_Day05
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Mon Oct 10 22:33:22 2016 Timothée Couble
** Last update Wed Nov 23 13:37:41 2016 Timothée Couble
*/

#include "../../include/my.h"

int     my_is_prime(int nb)
{
  int   count;

  count = 1;
  while (count < nb)
    {
      count = count + 1;
      if (count == nb)
	{
	  return (1);
	}
      else if (nb % count == 0)
	{
	  return (0);
	}
    }
}
