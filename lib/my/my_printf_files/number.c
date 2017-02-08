/*
** number.c for number in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Sat Nov 19 16:52:53 2016 Timothée Couble
** Last update Wed Nov 23 14:16:41 2016 Timothée Couble
*/

#include <stdlib.h>
#include "../../../include/my_printf.h"

int	number(char *str, int i)
{
  int	c;
  int	save_i;
  int	result;
  int	power;

  save_i = i;
  power = 1;
  result = 0;
  while (str[i] <= '9' && str[i] >= '0')
    {
      power = power * 10;
      i = i - 1;
    }
  i = i + 1;
  power /= 10;
  while (i <= save_i)
    {
      result = result + ((str[i] - '0') * power);
      power = power / 10;
      i = i + 1;
    }
  return (result);
}
