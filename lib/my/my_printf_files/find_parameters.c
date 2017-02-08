/*
** find_parameters.c for find_parameters in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_printf
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Sat Nov 19 16:07:14 2016 Timothée Couble
** Last update Wed Nov 23 14:02:41 2016 Timothée Couble
*/

#include "../../include/my_printf.h"
#include <stdlib.h>

int	find_specifer(char *s, int i)
{
  char	*specifer;
  int	n;

  n = 0;
  specifer = malloc(sizeof(char *) * 13);
  specifer = "diouxXcspSb%";
  while (specifer[n] != s[i])
    {
      n = n + 1;
      if (n > 11)
	return (-1);
    }
  return (n);
}

int	find_length(char *s, int i)
{
  char	*length;
  int	n;

  n = 0;
  length = malloc(sizeof(char *) * 5);
  length = "jzthl";
  while (length[n] != s[i])
    {
      n = n + 1;
      if (n > 4)
	return (-1);
    }
  if (n == 3 && s[i + 1] == 'h')
    n = 5;
  if (n == 4 && s[i + 1] == 'l')
    n = 6;
  return (n);
}

int	find_flags(char *s, int i)
{
  if ('0' <= s[i] && s[i] <= '9')
    return (1);
  else if (s[i] == '-' || s[i] == '0' || s[i] == '+')
    return (1);
  else
    return (0);
}

int	*find_width(char *s, int i, int *justify)
{
  if (s[i] == '-')
    justify[0] = 1;
  if (s[i] == '+')
    justify[1] = 1;
  if ('0' <= s[i] && s[i] <= '9')
    justify[3] = 1;
  if (s[i] == '0' && justify[3] == 0)
    {
      justify[0] = 2;
      justify[3] = 1;
    }
  if (s[i + 1] < '0' || '9' < s[i + 1])
    justify[2] = number(s, i);
  return (justify);
}
