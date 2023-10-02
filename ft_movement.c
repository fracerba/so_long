/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:02:55 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/10 13:02:57 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_map *map, char **buffer, int x, int y)
{
	if (buffer[x - 1][y] != '1' && buffer[x - 1][y] != 'E')
	{
		if (buffer[x - 1][y] == 'V')
		{
			map -> ending = 1;
			map -> player.steps++;
			return ;
		}
		else if (buffer[x - 1][y] == 'X')
		{
			map -> ending = -1;
			return ;
		}
		else if (buffer[x - 1][y] == 'C')
		{
			map -> score++;
			if (map -> score == map -> check.collectible)
				ft_unlock_exit(map, map -> map_buffer);
		}
		buffer[x - 1][y] = 'P';
		buffer[x][y] = '0';
		map -> player.x--;
		map -> player.steps++;
	}
}

void	ft_move_down(t_map *map, char **buffer, int x, int y)
{
	if (buffer[x + 1][y] != '1' && buffer[x + 1][y] != 'E')
	{
		if (buffer[x + 1][y] == 'V')
		{
			map -> ending = 1;
			map -> player.steps++;
			return ;
		}
		else if (buffer[x + 1][y] == 'X')
		{
			map -> ending = -1;
			return ;
		}
		else if (buffer[x + 1][y] == 'C')
		{
			map -> score++;
			if (map -> score == map -> check.collectible)
				ft_unlock_exit(map, map -> map_buffer);
		}
		buffer[x + 1][y] = 'P';
		buffer[x][y] = '0';
		map -> player.x++;
		map -> player.steps++;
	}
}

void	ft_move_left(t_map *map, char **buffer, int x, int y)
{
	map -> player.flip = 1;
	if (buffer[x][y - 1] != '1' && buffer[x][y - 1] != 'E')
	{
		if (buffer[x][y - 1] == 'V')
		{
			map -> ending = 1;
			map -> player.steps++;
			return ;
		}
		else if (buffer[x][y - 1] == 'X')
		{
			map -> ending = -1;
			return ;
		}
		else if (buffer[x][y - 1] == 'C')
		{
			map -> score++;
			if (map -> score == map -> check.collectible)
				ft_unlock_exit(map, map -> map_buffer);
		}
		buffer[x][y - 1] = 'P';
		buffer[x][y] = '0';
		map -> player.y--;
		map -> player.steps++;
	}
}

void	ft_move_right(t_map *map, char **buffer, int x, int y)
{
	map -> player.flip = 0;
	if (buffer[x][y + 1] != '1' && buffer[x][y + 1] != 'E')
	{
		if (buffer[x][y + 1] == 'V')
		{
			map -> ending = 1;
			map -> player.steps++;
			return ;
		}
		else if (buffer[x][y + 1] == 'X')
		{
			map -> ending = -1;
			return ;
		}
		else if (buffer[x][y + 1] == 'C')
		{
			map -> score++;
			if (map -> score == map -> check.collectible)
				ft_unlock_exit(map, map -> map_buffer);
		}
		buffer[x][y + 1] = 'P';
		buffer[x][y] = '0';
		map -> player.y++;
		map -> player.steps++;
	}
}

int	ft_move(int key, t_map *map)
{
	if (key == 65307)
		ft_close(map);
	ft_find_player(map, map -> map_buffer);
	if ((key == 100 || key == 65363) && map -> ending == 0)
		ft_move_right(map, map -> map_buffer, map -> player.x, map -> player.y);
	else if ((key == 97 || key == 65361) && map -> ending == 0)
		ft_move_left(map, map -> map_buffer, map -> player.x, map -> player.y);
	else if ((key == 115 || key == 65364) && map -> ending == 0)
		ft_move_down(map, map -> map_buffer, map -> player.x, map -> player.y);
	else if ((key == 119 || key == 65362) && map -> ending == 0)
		ft_move_up(map, map -> map_buffer, map -> player.x, map -> player.y);
	return (0);
}
