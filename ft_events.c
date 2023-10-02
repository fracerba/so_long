/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:51:57 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/13 12:51:58 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_unlock_exit(t_map *map, char **buffer)
{
	int	i;
	int	j;
	int	s;
	int	c;

	i = map -> exit_x;
	j = map -> exit_y;
	s = map -> score;
	c = map -> check.collectible;
	if (buffer[i][j] == 'E' && s == c)
		buffer[i][j] = 'V';
	return ;
}

void	ft_print_steps(t_map *map)
{
	char	*s;
	char	*c;
	int		y;

	c = ft_itoa(map -> player.steps);
	s = ft_strjoin("Passi: ", c);
	y = (map -> check.height * 64) - 20;
	mlx_string_put(map->mlx, map->window, 20, y, 65280, s);
	free(s);
	free(c);
}

void	ft_kill_player(t_map *map)
{
	if (map -> player.death < 6)
	{
		if ((map -> frames % 25000) == 0)
		{
			mlx_clear_window(map->mlx, map->window);
			ft_map_render(map, map -> map_buffer);
			ft_ent_render_death(map);
			ft_print_steps(map);
			map -> player.death++;
		}
	}
	else if (map -> player.death >= 6)
	{
		if ((map -> frames % 25000) == 0)
			ft_death_screen(map);
	}
	return ;
}

void	ft_win_aux(t_map *map)
{
	if (map -> player.death == 0)
	{
		ft_find_player(map, map -> map_buffer);
		map -> map_buffer[map -> player.x][map -> player.y] = '0';
		map -> player.death = -1;
	}
	mlx_clear_window(map->mlx, map->window);
	ft_map_render(map, map -> map_buffer);
	if (map -> e_true == 1)
		ft_ent_render_win(map);
	ft_print_steps(map);
	return ;
}

void	ft_win(t_map *map)
{
	if (map -> e_true == 1 && map -> enemy.death < 6)
	{
		if ((map -> frames % 25000) == 0)
		{
			ft_win_aux(map);
			map -> enemy.death++;
		}
	}
	else if (map -> e_true == 0 && map -> enemy.death < 6)
	{
		if ((map -> frames % 25000) == 0)
		{
			ft_win_aux(map);
			map -> enemy.death = 7;
		}
	}
	else if (map -> enemy.death >= 6)
	{
		if ((map -> frames % 25000) == 0)
			ft_victory_screen(map);
	}
	return ;
}
