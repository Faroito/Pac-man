/*
** my_phantoms_door.c for my_phantoms_door.c in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban/bonus
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Fri Dec 16 00:02:21 2016 Timothée Couble
** Last update Tue Dec 20 23:33:55 2016 Timothée Couble
*/

#include "../include/my.h"

t_coords	find_door(char **map)
{
  int		x;
  int		y;
  t_coords	door;

  x = 0;
  y = 0;
  door.x = -1;
  door.y = -1;
  door.nb = '-';
  while (map[y][x] != '\0')
    {
      if (map[y][x] == '\n')
	{
	  y += 1;
	  x = 0;
	}
      else if (map[y][x] == '-' || map[y][x] == '|')
	{
	  door.x = x;
	  door.y = y;
	  door.nb = map[y][x];
	}
      x += 1;
    }
  return (door);
}

t_coords	passing_door(char **map, t_coords phantom)
{
  if (phantom.way == -2 || phantom.way == 2)
    {
      phantom = move_phantom_y(map, phantom, phantom.way / 2);
      map[phantom.y - phantom.way / 2][phantom.x] = '-';
    }
  else
    {
      phantom = move_phantom_x(map, phantom, phantom.way);
      map[phantom.y][phantom.x - phantom.way] = '|';
    }
  phantom.nb = 1;
  return (phantom);
}

t_coords	goto_door_x(char **map, t_coords phantom, t_coords door)
{
  if (door.nb == '-')
    {
      if (door.x > phantom.x && door.x > -1)
	phantom = move_phantom_x(map, phantom, 1);
      else if (door.x < phantom.x && door.x > -1)
	phantom = move_phantom_x(map, phantom, -1);
      else if (door.y < phantom.y && door.y > -1)
	phantom = move_phantom_y(map, phantom, -1);
      else if (door.y > phantom.y && door.x > -1)
	phantom = move_phantom_y(map, phantom, 1);
      else
	phantom = passing_door(map, phantom);
    }
  return (phantom);
}

t_coords	goto_door_y(char **map, t_coords phantom, t_coords door)
{
  if (door.nb == '|' && phantom.nb == 0)
    {
      if (door.y < phantom.y && door.y > -1)
	phantom = move_phantom_y(map, phantom, -1);
      else if (door.y > phantom.y && door.x > -1)
	phantom = move_phantom_y(map, phantom, 1);
      else if (door.x > phantom.x && door.x > -1)
	phantom = move_phantom_x(map, phantom, 1);
      else if (door.x < phantom.x && door.x > -1)
	phantom = move_phantom_x(map, phantom, -1);
      else
	phantom = passing_door(map, phantom);
    }
  return (phantom);
}

