/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:24:48 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/18 12:24:51 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ent_render_death(t_map *map)
{
	int	i;
	int	j;
	int	d;
	int	f;

	d = map -> player.death + 8;
	f = (map -> frames / 25000) % 4;
	ft_find_player(map, map -> map_buffer);
	i = map -> player.x;
	j = map -> player.y;
	if (map -> player.flip == 0)
		ft_put_imgs(map, &map -> player.imgs[d + 6], i, j);
	else if (map -> player.flip == 1)
		ft_put_imgs(map, &map -> player.imgs[d], i, j);
	ft_find_enemy(map, map -> map_buffer);
	i = map -> enemy.x;
	j = map -> enemy.y;
	if (map -> enemy.flip == 0)
		ft_put_imgs(map, &map -> enemy.imgs[f + 4], i, j);
	else if (map -> enemy.flip == 1)
		ft_put_imgs(map, &map -> enemy.imgs[f], i, j);
}

void	ft_death_screen(t_map *map)
{
	int	x;
	int	y;

	mlx_clear_window(map->mlx, map->window);
	x = (map -> check.lenght * 32) - 36;
	y = (map -> check.height * 32) - 10;
	mlx_string_put(map->mlx, map->window, x, y, 16711680, "SEI MORTO");
}

void	ft_ent_render_win(t_map *map)
{
	int	i;
	int	j;
	int	d;

	d = map -> enemy.death + 8;
	ft_find_enemy(map, map -> map_buffer);
	i = map -> enemy.x;
	j = map -> enemy.y;
	if (map -> enemy.flip == 0)
		ft_put_imgs(map, &map -> enemy.imgs[d + 6], i, j);
	else if (map -> enemy.flip == 1)
		ft_put_imgs(map, &map -> enemy.imgs[d], i, j);
}

void	ft_victory_screen(t_map *map)
{
	int	x;
	int	y;

	mlx_clear_window(map->mlx, map->window);
	x = (map -> check.lenght * 32) - 36;
	y = (map -> check.height * 32) - 10;
	mlx_string_put(map->mlx, map->window, x, y, 65280, "HAI VINTO");
}
