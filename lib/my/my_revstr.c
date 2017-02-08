 /*
** my_revstr.c for my_revstr in /home/timothee.couble/CPool_Day06
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Mon Oct 10 08:16:51 2016 Timothée Couble
** Last update Wed Nov 23 13:38:25 2016 Timothée Couble
*/

#include "../../include/my.h"

int	count_all_char(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

char	*my_revstr(char *str)
{
  char	temp;
  int	i;
  int	j;

  j = count_all_char(str) - 1;
  i = 0;
  while (i < j)
    {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i = i + 1;
      j = j - 1;
    }
  return (str);
}
