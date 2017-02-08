/*
** my_end_msg.c for my_end_msg in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban/bonus/pac_man
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Wed Dec 21 14:34:31 2016 Timothée Couble
** Last update Wed Dec 21 14:46:00 2016 Timothée Couble
*/

#include "../include/my.h"
#include <ncurses.h>

int	you_win(t_coords player)
{
  char	*msg;
  int	size_msg;

  msg = "You win ! Your score is :";
  size_msg = my_strlen(msg);
  initscr();
  curs_set(FALSE);
  while (1)
    {
      clear();
      mvprintw(LINES / 2, (COLS / 2) - ((size_msg + 5) / 2),
	       "%s %i", msg, player.count);
      refresh();
      if (getch() == 32)
	{
	  endwin();
	  return (0);
	}
    }
}

int	you_lose(t_coords player)
{
  char	*msg;
  int	size_msg;

  msg = "You lose ! Your score is :";
  size_msg = my_strlen(msg);
  initscr();
  curs_set(FALSE);
  while (1)
    {
      clear();
      mvprintw(LINES / 2, (COLS / 2) - ((size_msg + 5) / 2),
	       "%s %i\n", msg, player.count);
      refresh();
      if (getch() == 32)
	{
	  endwin();
	  return (0);
	}
    }
}
