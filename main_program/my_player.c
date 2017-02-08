/*
** my_player.c for player in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Dec 13 14:39:18 2016 Timothée Couble
** Last update Tue Dec 20 23:35:44 2016 Timothée Couble
*/

#include <ncurses.h>
#include "../include/my.h"

t_coords	add_player(int x, int y, char buffer, t_coords player)
{
  if (buffer == 'C')
    {
      player.x = x;
      player.y = y;
    }
  return (player);
}

t_coords	move_player_x(char **map, t_coords player, int x)
{
  if (map[player.y][player.x + x] == '#' ||
      map[player.y][player.x + x] == '-' ||
      map[player.y][player.x + x] == '|' ||
      map[player.y][player.x + x] == '%')
    return (player);
  map[player.y][player.x] = ' ';
  player.x += x;
  if (map[player.y][player.x] == '.')
    player.count += 1;
  map[player.y][player.x] = 'C';
  return (player);
}

t_coords	move_player_y(char **map, t_coords player, int y)
{
  if (map[player.y + y][player.x] == '#' ||
      map[player.y + y][player.x] == '-' ||
      map[player.y + y][player.x] == '|' ||
      map[player.y + y][player.x] == '%')
    return (player);
  map[player.y][player.x] = ' ';
  player.y += y;
  if (map[player.y][player.x] == '.')
    player.count += 1;
  map[player.y][player.x] = 'C';
  return (player);
}

t_coords	auto_moving_player(char **map, t_coords player)
{
  if (player.nb == 0)
    player = move_player_x(map, player, -1);
  if (player.nb == 1)
    player = move_player_x(map, player, 1);
  if (player.nb == 2)
    player = move_player_y(map, player, -1);
  if (player.nb == 3)
    player = move_player_y(map, player, 1);
  return (player);
}

t_coords	move_player(char **map, t_coords player, t_coords size)
{
  int		t;
  t_coords	stop;

  t = getch();
  stop.x = -1;
  stop.y = -1;
  if (t == KEY_LEFT)
    player.nb = 0;
  if (t == KEY_RIGHT)
    player.nb = 1;
  if (t == KEY_UP)
    player.nb = 2;
  if (t == KEY_DOWN)
    player.nb = 3;
  if ((size.nb % 5 == 0 && (player.nb == 0 || player.nb == 1)) ||
      (size.nb % 7 == 0 && (player.nb == 2 || player.nb == 3)))
    player = auto_moving_player(map, player);
  if (t == 32)
    return (stop);
  return (player);
}
