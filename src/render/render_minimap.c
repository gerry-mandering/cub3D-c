/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:43:34 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/23 16:05:07 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

t_ivec	get_crop_offset(t_vars *vars)
{
	t_ivec	player;
	t_ivec	offset;

	player.x = (int)vars->player.x * TILE_SIZE;
	player.y = (int)vars->player.y * TILE_SIZE;
	offset.x = player.x - W_SIZE / 8;
	offset.y = player.y - H_SIZE / 8;
	if (offset.x < 0)
		offset.x = 0;
	else if (player.x + W_SIZE / 8 >= vars->minimap.w_size)
		offset.x = vars->minimap.w_size - W_SIZE / 4;
	if (offset.y < 0)
		offset.y = 0;
	else if (player.y + H_SIZE / 8 >= vars->minimap.h_size)
		offset.y = vars->minimap.h_size - H_SIZE / 4;
	return (offset);
}

void	crop_minimap(t_vars *vars)
{
	t_ivec			offset;
	t_ivec			pos;
	unsigned int	color;
	int				x;
	int				y;

	offset = get_crop_offset(vars);
	y = 0;
	while (y < vars->minimap.crop.height)
	{
		x = 0;
		while (x < vars->minimap.crop.width)
		{
			pos.x = offset.x + x;
			pos.y = offset.y + y;
			color = get_color_value(&vars->minimap.img, pos);
			ft_pixel_put(&vars->minimap.crop, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_vars *vars)
{
	ft_memcpy(vars->minimap.img.img_ptr, \
		vars->minimap.background_img.img_ptr, \
		sizeof(int) * vars->minimap.w_size * vars->minimap.h_size);
	place_player(vars);
	crop_minimap(vars);
}
