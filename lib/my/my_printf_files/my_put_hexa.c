/*
** my_put_hexa.c for my_put_hexa in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Nov 10 17:06:39 2016 Timothée Couble
** Last update Wed Nov 23 14:04:31 2016 Timothée Couble
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void	calcul_hexa(long long nb, int plus)
{
  if (nb < 0)
    {
      nb *= -1;
      my_putchar('-');
    }
  else if (plus == 1)
    my_putchar('+');
  if (nb >= 16)
    calcul_hexa(nb / 16, 0);
  nb = nb % 16;
  if (nb > 9)
    my_putchar(nb + 87);
  else
    my_putchar(nb + 48);
}

void	my_put_hexa(va_list args, int *justify, int length)
{
  long long	nb;

  nb = va_arg(args, long long);
  nb = choose_length(nb, length);
  if (justify[0] == 1)
    {
      calcul_hexa(nb, justify[1]);
      print_justify(calc_justify(nb, justify), 0);
    }
  else
    {
      if (justify[2] > 0 && justify[0] == 0)
	print_justify(calc_justify(nb, justify), 0);
      else if (justify[0] == 2)
	print_justify(calc_justify(nb, justify), 1);
      calcul_hexa(nb, justify[1]);
    }
}
