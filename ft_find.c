/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:54:16 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/13 10:54:19 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_map *map, char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j] && buffer[i][j] != '\n')
		{
			if (buffer[i][j] == 'P')
			{
				map -> player.x = i;
				map -> player.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_find_enemy(t_map *map, char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j] && buffer[i][j] != '\n')
		{
			if (buffer[i][j] == 'X')
			{
				map -> enemy.x = i;
				map -> enemy.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_find_exit(t_map *map, char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j] && buffer[i][j] != '\n')
		{
			if (buffer[i][j] == 'E' || buffer[i][j] == 'V')
			{
				map -> exit_x = i;
				map -> exit_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
