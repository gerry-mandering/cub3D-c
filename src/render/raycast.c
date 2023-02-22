/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/22 20:24:23 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h>

t_ray	init_ray(t_vars *vars, double ray_dir)
{
	t_ray	ray;

	ray.hit = 0;
	ray.dir = ray_dir;
	ray.start.x = vars->player.x;
	ray.start.y = vars->player.y;
	ray.map_check.x = (int)ray.start.x;
	ray.map_check.y = (int)ray.start.y;
	ray.delta.x = cos(ray_dir);
	ray.delta.y = sin(ray_dir);
	ray.step.x = (ray.delta.x >= 0) - (ray.delta.x < 0);
	ray.step.y = (ray.delta.y >= 0) - (ray.delta.y < 0);
	ray.unit_step.x = sqrt(1 + pow(ray.delta.y / ray.delta.x, 2));
	ray.unit_step.y = sqrt(1 + pow(ray.delta.x / ray.delta.y, 2));
	ray.length.x = (ray.map_check.x + 1 - ray.start.x) * ray.unit_step.x;
	ray.length.y = (ray.map_check.y + 1 - ray.start.y) * ray.unit_step.y;
	if (ray.delta.x < 0)
		ray.length.x = (ray.start.x - ray.map_check.x) * ray.unit_step.x;
	if (ray.delta.y < 0)
		ray.length.y = (ray.start.y - ray.map_check.y) * ray.unit_step.y;
	return (ray);
}

int	check_wall_hit(t_vars *vars, t_ray *ray, t_ray *object_ray)
{
	if (ray->map_check.x >= 0 && ray->map_check.x < vars->map_width \
		&& ray->map_check.y >= 0 && ray->map_check.y < vars->map_height)
	{
		if (vars->map_elem[ray->map_check.y][ray->map_check.x] == WALL)
			return (1);
		else if (vars->map_elem[ray->map_check.y][ray->map_check.x] == OBJECT && !object_ray->hit)
		{
			if (fabs((double)ray->map_check.x + 1 - ray->intersection.x) < 0.005)
			{
				ft_memcpy(object_ray, ray, sizeof(t_ray));
				object_ray->hit = OBJECT;
				object_ray->collision_direction = WEST;
			}
		}
		else if (ray->map_check.x > 0 && vars->map_elem[ray->map_check.y][ray->map_check.x - 1] == OBJECT && !object_ray->hit)
		{
			if (fabs((double)ray->map_check.x - ray->intersection.x) < 0.005)
			{
				ft_memcpy(object_ray, ray, sizeof(t_ray));
				object_ray->hit = OBJECT;
				object_ray->collision_direction = WEST;
			}
		}
		else if (vars->map_elem[ray->map_check.y][ray->map_check.x] == DOOR && !object_ray->hit)
		{
			t_door *door = find_door(vars, ray->map_check);
			if (door)
			{
				if (door->state == CLOSE)
				{
					ft_memcpy(object_ray, ray, sizeof(t_ray));
					object_ray->hit = DOOR;
				}
			}
		}
	}
	return (0);
}

void	raycast(t_vars *vars, double ray_dir)
{
	t_ray	ray;
	t_ray	object_ray;

	ray = init_ray(vars, ray_dir);
	object_ray = init_ray(vars, ray_dir);
	while (!ray.hit)
	{
		if (ray.length.x < ray.length.y)
		{
			ray.map_check.x += ray.step.x;
			ray.dist = ray.length.x;
			ray.length.x += ray.unit_step.x;
		}
		else
		{
			ray.map_check.y += ray.step.y;
			ray.dist = ray.length.y;
			ray.length.y += ray.unit_step.y;
		}
		ray.intersection.x = ray.start.x + ray.delta.x * ray.dist;
		ray.intersection.y = ray.start.y + ray.delta.y * ray.dist;
		ray.hit = check_wall_hit(vars, &ray, &object_ray);
	}
	render_view(vars, &ray, &object_ray);
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
	vars->sprite_count++;
	if (vars->sprite_count == 100)
		vars->sprite_count = 0;
}
