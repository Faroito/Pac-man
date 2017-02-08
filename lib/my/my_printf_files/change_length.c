/*
** change_length.c for change_length in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Sun Nov 20 20:10:18 2016 Timothée Couble
** Last update Wed Nov 23 14:02:31 2016 Timothée Couble
*/

#include "../../../include/my_printf.h"

short	to_short(long long nb)
{
  short	result;

  result = nb;
  return (result);
}

char	to_char(long long nb)
{
  char	result;

  result = nb;
  return (result);
}

int	to_int(long long nb)
{
  int	result;

  result = nb;
  return (result);
}

long	to_long(long long nb)
{
  long	result;

  result = nb;
  return (result);
}

long long	choose_length(long long nb, int length)
{
  if (length == 0)
    nb = to_int(nb);
  else if (length == 1)
    nb = to_short(nb);
  else if (length == 2)
    nb = to_char(nb);
  else if (length == 3)
    nb = to_long(nb);
  return (nb);
}
