/*
** justify.c for justify in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Sun Nov 20 17:19:13 2016 Timothée Couble
** Last update Wed Nov 23 14:02:49 2016 Timothée Couble
*/

#include "../../include/my_printf.h"

void	print_justify(int nb, int type)
{
  while (nb > 0)
    {
      if (type == 0)
	my_putchar(' ');
      if (type == 1)
	my_putchar('0');
      nb -= 1;
    }
}

long long	count_nb(long long nb)
{
  long long	result;

  result = 0;
  while (nb != 0)
    {
      nb /= 10;
      result += 1;
    }
  return (result);
}

int	calc_justify(long long nb, int *justify)
{
  int	result;

  result = justify[2] - count_nb(nb);
  if (nb < 0 || justify[1] == 1)
    result -= 1;
  return (result);
}
