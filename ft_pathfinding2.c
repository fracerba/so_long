/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinding2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:25:38 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/23 15:25:42 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player_path(t_check_path *path, char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j] && copy[i][j] != '\n')
		{
			if (copy[i][j] == 'P')
			{
				path -> player_x = i;
				path -> player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_path(t_check_path *path, char **copy)
{
	path -> score = 0;
	path -> threes = 0;
	path -> exit_reached = 0;
	path -> valid = 0;
	ft_find_player_path(path, copy);
}

void	ft_set_threes(t_check_path *path, char **copy, int i, int j)
{
	if (copy[i][j] == '0' || copy[i][j] == 'C')
	{
		if (copy[i][j] == 'C')
			path -> score++;
		copy[i][j] = '3';
		path -> threes++;
	}
	else if (copy[i][j] == 'E')
		path -> exit_reached = 1;
}

void	ft_next_move(t_check_path *path, char **copy, int i, int j)
{
	ft_set_threes(path, copy, i - 1, j);
	ft_set_threes(path, copy, i + 1, j);
	ft_set_threes(path, copy, i, j - 1);
	ft_set_threes(path, copy, i, j + 1);
	if (copy[i][j] == '3')
	{
		copy[i][j] = '2';
		path -> threes--;
	}
}

void	ft_check_check(t_check_path *path, t_map *map)
{
	int	c;
	int	s;

	s = path -> score;
	c = map -> check.collectible;
	if (path -> exit_reached == 1 && s == c)
		path -> valid = 1;
}
