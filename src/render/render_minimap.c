/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:43:34 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/15 19:09:54 by minseok2         ###   ########.fr       */
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

void	place_player(t_vars *vars)
{
	const int	x_offset = vars->player.x * TILE_SIZE;
	const int	y_offset = vars->player.y * TILE_SIZE;
	int			x;
	int			y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			ft_pixel_put(&vars->minimap.img, x_offset + x, y_offset + y, PLAYER_COLOR);
			y++;
		}
		x++;
	}
}

void	draw_rect(t_image *image, int w, int h, unsigned int color)
{
	const int	w_offset = w * TILE_SIZE;
	const int	h_offset = h * TILE_SIZE;
	int			i;
	int			j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			ft_pixel_put(image, w_offset + i, h_offset + j, color);
			j++;
		}
		i++;
	}
}

void	place_wall(t_vars *vars)
{
	int	w;
	int	h;

	h = 0;
	while (h < vars->map_height)
	{
		w = 0;
		while (w < vars->map_width)
		{
			if (vars->map_elem[h][w] == WALL)
				draw_rect(&vars->minimap.background_img, w, h, WALL_COLOR);
			w++;
		}
		h++;
	}
}

void	render_minimap(t_vars *vars)
{
	ft_memcpy(vars->minimap.img.img_ptr, vars->minimap.background_img.img_ptr, sizeof(int) * vars->minimap.w_size * vars->minimap.h_size);
	place_player(vars);
	raycast(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->minimap.img.img, MINIMAP_XOFFSET, MINIMAP_YOFFSET);
}
