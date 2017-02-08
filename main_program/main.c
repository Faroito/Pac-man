/*
** main.c for main in /home/timothee.couble/Epitech/C_Prog_Elem/CPE_2016_BSQ
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Mon Dec  5 13:01:41 2016 Timothée Couble
** Last update Tue Dec 20 23:23:18 2016 Timothée Couble
*/

#include "include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ncurses.h>

t_coords	attribute_tab(char *buffer, int size_buff,
			      char **map, t_coords player)
{
  int		x;
  int		y;
  int		k;

  x = 0;
  y = 0;
  k = 0;
  while (k < size_buff)
    {
      if (buffer[k] == '\n')
	{
	  map[y][x] = buffer[k];
	  x = 0;
	  y += 1;
	}
      else
	{
	  player = add_player(x, y, buffer[k], player);
	  map[y][x] = buffer[k];
	  x += 1;
	}
      k += 1;
    }
  return (player);
}

int		create_tab(char *buffer, int size_buff,
			   t_coords size, t_coords player)
{
  char		**map;
  int		n;
  t_coords	*phantom;

  n = 0;
  if ((map = malloc(sizeof(char *) * (size.y + 1))) == NULL)
    return (84);
  while (n < size.y)
    {
      if ((map[n] = malloc(sizeof(char) * (size.x + 1))) == NULL)
	return (84);
      n += 1;
    }
  find_phantom(buffer, size_buff);
  phantom = malloc(sizeof(t_coords) * 4);
  player = attribute_tab(buffer, size_buff, map, player);
  place_phantom(map, size, phantom);
  player = pac_man(map, size, player, phantom);
  endwin();
  restart(buffer, size_buff, size, player);
  return (0);
}

int		open_file(char *file)
{
  int		fd;
  char		buffer[30000];
  int		size_buff;
  t_coords	size;
  t_coords	player;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (84);
  size_buff = read(fd, buffer, 29999);
  if (size_buff == -1)
    return (84);
  close(fd);
  size.x = 0;
  size.y = 0;
  player.x = -1;
  player.y = -1;
  player.way = 3;
  size = my_size(buffer, size_buff, size);
  create_tab(buffer, size_buff, size, player);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    return (84);
  if (av[1][0] == '-' && av[1][1] == 'h')
    {
      man_pac_man();
      return (0);
    }
  return (open_file(av[1]));
}
