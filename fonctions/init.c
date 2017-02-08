/*
** init.c for init in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban/bonus/pac_man
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Dec 20 23:22:37 2016 Timothée Couble
** Last update Wed Dec 21 14:42:25 2016 Timothée Couble
*/

#include "include/my.h"
#include <ncurses.h>

long	pseudo_alea(long rand_seed)
{
  rand_seed = rand_seed * 1103515245 + 12345;
  rand_seed = (rand_seed / 65536) % 32768;
  return (rand_seed);
}

void	my_start_color()
{
  start_color();
  init_pair(5, COLOR_YELLOW, 0);
  init_color(COLOR_BLUE, 24, 31, 800);
  init_pair(6, COLOR_BLUE, 0);
  init_pair(1, COLOR_RED, 0);
  init_pair(2, COLOR_CYAN, 0);
  init_pair(3, COLOR_MAGENTA, 0);
  init_color(COLOR_GREEN, 937, 419, 835);
  init_pair(4, COLOR_GREEN, 0);
}

void	man_pac_man()
{
  my_printf("USAGE\n\t./my_pac_man map\n");
  my_printf("\nDESCRIPTION\n\tmap\tfile representing ");
  my_printf("the map, containing '#' for walls,\n");
  my_printf("\t\t'C' for the player, '.' for ");
  my_printf("coint and 'M' for phantoms.\n");
}

int	is_end(char **map, t_coords size)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < size.y)
    {
      while (x < size.x)
	{
	  if (map[y][x] == '.')
	    return (0);
	  x += 1;
	}
      x = 0;
      y += 1;
    }
  return (1);
}
