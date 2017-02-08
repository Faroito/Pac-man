/*
** my_printf.c for my_printf in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf_norepo
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Nov 15 10:07:02 2016 Timothée Couble
** Last update Mon Nov 28 13:53:02 2016 Timothée Couble
*/

#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdarg.h>

int	change_length(char *s, int i, va_list args, int *justify)
{
  void	(*specifer[12])(va_list, int *, int);

  add_specifer(specifer);
  if (find_length(s, i) <= 2)
    (*specifer[find_specifer(s, i + 1)])(args, justify, 0);
  else if (find_length(s, i) == 3)
    (*specifer[find_specifer(s, i + 1)])(args, justify, 1);
  else if (find_length(s, i) == 5)
    (*specifer[find_specifer(s, i + 2)])(args, justify, 2);
  else if (find_length(s, i) == 4)
    (*specifer[find_specifer(s, i + 1)])(args, justify, 3);
  else if (find_length(s, i) == 6)
    (*specifer[find_specifer(s, i + 2)])(args, justify, 4);
  if (find_length(s, i) >= 5)
    i = i + 1;
  i = i + 1;
  return (i);
}

int	parameters(char *s, int i, va_list args)
{
  void	(*specifer[12])(va_list, int *, int);
  int	end;
  int	*justify;

  add_specifer(specifer);
  justify = add_justify(justify);
  end = 0;
  while (s[i] != '\0' && end == 0)
    {
      if (find_specifer(s, i) >= 0 || find_length(s, i) >= 1)
	{
	  if (find_length(s, i) >= 0)
	    i = change_length(s, i, args, justify);
	  else
	    (*specifer[find_specifer(s, i)])(args, justify, 0);
	  end = 1;
	}
      else if (find_flags(s, i) == 1)
	justify = find_width(s, i, justify);
      else
	return (i);
      i = i + 1;
    }
  return (i);
}

int	my_printf(char *s, ...)
{
  va_list	args;
  int		nb;
  int		i;

  i = 0;
  va_start(args, s);
  nb = my_strlen(s);
  while (i < nb)
    {
      if (s[i] == '%')
	{
	  i = i + 1;
	  i = parameters(s, i, args);
	}
      else if (s[i] != '\0')
	{
	  my_putchar(s[i]);
	  i = i + 1;
	}
    }
  return (i);
}
