/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/14 21:31:09 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	raycast(t_vars *vars)
{
	// mlx = 0;
	// double	dir = map_data->player_position.direction;
	// double	startX = map_data->player_position.col;
	// double	startY = map_data->player_position.row;
	// double	dx = cos(dir);
	// double	dy = sin(dir);
	// double	unitStepX = sqrt(1 + (dy / dx) * (dy / dx));
	// double	unitStepY = sqrt(1 + (dx / dy) * (dx / dy));
	// int		mapX = (int)startX;
	// int		mapY = (int)startY;
	// double	stepX;
	// double	stepY;
	// double	lengthX;
	// double	lengthY;

	// if (dx < 0)
	// {
	// 	stepX = -1;
	// 	lengthX = (startX - (float)mapX) * unitStepX;
	// }
	// else
	// {
	// 	stepX = 1;
	// 	lengthX = ((float)(mapX + 1) - startX) * unitStepX;
	// }
	// if (dy < 0)
	// {
	// 	stepY = -1;
	// 	lengthY = (startY - (float)mapY) * unitStepY;
	// }
	// else
	// {
	// 	stepY = 1;
	// 	lengthY = ((float)(mapY + 1) - startY) * unitStepY;
	// }
	// int		hit = 0;
	// double	max_dist = 100;
	// double	dist = 0;
	// while (!hit && dist < max_dist)
	// {
	// 	if (lengthX < lengthY)
	// 	{
	// 		mapX += stepX;
	// 		dist += lengthX;
	// 		lengthX += unitStepX;
	// 	}
	// 	else
	// 	{
	// 		mapY += stepY;
	// 		dist += lengthY;
	// 		lengthY += unitStepY;
	// 	}
	// 	if (0 <= mapX && mapX < map_data->size.col && 0 <= mapY && mapY < map_data->size.row)
	// 	{
	// 		if (map_data->map[mapY][mapX] == 1)
	// 		{
	// 			hit = 1;
	// 		}
	// 	}
	// }
	// double	interX = 0;
	// double	interY = 0;
	// if (hit)
	// {
	// 	interX = startX + (dx * dist);
	// 	interY = startY + (dy * dist);
	// 	//printf("%f, %f\n", interX, interY);
	// 	ft_pixel_put(&map_data->minimap.minimap_img, interX * TILE_SIZE, interY * TILE_SIZE, 0xff);
	// }
	// t_coord	from;
	// t_coord	to;
	// from.col = (startX * TILE_SIZE) + 5;
	// from.row = (startY * TILE_SIZE) + 5;
	// to.col = (interX * TILE_SIZE);
	// to.row = (interY * TILE_SIZE);
	// draw_line(&map_data->minimap.minimap_img, from, to);
	vars = 0;
}
