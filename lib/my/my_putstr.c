/*
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Fri Oct  7 15:00:11 2016 Timothée Couble
** Last update Wed Nov 23 13:38:13 2016 Timothée Couble
*/

#include "../../include/my.h"

void	my_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
