/*
** my_power_rec.c for my_power_rec in /home/timothee.couble/CPool_Day05
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Mon Oct 10 21:56:16 2016 Timothée Couble
** Last update Wed Nov 23 13:37:47 2016 Timothée Couble
*/

#include "../../include/my.h"

int     my_power_rec(int nb, int p)
{
  if (p == 0)
    {
      nb = 1;
    }
  else if (p < 0)
    {
      nb = 0;
    }
  else if (p > 1)
    {
      nb = nb * my_power_rec(nb, p - 1);
    }
  return (nb);
}
