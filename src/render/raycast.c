/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/16 13:25:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	raycast(t_vars *vars, double ray_dir)
{
	t_dvec	ray_start;
	t_dvec	ray_length;
	t_dvec	unit_step_size;
	t_ivec	step;
	t_ivec	map_check;
	double	dx = cos(ray_dir);
	double	dy = sin(ray_dir);

	ray_start.x = vars->player.x;
	ray_start.y = vars->player.y;
	map_check.x = (int)ray_start.x;
	map_check.y = (int)ray_start.y;
	unit_step_size.x = sqrt(1 + (dy / dx) * (dy / dx));
	unit_step_size.y = sqrt(1 + (dx / dy) * (dx / dy));
	//printf("ray_dir: %f, dx: %f, dy: %f\n",ray_dir, dx, dy);
	if (dx < 0)
	{
		step.x = -1;
		ray_length.x = (ray_start.x - map_check.x) * unit_step_size.x;
	}
	else
	{
		step.x = 1;
		ray_length.x = (map_check.x + 1 - ray_start.x) * unit_step_size.x;
	}
	if (dy < 0)
	{
		step.y = -1;
		ray_length.y = (ray_start.y - map_check.y) * unit_step_size.y;
	}
	else
	{
		step.y = 1;
		ray_length.y = (map_check.y + 1 - ray_start.y) * unit_step_size.y;
	}
	int		hit = 0;
	double	dist = 0;
	//double	max_dist = 100;
	while (!hit)
	{
		if (ray_length.x < ray_length.y)
		{
			map_check.x += step.x;
			dist = ray_length.x;
			ray_length.x += unit_step_size.x;
		}
		else
		{
			map_check.y += step.y;
			dist = ray_length.y;
			ray_length.y += unit_step_size.y;
		}
		if (map_check.x >= 0 && map_check.x < vars->map_width && map_check.y >= 0 && map_check.y < vars->map_height)
		{
			if (vars->map_elem[map_check.y][map_check.x] == WALL)
			{
				//printf("block: %d, %d dist:%f\n", map_check.x, map_check.y, dist);
				hit = 1;
			}
		}
	}
	t_dvec	inter;
	inter.x = (ray_start.x + dx * dist);
	inter.y = (ray_start.y + dy * dist);
	//printf("start x:%f, y:%f hit x:%f, y:%f\n", ray_start.x, ray_start.y, inter.x, inter.y);
	t_ivec	offset;
	offset.x = inter.x * TILE_SIZE;
	offset.y = inter.y * TILE_SIZE;
	draw_rect(&vars->minimap.img, offset, 2, 0xff);
}

void	FOV(t_vars *vars)
{
	double	interval;
	double	start;
	double	end;

	interval = FOV_ANGLE / NUMBER_OF_RAYS;
	start = vars->viewing_angle - FOV_ANGLE / 2;
	end = start + FOV_ANGLE;
	while (start < end)
	{
		raycast(vars, start);
		start += interval;
	}
}
