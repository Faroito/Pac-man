/*
** add_parameters.c for parameters in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Sat Nov 19 16:18:59 2016 Timothée Couble
** Last update Wed Dec  7 09:21:58 2016 Timothée Couble
*/

#include "../../../include/my_printf.h"
#include <stdarg.h>
#include <stdlib.h>

void	add_specifer(void (*specifer[12])(va_list, int *, int))
{
  specifer[0] = &my_put_fnbr;
  specifer[1] = &my_put_fnbr;
  specifer[2] = &my_put_octal;
  specifer[3] = &my_put_unsigned_nbr;
  specifer[4] = &my_put_hexa;
  specifer[5] = &my_put_caps_hexa;
  specifer[6] = &my_put_char;
  specifer[7] = &my_put_str;
  specifer[9] = &my_showstr;
  specifer[10] = &my_put_binary;
  specifer[11] = &my_put_percent;
}

int	*add_justify(int *justify)
{
  if (justify != (justify = malloc(sizeof(int) * 4)))
    return (84);
  justify[0] = 0;
  justify[1] = 0;
  justify[2] = 0;
  justify[3] = 0;
  return (justify);
}
