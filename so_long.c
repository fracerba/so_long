/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:23:02 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/15 10:23:04 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_imgs_ent(t_map *map)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (map -> player.imgs[i].img)
			mlx_destroy_image(map -> mlx, map -> player.imgs[i].img);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		if (map -> enemy.imgs[i].img)
			mlx_destroy_image(map -> mlx, map -> enemy.imgs[i].img);
		i++;
	}
	return ;
}

void	ft_destroy_imgs(t_map *map)
{
	int	i;

	if (map -> floor.img)
		mlx_destroy_image(map -> mlx, map -> floor.img);
	if (map -> box.img)
		mlx_destroy_image(map -> mlx, map -> box.img);
	if (map -> key.img)
		mlx_destroy_image(map -> mlx, map -> key.img);
	if (map -> exit_closed.img)
		mlx_destroy_image(map -> mlx, map -> exit_closed.img);
	if (map -> exit_open.img)
		mlx_destroy_image(map -> mlx, map -> exit_open.img);
	i = 0;
	while (i < 8)
	{
		if (map -> wall[i].img)
			mlx_destroy_image(map -> mlx, map -> wall[i].img);
		i++;
	}
	ft_destroy_imgs_ent(map);
	return ;
}

int	ft_close(t_map *map)
{
	if (map -> check.valid == 1)
		ft_free_map(map -> map_buffer);
	if (map -> mlx)
	{
		ft_destroy_imgs(map);
		if (map -> window)
			mlx_destroy_window(map -> mlx, map -> window);
		mlx_destroy_display(map -> mlx);
		free(map -> mlx);
	}
	exit(0);
}

void	ft_map_init(t_map *map)
{
	map -> mlx = mlx_init();
	map -> frames = 0;
	map -> score = 0;
	map -> e_true = 0;
	map -> ending = 0;
	ft_find_exit(map, map -> map_buffer);
	ft_find_player(map, map -> map_buffer);
	map -> player.flip = 0;
	map -> enemy.flip = 0;
	map -> player.steps = 0;
	map -> enemy.steps = 0;
	map -> player.death = 0;
	map -> enemy.death = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (!ft_check_map(argc, argv[1], &map))
		ft_close(&map);
	ft_map_init(&map);
	if (!(map.mlx))
		ft_close(&map);
	set_imgs(&map, argv[2]);
	map.window = mlx_new_window(map.mlx, map.check.lenght * 64,
			map.check.height * 64, "In the Court of the Crimson King");
	if (!map.window)
		ft_close(&map);
	ft_spawn_enemy(&map, map.map_buffer);
	mlx_hook(map.window, 3, 1L << 1, ft_move, &map);
	mlx_hook(map.window, 17, 0, ft_close, &map);
	mlx_loop_hook(map.mlx, ft_frame_render, &map);
	mlx_loop(map.mlx);
	ft_close(&map);
	return (0);
}
