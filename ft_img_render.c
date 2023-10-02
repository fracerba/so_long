/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:00:01 by fracerba          #+#    #+#             */
/*   Updated: 2023/01/13 12:50:44 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_map *m, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(m->mlx, path, &img->lenght, &img->height);
	if (!img -> img)
		ft_close(m);
	img->path = mlx_get_data_addr(img->img, &img->bits, &img->line, &img->end);
}

void	set_img_enemy(t_map *map)
{
	get_img(map, &map->enemy.imgs[0], "./Textures/Enemy/SkeletonRogueL1.xpm");
	get_img(map, &map->enemy.imgs[1], "./Textures/Enemy/SkeletonRogueL2.xpm");
	get_img(map, &map->enemy.imgs[2], "./Textures/Enemy/SkeletonRogueL3.xpm");
	get_img(map, &map->enemy.imgs[3], "./Textures/Enemy/SkeletonRogueL4.xpm");
	get_img(map, &map->enemy.imgs[4], "./Textures/Enemy/SkeletonRogueR1.xpm");
	get_img(map, &map->enemy.imgs[5], "./Textures/Enemy/SkeletonRogueR2.xpm");
	get_img(map, &map->enemy.imgs[6], "./Textures/Enemy/SkeletonRogueR3.xpm");
	get_img(map, &map->enemy.imgs[7], "./Textures/Enemy/SkeletonRogueR4.xpm");
	get_img(map, &map->enemy.imgs[8], "./Textures/Enemy/SkeletonRogueDL1.xpm");
	get_img(map, &map->enemy.imgs[9], "./Textures/Enemy/SkeletonRogueDL2.xpm");
	get_img(map, &map->enemy.imgs[10], "./Textures/Enemy/SkeletonRogueDL3.xpm");
	get_img(map, &map->enemy.imgs[11], "./Textures/Enemy/SkeletonRogueDL4.xpm");
	get_img(map, &map->enemy.imgs[12], "./Textures/Enemy/SkeletonRogueDL5.xpm");
	get_img(map, &map->enemy.imgs[13], "./Textures/Enemy/SkeletonRogueDL6.xpm");
	get_img(map, &map->enemy.imgs[14], "./Textures/Enemy/SkeletonRogueDR1.xpm");
	get_img(map, &map->enemy.imgs[15], "./Textures/Enemy/SkeletonRogueDR2.xpm");
	get_img(map, &map->enemy.imgs[16], "./Textures/Enemy/SkeletonRogueDR3.xpm");
	get_img(map, &map->enemy.imgs[17], "./Textures/Enemy/SkeletonRogueDR4.xpm");
	get_img(map, &map->enemy.imgs[18], "./Textures/Enemy/SkeletonRogueDR5.xpm");
	get_img(map, &map->enemy.imgs[19], "./Textures/Enemy/SkeletonRogueDR6.xpm");
}

void	set_player_knight(t_map *map)
{
	get_img(map, &map -> player.imgs[0], "./Textures/Player/KnightL1.xpm");
	get_img(map, &map -> player.imgs[1], "./Textures/Player/KnightL2.xpm");
	get_img(map, &map -> player.imgs[2], "./Textures/Player/KnightL3.xpm");
	get_img(map, &map -> player.imgs[3], "./Textures/Player/KnightL4.xpm");
	get_img(map, &map -> player.imgs[4], "./Textures/Player/KnightR1.xpm");
	get_img(map, &map -> player.imgs[5], "./Textures/Player/KnightR2.xpm");
	get_img(map, &map -> player.imgs[6], "./Textures/Player/KnightR3.xpm");
	get_img(map, &map -> player.imgs[7], "./Textures/Player/KnightR4.xpm");
	get_img(map, &map -> player.imgs[8], "./Textures/Player/KnightDL1.xpm");
	get_img(map, &map -> player.imgs[9], "./Textures/Player/KnightDL2.xpm");
	get_img(map, &map -> player.imgs[10], "./Textures/Player/KnightDL3.xpm");
	get_img(map, &map -> player.imgs[11], "./Textures/Player/KnightDL4.xpm");
	get_img(map, &map -> player.imgs[12], "./Textures/Player/KnightDL5.xpm");
	get_img(map, &map -> player.imgs[13], "./Textures/Player/KnightDL6.xpm");
	get_img(map, &map -> player.imgs[14], "./Textures/Player/KnightDR1.xpm");
	get_img(map, &map -> player.imgs[15], "./Textures/Player/KnightDR2.xpm");
	get_img(map, &map -> player.imgs[16], "./Textures/Player/KnightDR3.xpm");
	get_img(map, &map -> player.imgs[17], "./Textures/Player/KnightDR4.xpm");
	get_img(map, &map -> player.imgs[18], "./Textures/Player/KnightDR5.xpm");
	get_img(map, &map -> player.imgs[19], "./Textures/Player/KnightDR6.xpm");
}

void	set_player_rogue(t_map *map)
{
	get_img(map, &map -> player.imgs[0], "./Textures/Player/RogueL1.xpm");
	get_img(map, &map -> player.imgs[1], "./Textures/Player/RogueL2.xpm");
	get_img(map, &map -> player.imgs[2], "./Textures/Player/RogueL3.xpm");
	get_img(map, &map -> player.imgs[3], "./Textures/Player/RogueL4.xpm");
	get_img(map, &map -> player.imgs[4], "./Textures/Player/RogueR1.xpm");
	get_img(map, &map -> player.imgs[5], "./Textures/Player/RogueR2.xpm");
	get_img(map, &map -> player.imgs[6], "./Textures/Player/RogueR3.xpm");
	get_img(map, &map -> player.imgs[7], "./Textures/Player/RogueR4.xpm");
	get_img(map, &map -> player.imgs[8], "./Textures/Player/RogueDL1.xpm");
	get_img(map, &map -> player.imgs[9], "./Textures/Player/RogueDL2.xpm");
	get_img(map, &map -> player.imgs[10], "./Textures/Player/RogueDL3.xpm");
	get_img(map, &map -> player.imgs[11], "./Textures/Player/RogueDL4.xpm");
	get_img(map, &map -> player.imgs[12], "./Textures/Player/RogueDL5.xpm");
	get_img(map, &map -> player.imgs[13], "./Textures/Player/RogueDL6.xpm");
	get_img(map, &map -> player.imgs[14], "./Textures/Player/RogueDR1.xpm");
	get_img(map, &map -> player.imgs[15], "./Textures/Player/RogueDR2.xpm");
	get_img(map, &map -> player.imgs[16], "./Textures/Player/RogueDR3.xpm");
	get_img(map, &map -> player.imgs[17], "./Textures/Player/RogueDR4.xpm");
	get_img(map, &map -> player.imgs[18], "./Textures/Player/RogueDR5.xpm");
	get_img(map, &map -> player.imgs[19], "./Textures/Player/RogueDR6.xpm");
}

void	set_imgs(t_map *map, char *argv)
{
	get_img(map, &map -> wall[0], "./Textures/Environment/Wall_UL.xpm");
	get_img(map, &map -> wall[1], "./Textures/Environment/Wall_UR.xpm");
	get_img(map, &map -> wall[2], "./Textures/Environment/Wall_DL.xpm");
	get_img(map, &map -> wall[3], "./Textures/Environment/Wall_DR.xpm");
	get_img(map, &map -> wall[4], "./Textures/Environment/Wall_U.xpm");
	get_img(map, &map -> wall[5], "./Textures/Environment/Wall_L.xpm");
	get_img(map, &map -> wall[6], "./Textures/Environment/Wall_R.xpm");
	get_img(map, &map -> wall[7], "./Textures/Environment/Wall_D.xpm");
	get_img(map, &map -> floor, "./Textures/Environment/Floor.xpm");
	get_img(map, &map -> box, "./Textures/Environment/Box.xpm");
	get_img(map, &map -> key, "./Textures/Environment/Key.xpm");
	get_img(map, &map -> exit_closed, "./Textures/Environment/Exit_closed.xpm");
	get_img(map, &map -> exit_open, "./Textures/Environment/Exit_open.xpm");
	set_img_enemy(map);
	if (!argv || ft_strncmp(argv, "2", 1))
		set_player_knight(map);
	else if (ft_strncmp(argv, "2", 1) == 0)
		set_player_rogue(map);
}
