/*
** fonctions.c for fonctions in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Tue Dec 13 09:44:43 2016 Timothée Couble
** Last update Wed Jan  4 11:28:48 2017 Timothée Couble
*/

#include "../include/my.h"
#include <ncurses.h>
#include <unistd.h>

t_coords	my_size(char *buffer, int size_buff, t_coords size)
{
  int		x;
  int		k;

  x = 0;
  k = 0;
  while (k < size_buff)
    {
      if (buffer[k] == '\n')
	{
	  if (x > size.x)
	    size.x = x;
	  x = 0;
	  size.y += 1;
	}
      x += 1;
      k += 1;
    }
  size.y += 1;
  return (size);
}

int	find_phantom(char *buffer, int size_buff)
{
  int	nb;
  int	k;

  nb = 0;
  k = 0;
  while (k < size_buff)
    {
      if (buffer[k] == 'M')
	nb += 1;
      k += 1;
    }
  return (nb);
}

void	place_phantom(char **map, t_coords size, t_coords *phantom)
{
  int	x;
  int	y;
  int	i;

  x = 0;
  y = 0;
  i = 0;
  while (y < size.y)
    {
      while (x < size.x)
	{
	  if (map[y][x] == 'M')
	    {
	      phantom[i].x = x;
	      phantom[i].y = y;
	      phantom[i].nb = 0;
	      phantom[i].count = 0;
	      i += 1;
	    }
	  x += 1;
	}
      x = 0;
      y += 1;
    }
}

int	wrong_size(t_coords size)
{
  char	*msg;
  int	size_msg;

  msg = "The windows is to small";
  size_msg = my_strlen(msg);
  initscr();
  curs_set(FALSE);
  while (1)
    {
      clear();
      mvprintw(LINES / 2, (COLS / 2) - (size_msg / 2), msg);
      refresh();
      if ((LINES / 2) - ((size.y + 2) / 2) > 0
	  && (COLS / 2) - (size.x / 2) > 0)
	{
	  endwin();
	  return (0);
	}
    }
}

void	restart(char *buffer, int size_buff, t_coords size, t_coords player)
{
  if (player.way > 0 && player.x != -1
      && player.y != -1 && player.way != 4)
    create_tab(buffer, size_buff, size, player);
  else if (player.x != -1 && player.y != -1 && player.way != 0)
    you_win(player);
  else
    you_lose(player);
}
