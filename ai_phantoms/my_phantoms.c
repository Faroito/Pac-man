/*
** my_phantoms.c for my_phantoms in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban/bonus
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Thu Dec 15 19:20:52 2016 Timothée Couble
** Last update Tue Dec 20 23:33:01 2016 Timothée Couble
*/

#include "../include/my.h"

t_coords	move_phantom_x(char **map, t_coords phantom, int x)
{
  if (map[phantom.y][phantom.x + x] == '%')
    return (phantom);
  if (map[phantom.y][phantom.x + x] == '#' ||
      map[phantom.y][phantom.x + x] == 'M' ||
      (phantom.nb == 1 && (map[phantom.y][phantom.x + x] == '-' ||
			   map[phantom.y][phantom.x + x] == '|')))
    {
      phantom.way = x * -1;
      return (phantom);
    }
  if (phantom.count == 1)
    map[phantom.y][phantom.x] = '.';
  else
    map[phantom.y][phantom.x] = ' ';
  phantom.x += x;
  if (map[phantom.y][phantom.x] == '.')
    phantom.count = 1;
  else
    phantom.count = 0;
  map[phantom.y][phantom.x] = 'M';
  phantom.way = x;
  return (phantom);
}

t_coords	move_phantom_y(char **map, t_coords phantom, int y)
{
  if (map[phantom.y + y][phantom.x] == '%')
    return (phantom);
  if (map[phantom.y + y][phantom.x] == '#' ||
      map[phantom.y + y][phantom.x] == 'M' ||
      (phantom.nb == 1 && (map[phantom.y + y][phantom.x] == '-' ||
			   map[phantom.y + y][phantom.x] == '|')))
    {
      phantom.way = y * -2;
      return (phantom);
    }
  if (phantom.count == 1)
    map[phantom.y][phantom.x] = '.';
  else
    map[phantom.y][phantom.x] = ' ';
  phantom.y += y;
  if (map[phantom.y][phantom.x] == '.')
    phantom.count = 1;
  else
    phantom.count = 0;
  map[phantom.y][phantom.x] = 'M';
  phantom.way = y * 2;
  return (phantom);
}

int	phantom_choice(char **map, t_coords phantom)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  if (map[phantom.y][phantom.x + 1] != '#')
    x += 1;
  if (map[phantom.y][phantom.x - 1] != '#')
    x += 1;
  if (map[phantom.y + 1][phantom.x] != '#')
    y += 1;
  if (map[phantom.y - 1][phantom.x] != '#')
    y += 1;
  if ((x == 2 && y > 0) || (y == 2 && x > 0))
    return (1);
  else if (x == 1 && y == 1)
    return (2);
  return (0);
}

t_coords	auto_moving_phantoms(char **map, t_coords phantom,
				     t_coords player, t_coords size)
{
  if (phantom.nb == 0)
    {
      phantom = goto_door_x(map, phantom, find_door(map));
      phantom = goto_door_y(map, phantom, find_door(map));
    }
  else
    {
      if (phantom_choice(map, phantom) == 1)
	phantom = goto_somewhere(map, phantom, player, size);
      else if (phantom_choice(map, phantom) == 2)
	phantom = goto_corners(map, phantom);
      else
	{
	  if (phantom.way == -2 || phantom.way == 2)
	    phantom = move_phantom_y(map, phantom, phantom.way / 2);
	  else
	    phantom = move_phantom_x(map, phantom, phantom.way);
	}
    }
  return (phantom);
}

void	move_phantoms(char **map, t_coords *phantom,
		      t_coords size, t_coords player)
{
  if (size.nb > 50 && size.nb % 8 == 0)
    phantom[0] = auto_moving_phantoms(map, phantom[0], player, size);
  if (size.nb > 200 && size.nb % 8 == 0)
    phantom[1] = auto_moving_phantoms(map, phantom[1], player, size);
  if (size.nb > 350 && size.nb % 8 == 0)
    phantom[2] = auto_moving_phantoms(map, phantom[2], player, size);
  if (size.nb > 500 && size.nb % 8 == 0)
    phantom[3] = auto_moving_phantoms(map, phantom[3], player, size);
}
