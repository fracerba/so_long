/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:51:15 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/13 12:51:17 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_imgs(t_map *map, t_img *img, int y, int x)
{
	mlx_put_image_to_window(map->mlx, map->window, img -> img, x * 64, y * 64);
}

void	ft_put_wall(t_map *map, int i, int j)
{
	int	h;
	int	l;

	h = map -> check.height - 1;
	l = map -> check.lenght - 1;
	if (i == 0 && j == 0)
		ft_put_imgs(map, &map -> wall[0], i, j);
	else if (i == 0 && j == l)
		ft_put_imgs(map, &map -> wall[1], i, j);
	else if (i == h && j == 0)
		ft_put_imgs(map, &map -> wall[2], i, j);
	else if (i == h && j == l)
		ft_put_imgs(map, &map -> wall[3], i, j);
	else if (i == 0 && j > 0 && j < l)
		ft_put_imgs(map, &map -> wall[4], i, j);
	else if (j == 0 && i > 0 && i < h)
		ft_put_imgs(map, &map -> wall[5], i, j);
	else if (j == l && i > 0 && i < h)
		ft_put_imgs(map, &map -> wall[6], i, j);
	else if (i == h && j > 0 && j < l)
		ft_put_imgs(map, &map -> wall[7], i, j);
	else if (j > 0 && j < l && i > 0 && i < h)
		ft_put_imgs(map, &map -> box, i, j);
}

void	ft_map_render(t_map *map, char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j] && buffer[i][j] != '\n')
		{
			if (buffer[i][j] == '0')
				ft_put_imgs(map, &map -> floor, i, j);
			else if (buffer[i][j] == '1')
				ft_put_wall(map, i, j);
			else if (buffer[i][j] == 'C')
				ft_put_imgs(map, &map -> key, i, j);
			else if (buffer[i][j] == 'E')
				ft_put_imgs(map, &map -> exit_closed, i, j);
			else if (buffer[i][j] == 'V')
				ft_put_imgs(map, &map -> exit_open, i, j);
			j++;
		}
		i++;
	}
}

void	ft_ent_render(t_map *map)
{
	int	i;
	int	j;
	int	f;

	f = (map -> frames / 25000) % 4;
	ft_find_player(map, map -> map_buffer);
	i = map -> player.x;
	j = map -> player.y;
	if (map -> player.flip == 0)
		ft_put_imgs(map, &map -> player.imgs[f + 4], i, j);
	else if (map -> player.flip == 1)
		ft_put_imgs(map, &map -> player.imgs[f], i, j);
	if (map -> e_true == 1)
	{
		ft_find_enemy(map, map -> map_buffer);
		i = map -> enemy.x;
		j = map -> enemy.y;
		if (map -> enemy.flip == 0)
			ft_put_imgs(map, &map -> enemy.imgs[f + 4], i, j);
		else if (map -> enemy.flip == 1)
			ft_put_imgs(map, &map -> enemy.imgs[f], i, j);
	}
}

int	ft_frame_render(t_map *map)
{
	map -> frames++;
	if (map -> ending != 0)
	{
		if (map -> ending == 1)
		{
			ft_win(map);
			return (0);
		}
		else if (map -> ending == -1 && map -> e_true == 1)
		{
			ft_kill_player(map);
			return (0);
		}
	}
	if ((map-> frames % 62500) == 0 && map-> ending == 0 && map-> e_true == 1)
		ft_move_enemy(map);
	if ((map -> frames % 25000) == 0 && map -> ending == 0)
	{
		mlx_clear_window(map->mlx, map->window);
		ft_map_render(map, map -> map_buffer);
		ft_ent_render(map);
		ft_print_steps(map);
	}
	return (0);
}
