/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:43:34 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/15 21:52:03 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	offset = (y * img->size_line + x * (img->bits_per_pixel / 8));
	dst = img->img_ptr + offset;
	*(unsigned int *)dst = color;
}

void	draw_rect(t_image *image, t_ivec offset, int size, unsigned int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_pixel_put(image, offset.x + x, offset.y + y, color);
			x++;
		}
		y++;
	}
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
				draw_rect(&vars->minimap.background_img, offset, TILE_SIZE, WALL_COLOR);
			x++;
		}
		y++;
	}
}

void	place_player(t_vars *vars)
{
	t_ivec	offset;

	offset.x = (int)(vars->player.x * TILE_SIZE);
	offset.y = (int)(vars->player.y * TILE_SIZE);
	draw_rect(&vars->minimap.img, offset, PLAYER_SIZE, PLAYER_COLOR);
}

void	render_minimap(t_vars *vars)
{
	ft_memcpy(vars->minimap.img.img_ptr, vars->minimap.background_img.img_ptr, sizeof(int) * vars->minimap.w_size * vars->minimap.h_size);
	place_player(vars);
	FOV(vars);
}
