/*
** my_pac_man.c for my_pac_man in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Dec  8 11:03:04 2016 Timothée Couble
** Last update Wed Feb  8 13:36:46 2017 Timothée Couble
*/

#include "../include/my.h"

int	is_life(char **map, t_coords player, t_coords *phantom)
{
  int	n;

  n = 0;
  while (n < 4)
    {
      if (map[phantom[n].y][phantom[n].x] == map[player.y][player.x])
	return (1);
      n += 1;
    }
  return (0);
}

t_coords	move_shortcut(char **map, t_coords size, t_coords object)
{
  if (map[object.y][object.x + 1] == '%')
    object.x = 2;
  else if (map[object.y][object.x - 1] == '%')
    object.x = size.x - 3;
  else if (map[object.y + 1][object.x] == '%')
    object.y = 1;
  else if (map[object.y - 1][object.x] == '%')
    object.y = size.y - 2;
  return (object);
}

t_coords	find_shortcut(char **map, t_coords size,
			      t_coords player, t_coords *phantom)
{
  int	i;

  i = 0;
  player = move_shortcut(map, size, player);
  while (i < 4)
    {
      phantom[i] = move_shortcut(map, size, phantom[i]);
      i += 1;
    }
  return (player);
}

t_coords	pac_man_2(char **map, t_coords size,
			  t_coords player, t_coords *phantom)
{
  usleep(30000);
  if ((LINES / 2) - ((size.y + 2) / 2) <= 0
	  || (COLS / 2) - (size.x / 2) <= 0)
	{
	  endwin();
	  wrong_size(size);
	  pac_man(map, size, player, phantom);
	}
  if (size.nb % 5 == 0)
    {
      clear();
      player = find_shortcut(map, size, player, phantom);
      print_map(map, size, player, phantom);
      refresh();
    }
  if (is_end(map, size) == 1)
    player.way = 4;
  return (player);
}

t_coords	pac_man(char **map, t_coords size,
			t_coords player, t_coords *phantom)
{
  size.nb = 0;
  initscr();
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  nodelay(stdscr, TRUE);
  noecho();
  player.nb = 0;
  player.count = 0;
  while (1)
    {
      player = pac_man_2(map, size, player, phantom);
      size.nb += 1;
      move_phantoms(map, phantom, size, player);
      player = move_player(map, player, size);
      if ((player.x == -1 && player.y == -1) || (is_end(map, size) == 1))
	return (player);
      if (is_life(map, player, phantom) == 1)
	{
	  player.way -= 1;
	  return (player);
	}
      if (size.nb > 47264748)
	size.nb = 901;
    }
}
