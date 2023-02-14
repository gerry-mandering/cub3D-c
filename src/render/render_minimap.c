/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:43:34 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/13 21:46:20 by jinholee         ###   ########.fr       */
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

void	place_player(t_image *img, int w, int h)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			ft_pixel_put(img, w + j, h + i, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}

void	place_wall(t_image	*img, int w, int h)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			ft_pixel_put(img, w + j, h + i, WALL_COLOR);
			j++;
		}
		i++;
	}
}

void	show_direction(t_map_data *map_data)
{
	t_coord	from;
	t_coord	to;

	from.row = map_data->player_position.row + 5;
	from.col = map_data->player_position.col + 5;
	to = from;
	to.col += 20 * cos(map_data->player_position.direction);
	to.row += 20 * sin(map_data->player_position.direction);
	draw_line(&map_data->minimap.minimap_img, from, to);
}

void	render_minimap(t_mlx *mlx, t_map_data *map_data)
{
	ft_memcpy(map_data->minimap.minimap_img.img_ptr, map_data->minimap.background_img.img_ptr, map_data->minimap.w_size * map_data->minimap.h_size * sizeof(int));
	place_player(&map_data->minimap.minimap_img, map_data->player_position.col, map_data->player_position.row);
	show_direction(map_data);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, map_data->minimap.minimap_img.img, 0, 0);
}
