/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/24 10:53:38 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_wall_hit(t_vars *vars, t_ray *ray)
{
	int	hit;

	if (ray->map_check.x >= 0 && ray->map_check.x < vars->map_width \
		&& ray->map_check.y >= 0 && ray->map_check.y < vars->map_height)
	{
		hit = vars->map_elem[ray->map_check.y][ray->map_check.x];
		if (hit == WALL)
			return (WALL);
	}
	return (0);
}

void	raycast(t_vars *vars, double ray_dir)
{
	t_ray	ray;

	ray = init_ray(vars, ray_dir);
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
		ray.hit = check_wall_hit(vars, &ray);
	}
	render_view(vars, &ray);
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
	return (0);
}
