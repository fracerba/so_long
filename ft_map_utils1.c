/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:11:40 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/20 09:15:38 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_error(void)
{
	ft_printf("Error\n");
	ft_printf("Il file passato non e' un file \".ber\"");
	return (0);
}

int	ft_check_file(char *argv)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = ".ber";
	while (argv[i] != '\0')
		i++;
	if (i < 4)
	{
		ft_file_error();
		return (0);
	}
	while (argv[i - 4 + j] != '\0' && i >= 4)
	{
		if (argv[i - 4 + j] != s[j])
		{
			ft_file_error();
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_char_error(char buffer, t_map *map)
{
	if (buffer == 'P')
		map -> check.player++;
	else if (buffer == 'E')
		map -> check.exit++;
	else if (buffer == '0')
		map -> check.space++;
	else if (buffer == '1')
		map -> check.wall++;
	else if (buffer == 'C')
		map -> check.collectible++;
	else
	{		
		ft_printf("Error\n");
		ft_printf("La mappa presenta caratteri non validi");
		return (0);
	}
	return (1);
}

int	ft_wall_error(char buffer)
{
	if (buffer != '1')
	{
		ft_printf("Error\n");
		ft_printf("La mappa non e' chiusa da muri");
		return (0);
	}
	return (1);
}

int	ft_check_walls_extra(char *buffer)
{
	int	j;

	j = 0;
	while (buffer[j] != '\n')
	{
		if (!ft_wall_error(buffer[j]))
			return (0);
		j++;
	}
	return (1);
}
