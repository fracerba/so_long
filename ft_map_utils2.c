/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:34:18 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/20 10:34:21 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_error_2(void)
{
	ft_printf("Error\n");
	ft_printf("Il file passato non esiste");
	exit(0);
}

void	ft_map_error(void)
{
	ft_printf("Error\n");
	ft_printf("La mappa passata e' vuota");
	exit(0);
}

void	ft_map_error_2(char **buffer)
{
	ft_free_map(buffer);
	ft_printf("Error\n");
	ft_printf("La mappa passata e' assurda");
	exit(0);
}

void	ft_check_init(t_map *map)
{
	map -> check.space = 0;
	map -> check.wall = 0;
	map -> check.collectible = 0;
	map -> check.player = 0;
	map -> check.exit = 0;
	map -> check.height = 0;
	map -> check.lenght = 0;
}
