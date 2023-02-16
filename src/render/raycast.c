/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/16 17:25:06 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_vertical_line(t_image *img, t_ivec offset, \
							int length, unsigned int color)
{
	for (int i=offset.y-length; i<offset.y+length; i++)
	{
		for (int j=offset.x; j<offset.x+1; j++)
		{
			ft_pixel_put(img, j, i, color);
		}
	}
}

t_ray	init_ray(t_vars *vars, double ray_dir)
{
	t_ray	ray;

	ray.dir = ray_dir;
	ray.start.x = vars->player.x;
	ray.start.y = vars->player.y;
	ray.map_check.x = (int)ray.start.x;
	ray.map_check.y = (int)ray.start.y;
	ray.delta.x = cos(ray_dir);
	ray.delta.y = sin(ray_dir);
	ray.step.x = (ray.delta.x >= 0) - (ray.delta.x < 0);
	ray.step.y = (ray.delta.y >= 0) - (ray.delta.y < 0);
	ray.unit_step.x = sqrt(1 + \
				(ray.delta.y / ray.delta.x) * (ray.delta.y / ray.delta.x));
	ray.unit_step.y = sqrt(1 + \
				(ray.delta.x / ray.delta.y) * (ray.delta.x / ray.delta.y));
	ray.length.x = (ray.map_check.x + 1 - ray.start.x) * ray.unit_step.x;
	ray.length.y = (ray.map_check.y + 1 - ray.start.y) * ray.unit_step.y;
	if (ray.delta.x < 0)
		ray.length.x = (ray.start.x - ray.map_check.x) * ray.unit_step.x;
	if (ray.delta.y < 0)
		ray.length.y = (ray.start.y - ray.map_check.y) * ray.unit_step.y;
	return (ray);
}

int	check_wall_hit(t_vars *vars, t_ray ray)
{
	if (ray.map_check.x >= 0 && ray.map_check.x < vars->map_width \
		&& ray.map_check.y >= 0 && ray.map_check.y < vars->map_height)
	{
		if (vars->map_elem[ray.map_check.y][ray.map_check.x] == WALL)
			return (1);
	}
	return (0);
}

void	render_view(t_vars *vars, t_ray ray)
{
	const int	face = get_collision_direction(ray.map_check, ray.intersection);

	ray.perp_wall_dist = 0;
	if (face == NORTH || face == SOUTH)
		ray.perp_wall_dist = ((double)ray.map_check.y - vars->player.y + (1 - ray.step.y) / 2) / ray.delta.y;
	else if (face == WEST || face == EAST)
		ray.perp_wall_dist = ((double)ray.map_check.x - vars->player.x + (1 - ray.step.x) / 2) / ray.delta.x;
	//From here is just a temporary code for debugging; 
	int 	color = 0;
	t_ivec	offset;
	offset.x = W_SIZE * (ray.dir + FOV_ANGLE / 2 - vars->viewing_angle) / FOV_ANGLE;
	offset.y = H_SIZE / 2;
	if (face ==  NORTH)
		color = 0xff0000;
	else if (face == SOUTH)
		color = 0xff00;
	else if (face == EAST)
		color = 0xff;
	else if (face == WEST)
		color = 0xffffff;
	else
		printf("wrong face\n");
	draw_vertical_line(&vars->view, offset, 200/ray.perp_wall_dist, color);
}

void	raycast(t_vars *vars, double ray_dir)
{
	t_ray	ray;
	int		hit;

	ray = init_ray(vars, ray_dir);
	hit = 0;
	while (!hit)
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
		hit = check_wall_hit(vars, ray);
	}
	ray.intersection.x = ray.start.x + ray.delta.x * ray.dist;
	ray.intersection.y = ray.start.y + ray.delta.y * ray.dist;
	//add ray to minimap
	t_ivec	offset;
	offset.x = ray.intersection.x * TILE_SIZE;
	offset.y = ray.intersection.y * TILE_SIZE;
	draw_rect(&vars->minimap.img, offset, 2, 0xff);
	render_view(vars, ray);
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
