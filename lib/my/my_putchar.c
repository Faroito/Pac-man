/*
** my_putchar.c for my_putchar in /home/timothee.couble/CPool_Day07/lib
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Oct 12 08:42:18 2016 Timothée Couble
** Last update Wed Nov 23 13:37:55 2016 Timothée Couble
*/

#include "../../include/my.h"
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
