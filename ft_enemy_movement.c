/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:51:39 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/13 12:51:40 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_up(t_map *map, char **buffer, int x, int y)
{
	if (buffer[x - 1][y] == '0' || buffer[x - 1][y] == 'P')
	{
		if (buffer[x - 1][y] == 'P')
		{
			map -> ending = -1;
			return ;
		}
		buffer[x - 1][y] = 'X';
		buffer[x][y] = '0';
		map -> enemy.x--;
		map -> enemy.steps++;
	}
}

void	ft_enemy_down(t_map *map, char **buffer, int x, int y)
{
	if (buffer[x + 1][y] == '0' || buffer[x + 1][y] == 'P')
	{
		if (buffer[x + 1][y] == 'P')
		{
			map -> ending = -1;
			return ;
		}
		buffer[x + 1][y] = 'X';
		buffer[x][y] = '0';
		map -> enemy.x++;
		map -> enemy.steps++;
	}
}

void	ft_enemy_left(t_map *map, char **buffer, int x, int y)
{
	if (buffer[x][y - 1] == '0' || buffer[x][y - 1] == 'P')
	{
		map -> enemy.flip = 1;
		if (buffer[x][y - 1] == 'P')
		{
			map -> ending = -1;
			return ;
		}
		buffer[x][y - 1] = 'X';
		buffer[x][y] = '0';
		map -> enemy.y--;
		map -> enemy.steps++;
	}
}

void	ft_enemy_right(t_map *map, char **buffer, int x, int y)
{
	if (buffer[x][y + 1] == '0' || buffer[x][y + 1] == 'P')
	{
		map -> enemy.flip = 0;
		if (buffer[x][y + 1] == 'P')
		{
			map -> ending = -1;
			return ;
		}
		buffer[x][y + 1] = 'X';
		buffer[x][y] = '0';
		map -> enemy.y++;
		map -> enemy.steps++;
	}
}

void	ft_move_enemy(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = map -> enemy.steps;
	ft_find_enemy(map, map -> map_buffer);
	x = map -> enemy.x;
	y = map -> enemy.y;
	while (j == map -> enemy.steps && map -> ending == 0)
	{
		i = rand() % 4;
		if (i == 0)
			ft_enemy_right(map, map -> map_buffer, x, y);
		else if (i == 1)
			ft_enemy_left(map, map -> map_buffer, x, y);
		else if (i == 2)
			ft_enemy_down(map, map -> map_buffer, x, y);
		else if (i == 3)
			ft_enemy_up(map, map -> map_buffer, x, y);
	}
}
