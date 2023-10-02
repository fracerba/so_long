/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:47:55 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/23 11:47:56 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_path_error(char **copy)
{
	ft_free_map(copy);
	ft_printf("Error\n");
	ft_printf("La mappa e' impossibile, ");
	ft_printf("non si puo' raggiungere la fine");
	return (0);
}

int	ft_first_check_aux(char **copy, int i, int j)
{
	int	s;

	s = 0;
	if (copy[i - 1][j] != '1' && copy[i - 1][j] != 'E')
		s++;
	if (copy[i + 1][j] != '1' && copy[i + 1][j] != 'E')
		s++;
	if (copy[i][j - 1] != '1' && copy[i][j - 1] != 'E')
		s++;
	if (copy[i][j + 1] != '1' && copy[i][j + 1] != 'E')
		s++;
	if (s == 0)
		return (0);
	return (1);
}

int	ft_first_check(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j] && copy[i][j] != '\n')
		{
			if (copy[i][j] == 'P' || copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				if (!ft_first_check_aux(copy, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_real_check(char **copy, t_map *map, t_check_path *path)
{
	int		i;
	int		j;

	ft_init_path(path, copy);
	ft_next_move(path, copy, path -> player_x, path -> player_y);
	while (path -> threes != 0)
	{
		i = 0;
		while (copy[i])
		{
			j = 0;
			while (copy[i][j] && copy[i][j] != '\n')
			{
				if (copy[i][j] == '3')
					ft_next_move(path, copy, i, j);
				j++;
			}
			i++;
		}	
	}
	ft_check_check(path, map);
	if (path -> valid == 1)
		return (1);
	return (0);
}

int	ft_check_path(char **buffer, t_map *map)
{
	t_check_path	path;
	int				i;

	i = 0;
	path.copy = malloc(sizeof(char *) * (map -> check.height + 1));
	if (!path.copy)
		ft_close(map);
	while (buffer[i])
	{
		path.copy[i] = ft_strdup(buffer[i]);
		i++;
	}
	path.copy[i] = 0;
	if (!ft_first_check(path.copy))
		return (ft_path_error(path.copy));
	if (!ft_real_check(path.copy, map, &path))
		return (ft_path_error(path.copy));
	ft_free_map(path.copy);
	return (1);
}
