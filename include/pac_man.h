/*
** pac_man.h for pac_man in /home/timothee.couble/Epitech/Unix_System/PSU_2016_my_sokoban
** 
** Made by Timothée Couble
** Login   <timothee.couble@epitech.net>
** 
** Started on  Mon Dec 12 12:51:47 2016 Timothée Couble
** Last update Wed Dec 21 14:43:19 2016 Timothée Couble
*/

#ifndef PAC_MAN_H_
# define PAC_MAN_H_

typedef struct	s_coords
{
  int	x;
  int	y;
  int	nb;
  int	count;
  int	way;
}		t_coords;

t_coords	pac_man(char **map, t_coords size,
			t_coords player, t_coords *phantom);
void		place_phantom(char **map, t_coords size, t_coords *phantom);
int		find_phantom(char *buffer, int size_buff);
int		wrong_size(t_coords size);
void		my_start_color();
void		man_pac_man();
long		pseudo_alea(long rand_seed);
void		print_map(char **map, t_coords size,
			  t_coords player, t_coords *phantom);
void		restart(char *buffer, int size_buff,
			t_coords size, t_coords player);
int		create_tab(char *buffer, int size_buff,
			   t_coords size, t_coords player);
void		move_phantoms(char **map, t_coords *phantom,
			      t_coords size, t_coords player);
t_coords	move_player(char **map, t_coords player, t_coords size);
t_coords	add_player(int x, int y, char buffer, t_coords player);
t_coords	my_size(char *buffer, int size_buff, t_coords size);
t_coords	move_phantom_x(char **map, t_coords phantom, int x);
t_coords	move_phantom_y(char **map, t_coords phantom, int y);
t_coords	find_door(char **map);
t_coords	goto_door_x(char **map, t_coords phantom, t_coords door);
t_coords	goto_door_y(char **map, t_coords phantom, t_coords door);
t_coords	goto_somewhere(char **map, t_coords phantom,
			       t_coords player, t_coords size);
t_coords	goto_corners(char **way, t_coords phantom);
int		you_win(t_coords player);
int		you_lose(t_coords player);
int		is_end(char **map, t_coords size);

#endif /* !PAC_MAN_H_ */
