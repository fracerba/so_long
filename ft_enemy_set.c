/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:56:31 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/13 12:56:34 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_space(char **buffer, int i, int j)
{
	int	spaces;

	spaces = 0;
	if (buffer[i - 1][j] == 'P' || buffer[i + 1][j] == 'P')
		return (0);
	if (buffer[i][j - 1] == 'P' || buffer[i][j + 1] == 'P')
		return (0);
	if (buffer[i - 1][j] == '0')
		spaces++;
	if (buffer[i + 1][j] == '0')
		spaces++;
	if (buffer[i][j - 1] == '0')
		spaces++;
	if (buffer[i][j + 1] == '0')
		spaces++;
	return (spaces);
}

void	ft_spawn_enemy(t_map *map, char **buffer)
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
			{
				if (ft_check_space(buffer, i, j) > 2)
					buffer[i][j] = 'X';
			}
			if (buffer[i][j] == 'X')
			{
				map -> e_true = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}
