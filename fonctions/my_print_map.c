/*
** my_print_map.c for my_print_map in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban/bonus
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Dec 15 16:29:22 2016 Timothée Couble
** Last update Wed Dec 21 14:46:03 2016 Timothée Couble
*/

#include "../include/my.h"
#include <ncurses.h>

void	color_pac_man(char **map, t_coords player, t_coords size)
{
  if (size.count == player.y && size.way == player.x)
    {
      attron(COLOR_PAIR(5));
      mvaddch((LINES / 2) - (size.y / 2) + size.count,
	      (COLS / 2) - (size.x / 2) + size.way,
	      map[size.count][size.way]);
      attroff(COLOR_PAIR(5));
    }
}

void	color_phantom(char **map, t_coords *phantom, t_coords size)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      if (size.way == phantom[i].x && size.count == phantom[i].y)
	{
	  attron(COLOR_PAIR(i + 1));
	  mvaddch((LINES / 2) - (size.y / 2) + size.count,
		  (COLS / 2) - (size.x / 2) + size.way,
		  map[size.count][size.way]);
	  attroff(COLOR_PAIR(i + 1));
	}
      i += 1;
    }
}

void	color_map(char **map, int x, int y, t_coords size)
{
  if (map[y][x] == '#' || map[y][x] == '-' || map[y][x] == '|')
    {
      attron(COLOR_PAIR(6));
      mvaddch((LINES / 2) - (size.y / 2) + y,
	      (COLS / 2) - (size.x / 2) + x, map[y][x]);
      attroff(COLOR_PAIR(6));
    }
  else if (map[y][x] == '.')
    mvaddch((LINES / 2) - (size.y / 2) + y,
	    (COLS / 2) - (size.x / 2) + x, map[y][x]);
}

void	print_map_2(char **map, t_coords size,
		    t_coords player, t_coords *phantom)
{
  while (size.count < size.y)
    {
      while (size.way < size.x - 1)
	{
	  color_phantom(map, phantom, size);
	  color_pac_man(map, player, size);
	  color_map(map, size.way, size.count, size);
	  size.way += 1;
	}
      mvaddch((LINES / 2) - (size.y / 2) + size.count,
	      (COLS / 2) - (size.x / 2) + size.way + 1, '\n');
      size.way = 0;
      size.count += 1;
    }
}

void	print_map(char **map, t_coords size,
		  t_coords player, t_coords *phantom)
{
  char	*msg;
  int	i;

  size.count = 0;
  size.way = 0;
  i = 0;
  my_start_color();
  msg = "Your score is :";
  mvprintw((LINES / 2) - ((size.y) / 2) - 3,
	   (COLS / 2) - ((my_strlen(msg) + 5) / 2), "%s %i\n", msg, player.count);
  while (i < player.way)
    {
      attron(COLOR_PAIR(5));
      mvaddch((LINES / 2) - (size.y / 2) -1,
	      (COLS / 2) - (size.x / 2) + i, 'C');
      attroff(COLOR_PAIR(5));
      i += 1;
    }
  print_map_2(map, size, player, phantom);
}
