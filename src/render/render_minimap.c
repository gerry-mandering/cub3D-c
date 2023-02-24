/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:43:34 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/24 13:27:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	place_wall(t_vars *vars)
{
	t_ivec	offset;
	int		x;
	int		y;

	y = 0;
	while (y < vars->map_size.y)
	{
		x = 0;
		while (x < vars->map_size.x)
		{
			offset.x = x * TILE_SIZE;
			offset.y = y * TILE_SIZE;
			if (vars->map[y][x] == WALL)
				draw_rect(&vars->minimap.background_img, \
					offset, TILE_SIZE, WALL_COLOR);
			else
				draw_rect(&vars->minimap.background_img, \
					offset, TILE_SIZE, 0x5f0f0f0f);
			x++;
		}
		y++;
	}
}

void	place_player(t_vars *vars)
{
	t_ivec	offset;

	offset.x = (int)(vars->player_pos.x * TILE_SIZE) - PLAYER_SIZE / 2;
	offset.y = (int)(vars->player_pos.y * TILE_SIZE) - PLAYER_SIZE / 2;
	draw_rect(&vars->minimap.img, offset, PLAYER_SIZE, PLAYER_COLOR);
}

t_ivec	get_crop_offset(t_vars *vars)
{
	t_ivec	player;
	t_ivec	offset;

	player.x = (int)vars->player_pos.x * TILE_SIZE;
	player.y = (int)vars->player_pos.y * TILE_SIZE;
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
	t_ivec			index;

	offset = get_crop_offset(vars);
	index.y = 0;
	while (index.y < vars->minimap.crop.height)
	{
		index.x = 0;
		while (index.x < vars->minimap.crop.width)
		{
			pos.x = offset.x + index.x;
			pos.y = offset.y + index.y;
			color = get_color_value(&vars->minimap.img, pos);
			put_pixel(&vars->minimap.crop, index.x, index.y, color);
			index.x++;
		}
		index.y++;
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
