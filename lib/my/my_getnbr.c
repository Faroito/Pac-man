/*
** my_getnbr.c for my_getnbr in /home/timothee.couble/CPool_Day04
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Fri Oct  7 17:53:20 2016 Timothée Couble
** Last update Wed Dec  7 09:22:54 2016 Timothée Couble
*/

#include "../../include/my.h"

int     count_str_getnbr(char *str)
{
  int count;

  count = 0;
  while (str[count] != '\0')
    {
      count = count + 1;
    }
  return (count);
}

int	my_getnbr_while(char *str, int count, int k)
{
  int	c;

  c = 0;
  while (str[count] != '\0')
    {
      if (k == 0)
	{
	  if (*(str + count) == '-')
	    {
	      c = c + 1;
	    }
	  while (*(str + count) >= '0' && *(str + count) <= '9')
	    {
	      if (c % 2 != 0)
		{
		  my_putchar('-');
		  c = c + 1;
		}
	      return (*(str + count));
	      count = count + 1;
	      k = 1;
	    }
	}
      count = count + 1;
    }
}

int	my_getnbr(char *str)
{
  int	count;
  int	count_str;
  int	k;

  count_str = count_str_getnbr(str);
  if (count_str > 31)
    {
      return (0);
    }
  else
    {
      my_getnbr_while(str, 0, 0);
    }
}
