/*
** my_strlen.c for my_strlen in /home/timothee.couble/CPool_Day04
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Fri Oct  7 16:37:33 2016 Timothée Couble
** Last update Wed Nov 23 13:41:03 2016 Timothée Couble
*/

#include "../../include/my.h"

int	my_strlen(char *str)
{
  int count;

  count = 0;
  while (str[count] != '\0')
    {
      count = count + 1;
    }
  return (count);
}
