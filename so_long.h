/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:23:11 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/15 10:23:13 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_check_path
{
	int		score;
	int		threes;
	int		valid;
	int		player_x;
	int		player_y;
	int		exit_reached;
	char	**copy;
}	t_check_path;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		line;
	int		end;
	int		height;
	int		lenght;
	int		bits;
}	t_img;

typedef struct s_check_map
{
	int	space;
	int	wall;
	int	collectible;
	int	player;
	int	exit;
	int	valid;
	int	height;
	int	lenght;
}	t_check_map;

typedef struct s_ent
{
	int		x;
	int		y;
	int		flip;
	int		steps;
	int		death;
	t_img	imgs[20];
}	t_ent;

typedef struct s_map
{
	t_check_map	check;
	void		*mlx;
	void		*window;
	char		**map_buffer;
	t_ent		player;
	t_ent		enemy;
	t_img		wall[8];
	t_img		floor;
	t_img		box;
	t_img		key;
	t_img		exit_closed;
	t_img		exit_open;
	int			exit_x;
	int			exit_y;
	int			frames;
	int			score;
	int			e_true;
	int			ending;
}	t_map;

int		ft_check_char(char **buffer, t_map *map);
int		ft_check_various(t_map *map);
int		ft_check_shape(char **buffer, t_map *map);
int		ft_check_walls(char **buffer);
int		ft_check_map(int argc, char *argv, t_map *map);

int		ft_file_error(void);
int		ft_check_file(char *argv);
int		ft_char_error(char buffer, t_map *map);
int		ft_wall_error(char buffer);
int		ft_check_walls_extra(char *buffer);

void	ft_file_error_2(void);
void	ft_map_error(void);
void	ft_map_error_2(char **buffer);
void	ft_check_init(t_map *map);

int		ft_path_error(char **copy);
int		ft_first_check_aux(char **copy, int i, int j);
int		ft_first_check(char **copy);
int		ft_real_check(char **copy, t_map *map, t_check_path *path);
int		ft_check_path(char **buffer, t_map *map);

void	ft_find_player_path(t_check_path *path, char **copy);
void	ft_init_path(t_check_path *path, char **copy);
void	ft_set_threes(t_check_path *path, char **copy, int i, int j);
void	ft_next_move(t_check_path *path, char **copy, int i, int j);
void	ft_check_check(t_check_path *path, t_map *map);

int		get_map_size(char *argv);
char	**ft_map_fill(char *argv, t_map *map);
void	ft_free_map(char **buffer);

void	get_img(t_map *map, t_img *img, char *path);
void	set_img_enemy(t_map *map);
void	set_player_knight(t_map *map);
void	set_player_rogue(t_map *map);
void	set_imgs(t_map *map, char *argv);

void	ft_find_player(t_map *map, char **buffer);
void	ft_find_enemy(t_map *map, char **buffer);
void	ft_find_exit(t_map *map, char **buffer);

void	ft_move_up(t_map *map, char **buffer, int x, int y);
void	ft_move_down(t_map *map, char **buffer, int x, int y);
void	ft_move_left(t_map *map, char **buffer, int x, int y);
void	ft_move_right(t_map *map, char **buffer, int x, int y);
int		ft_move(int key, t_map *map);

void	ft_enemy_up(t_map *map, char **buffer, int x, int y);
void	ft_enemy_down(t_map *map, char **buffer, int x, int y);
void	ft_enemy_left(t_map *map, char **buffer, int x, int y);
void	ft_enemy_right(t_map *map, char **buffer, int x, int y);
void	ft_move_enemy(t_map *map);

void	ft_put_imgs(t_map *map, t_img *img, int y, int x);
void	ft_put_wall(t_map *map, int i, int j);
void	ft_map_render(t_map *map, char **buffer);
void	ft_ent_render(t_map *map);
int		ft_frame_render(t_map *map);

int		ft_check_space(char **buffer, int i, int j);
void	ft_spawn_enemy(t_map *map, char **buffer);

void	ft_unlock_exit(t_map *map, char **buffer);
void	ft_print_steps(t_map *map);
void	ft_kill_player(t_map *map);
void	ft_win_aux(t_map *map);
void	ft_win(t_map *map);

void	ft_ent_render_death(t_map *map);
void	ft_death_screen(t_map *map);
void	ft_ent_render_win(t_map *map);
void	ft_victory_screen(t_map *map);

void	ft_destroy_imgs_ent(t_map *map);
void	ft_destroy_imgs(t_map *map);
void	ft_map_init(t_map *map);
int		ft_close(t_map *map);

#endif
