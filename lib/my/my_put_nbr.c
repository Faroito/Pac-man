/*
** my_put_nbr.c for my_put_nbr in /home/timothee.couble/CPool_Day03
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Oct  6 21:05:47 2016 Timothée Couble
** Last update Wed Nov 23 14:05:18 2016 Timothée Couble
*/

#include "../../include/my.h"

void    my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb *= -1;
      my_putchar('-');
    }
  if (nb > 9)
    my_put_nbr(nb / 10);
  nb %= 10;
  my_putchar(nb + 48);
}
