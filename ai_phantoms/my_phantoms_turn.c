/*
** my_phantoms_turn.c for my_phantoms_turn in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban/bonus
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Fri Dec 16 10:45:42 2016 Timothée Couble
** Last update Tue Dec 20 23:35:16 2016 Timothée Couble
*/

#include "../include/my.h"

int	phantom_turn_y(char **map, t_coords phantom)
{
  int	turn;

  turn = 0;
  if (map[phantom.y + 1][phantom.x] != '#')
    turn = 1;
  else
    turn = -1;
  return (turn);
}

int	phantom_turn_x(char **map, t_coords phantom)
{
  int	turn;

  turn = 0;
  if (map[phantom.y][phantom.x + 1] != '#')
    turn = 1;
  else
    turn = -1;
  return (turn);
}

t_coords	goto_corners(char **map, t_coords phantom)
{
  if (phantom.way == -2 || phantom.way == 2)
    {
      phantom.way = phantom_turn_x(map, phantom);
      phantom = move_phantom_x(map, phantom, phantom.way);
    }
  else
    {
      phantom.way = phantom_turn_y(map, phantom);
      phantom = move_phantom_y(map, phantom, phantom.way);
    }
  return (phantom);
}
