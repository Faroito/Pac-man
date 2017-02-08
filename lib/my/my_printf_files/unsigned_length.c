/*
** unsigned_length.c for unsigned_length in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Sun Nov 20 22:11:09 2016 Timothée Couble
** Last update Wed Nov 23 14:16:49 2016 Timothée Couble
*/

#include "../../include/my_printf.h"

unsigned short		unsigned_short(unsigned long long nb)
{
  unsigned short	result;

  result = nb;
  return (result);
}

unsigned char	unsigned_char(unsigned long long nb)
{
  unsigned char	result;

  result = nb;
  return (result);
}

unsigned int	unsigned_int(unsigned long long nb)
{
  unsigned int	result;

  result = nb;
  return (result);
}

unsigned long	unsigned_long(unsigned long long nb)
{
  unsigned long	result;

  result = nb;
  return (result);
}

unsigned long long	unsigned_length(unsigned long long nb, int length)
{
  if (length == 0)
    nb = unsigned_int(nb);
  else if (length == 1)
    nb = unsigned_short(nb);
  else if (length == 2)
    nb = unsigned_char(nb);
  else if (length == 3)
    nb = unsigned_long(nb);
  return (nb);
}
