/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:43:34 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/22 02:38:09 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	add_ray_to_minimap(t_vars *vars, t_ray *ray)
{
	t_ivec	offset;

	offset.x = ray->intersection.x * TILE_SIZE;
	offset.y = ray->intersection.y * TILE_SIZE;
	draw_rect(&vars->minimap.img, offset, 2, 0xff);
}

void	place_wall(t_vars *vars)
{
	t_ivec	offset;
	int		x;
	int		y;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			offset.x = x * TILE_SIZE;
			offset.y = y * TILE_SIZE;
			if (vars->map_elem[y][x] == WALL)
				draw_rect(&vars->minimap.background_img, \
					offset, TILE_SIZE, WALL_COLOR);
			else
				draw_rect(&vars->minimap.background_img, \
					offset, TILE_SIZE, 0x5f0f0f0f);
			if (vars->map_elem[y][x] == OBJECT)
				draw_rect(&vars->minimap.background_img, \
					offset, TILE_SIZE, 0xffd400);
			x++;
		}
		y++;
	}
}

void	place_player(t_vars *vars)
{
	t_ivec	offset;

	offset.x = (int)(vars->player.x * TILE_SIZE) - PLAYER_SIZE / 2;
	offset.y = (int)(vars->player.y * TILE_SIZE) - PLAYER_SIZE / 2;
	draw_rect(&vars->minimap.img, offset, PLAYER_SIZE, PLAYER_COLOR);
}

void	render_minimap(t_vars *vars)
{
	
}

// void	render_minimap(t_vars *vars)
// {
// 	ft_memcpy(vars->minimap.img.img_ptr, \
// 		vars->minimap.background_img.img_ptr, \
// 		sizeof(int) * vars->minimap.w_size * vars->minimap.h_size);
// 	place_player(vars);
// }
