/*
** my_put_unsigned_nbr.c for my_put_unsigned_nbr in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf_bootstrap
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Nov 10 17:06:39 2016 Timothée Couble
** Last update Wed Nov 23 14:16:27 2016 Timothée Couble
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void	calcul_unsigned_nbr(unsigned long long nb, int plus)
{
  if (nb < 0)
    {
      nb *= -1;
      my_putchar('-');
    }
  else if (plus == 1)
    my_putchar('+');
  if (nb > 9)
    calcul_unsigned_nbr(nb / 10, 0);
  nb %= 10;
  my_putchar(nb + 48);
}

void		my_put_unsigned_nbr(va_list args, int *justify, int length)
{
  unsigned long long	nb;

  nb = va_arg(args, unsigned long long);
  nb = unsigned_length(nb, length);
  if (justify[0] == 1)
    {
      calcul_unsigned_nbr(nb, justify[1]);
      print_justify(calc_justify(nb, justify), 0);
    }
  else
    {
      if (justify[2] > 0 && justify[0] == 0)
	print_justify(calc_justify(nb, justify), 0);
      else if (justify[0] == 2)
	print_justify(calc_justify(nb, justify), 1);
      calcul_unsigned_nbr(nb, justify[1]);
    }
}
