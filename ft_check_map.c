/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:00:13 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/15 11:00:17 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_char(char **buffer, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j] && buffer[i][j] != '\n')
		{
			if (!ft_char_error(buffer[i][j], map))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_various(t_map *map)
{
	if (map -> check.player != 1 || map -> check.exit != 1)
	{
		ft_printf("Error\n");
		ft_printf("La mappa passata e' invalida");
		return (0);
	}
	else if (map -> check.collectible < 1)
	{
		ft_printf("Error\n");
		ft_printf("La mappa passata e' invalida");
		return (0);
	}
	return (1);
}

int	ft_check_shape(char **buffer, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		j = ft_strlen(buffer[i]) - 1;
		if (j != map -> check.lenght)
		{
			ft_printf("Error\n");
			ft_printf("La mappa non e' rettangolare");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_walls(char **buffer)
{
	int	i;
	int	j;

	j = 0;
	while (buffer[0][j] != '\n' && buffer[0][j])
	{
		if (!ft_wall_error(buffer[0][j]))
			return (0);
		j++;
	}
	j--;
	i = 0;
	while (buffer[i])
	{
		if (!ft_wall_error(buffer[i][0]) || !ft_wall_error(buffer[i][j]))
			return (0);
		i++;
	}
	i--;
	if (!ft_check_walls_extra(buffer[i]))
		return (0);
	return (1);
}

int	ft_check_map(int argc, char *argv, t_map *map)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		ft_printf("Nessuna mappa passata");
		return (0);
	}
	if (!ft_check_file(argv))
		return (0);
	ft_check_init(map);
	map -> map_buffer = ft_map_fill(argv, map);
	map -> check.valid = 1;
	if (!ft_check_char(map -> map_buffer, map))
		return (0);
	if (!ft_check_various(map))
		return (0);
	if (!ft_check_shape(map -> map_buffer, map))
		return (0);
	if (!ft_check_walls(map -> map_buffer))
		return (0);
	if (!ft_check_path(map -> map_buffer, map))
		return (0);
	return (1);
}
