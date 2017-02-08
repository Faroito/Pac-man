/*
** my_swap.c for my_swap in /home/timothee.couble/CPool_Day04
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Oct  6 11:11:34 2016 Timothée Couble
** Last update Wed Nov 23 13:42:36 2016 Timothée Couble
*/

#include "../../include/my.h"

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
