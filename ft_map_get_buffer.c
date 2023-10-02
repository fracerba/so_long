/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:59:44 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/09 12:59:45 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_map_size(char *argv)
{
	char	*s;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	s = NULL;
	while (i == 0 || s)
	{
		if (s)
			free(s);
		s = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**ft_map_fill(char *argv, t_map *map)
{
	char	**buffer;
	char	*s;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		ft_file_error_2();
	i = ft_get_map_size(argv);
	if (i == 1)
		ft_map_error();
	buffer = malloc(sizeof(char *) * i);
	i = 0;
	while (i == 0 || s)
	{
		s = get_next_line(fd);
		buffer[i] = s;
		i++;
	}
	map -> check.height = i - 1;
	map -> check.lenght = ft_strlen(buffer[0]) - 1;
	close(fd);
	if (map -> check.height < 3 || map -> check.lenght < 3)
		ft_map_error_2(buffer);
	return (buffer);
}

void	ft_free_map(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
