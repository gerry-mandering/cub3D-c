/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/23 21:28:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	check_object_hit(t_vars *vars, t_ray *ray, t_ray *obj_ray)
{
	int	hit;

	hit = vars->map_elem[ray->map_check.y][ray->map_check.x];
	if (hit == DOOR_CLOSED || (hit == OBJECT && \
		fabs((double)ray->map_check.x + 1 - ray->intersection.x) < 0.005))
	{
		ft_memcpy(obj_ray, ray, sizeof(t_ray));
		obj_ray->hit = hit;
		obj_ray->collision_direction = EAST;
	}
	else if (ray->map_check.x > 0 && \
		vars->map_elem[ray->map_check.y][ray->map_check.x -1] == OBJECT)
	{
		if (fabs((double)ray->map_check.x - ray->intersection.x) < 0.005)
		{
			ft_memcpy(obj_ray, ray, sizeof(t_ray));
			obj_ray->hit = OBJECT;
			obj_ray->collision_direction = WEST;
		}
	}
}

int	check_wall_hit(t_vars *vars, t_ray *ray, t_ray *object_ray)
{
	int	hit;

	if (ray->map_check.x >= 0 && ray->map_check.x < vars->map_width \
		&& ray->map_check.y >= 0 && ray->map_check.y < vars->map_height)
	{
		hit = vars->map_elem[ray->map_check.y][ray->map_check.x];
		if (!object_ray->hit)
			check_object_hit(vars, ray, object_ray);
		if (hit == WALL)
			return (WALL);
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

void	field_of_view(t_vars *vars)
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

int	render(t_vars *vars)
{
	ft_memcpy(vars->view.img_ptr, \
			vars->background.img_ptr, sizeof(int) * W_SIZE * H_SIZE);
	render_minimap(vars);
	field_of_view(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->view.img, 0, 0);
	mlx_put_image_to_window(vars->mlx_ptr, \
							vars->win_ptr, vars->minimap.crop.img, 0, 0);
	if (is_near_door(vars))
		mlx_string_put(vars->mlx_ptr, \
			vars->win_ptr, W_SIZE / 2, H_SIZE / 3 * 2, 0xFFFFFF, PRESS_MSG);
	return (0);
}
