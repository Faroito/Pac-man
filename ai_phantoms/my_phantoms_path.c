/*
** my_phantoms_path.c for my_phantoms_path in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban/bonus
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Fri Dec 16 00:02:21 2016 Timothée Couble
** Last update Tue Dec 20 23:34:27 2016 Timothée Couble
*/

#include "../include/my.h"

t_coords	goto_pac_man_x(char **map, t_coords phantom, t_coords player)
{
  if (player.x > phantom.x && map[phantom.y][phantom.x + 1] != '#')
    phantom = move_phantom_x(map, phantom, 1);
  else if (player.x < phantom.x && map[phantom.y][phantom.x - 1] != '#')
    phantom = move_phantom_x(map, phantom, -1);
  else if (player.y < phantom.y && map[phantom.y - 1][phantom.x] != '#')
    phantom = move_phantom_y(map, phantom, -1);
  else if (player.y > phantom.y && map[phantom.y + 1][phantom.x] != '#')
    phantom = move_phantom_y(map, phantom, 1);
  return (phantom);
}

t_coords	goto_pac_man_y(char **map, t_coords phantom, t_coords player)
{
  if (player.y < phantom.y && map[phantom.y - 1][phantom.x] != '#')
    phantom = move_phantom_y(map, phantom, -1);
  else if (player.y > phantom.y && map[phantom.y + 1][phantom.x] != '#')
    phantom = move_phantom_y(map, phantom, 1);
  else if (player.x > phantom.x && map[phantom.y][phantom.x + 1] != '#')
    phantom = move_phantom_x(map, phantom, 1);
  else if (player.x < phantom.x && map[phantom.y][phantom.x - 1] != '#')
    phantom = move_phantom_x(map, phantom, -1);
  return (phantom);
}

t_coords	goto_somewhere_else(char **map, t_coords phantom, long rand)
{
  if (rand % 4 == 0)
    phantom = move_phantom_x(map, phantom, 1);
  else if (rand % 4 == 1)
    phantom = move_phantom_x(map, phantom, -1);
  else if (rand % 4 == 2)
    phantom = move_phantom_y(map, phantom, -1);
  else if (rand % 4 == 3)
    phantom = move_phantom_y(map, phantom, 1);
  return (phantom);
}

t_coords	goto_somewhere(char **map, t_coords phantom,
			       t_coords player, t_coords size)
{
  long		rand_seed;

  rand_seed = pseudo_alea(size.nb + player.count - phantom.x);
  if (rand_seed % 3 == 2)
    phantom = goto_somewhere_else(map, phantom, rand_seed);
  else
    {
      if (phantom.x - player.x < phantom.y - player.y)
	phantom = goto_pac_man_x(map, phantom, player);
      else
	phantom = goto_pac_man_y(map, phantom, player);
    }
  return (phantom);
}
