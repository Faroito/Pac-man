/*
** my_isneg.c for my_isneg in /home/timothee.couble/CPool_Day03
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct  5 11:25:30 2016 Timothée Couble
** Last update Wed Nov 23 13:37:32 2016 Timothée Couble
*/

#include "../../include/my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
