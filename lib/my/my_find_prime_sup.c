/*
** my_find_prime_sup.c for my_find_prime_sup in /home/timothee.couble/CPool_Day05
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Mon Oct 10 22:33:22 2016 Timothée Couble
** Last update Wed Nov 23 13:33:39 2016 Timothée Couble
*/

#include "../../include/my.h"

int     my_find_prime_sup(int nb)
{
  int   count;

  count = 2;
  while (count < nb)
    {
      if (count == nb)
	{
	  return (nb);
	}
      if (nb % count == 0)
	{
	  nb = nb + 1;
	}
      count = count + 1;
    }
}
