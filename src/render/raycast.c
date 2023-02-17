/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/17 17:01:00 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_vertical_line(t_image *img, t_ivec offset, \
							int length, unsigned int color)
{
	for (int i=offset.y-length; i<offset.y+length; i++)
	{
		for (int j=offset.x; j<offset.x+3; j++)
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

void	render_view_without_texture(t_vars *vars, t_ray ray)
{
	t_ivec	offset;
	int		face;

	face = get_collision_direction(ray.map_check, ray.intersection);
	ray.perp_wall_dist = 0;
	if (face == NORTH || face == SOUTH)
		ray.perp_wall_dist = ((double)ray.map_check.y - vars->player.y + (1 - ray.step.y) / 2) / ray.delta.y;
	else if (face == WEST || face == EAST)
		ray.perp_wall_dist = ((double)ray.map_check.x - vars->player.x + (1 - ray.step.x) / 2) / ray.delta.x;
	offset.x = W_SIZE * (ray.dir + FOV_ANGLE / 2 - vars->viewing_angle) / FOV_ANGLE;
	offset.y = H_SIZE / 2;
	int color;
	if (face == NORTH)
		color = 0xff0000;
	else if (face == EAST)
		color = 0xff00;
	else if (face == WEST)
		color = 0xff;
	else
		color = 0xffffff;
	draw_vertical_line(&vars->view, offset, 200/ray.perp_wall_dist, color);
	// if (face == WEST)
	// {
	// 	printf("dist: %f, perp_dist: %f, line_height: %f\n", ray.dist, ray.perp_wall_dist, 200/ray.perp_wall_dist);
	// 	printf("(double)ray.map_check.x - vars->player.x + (1 - ray.step.x) / 2) / ray.delta.x = %lf\n", ray.perp_wall_dist);
	// 	printf("%lf - %f + (1 - %d) / 2) / %lf\n", (double)ray.map_check.x, vars->player.x, ray.step.x, ray.delta.x);
	// }
}

void	render_view(t_vars *vars, t_ray ray)
{
	const int	face = get_collision_direction(ray.map_check, ray.intersection);

	ray.perp_wall_dist = 0;
	if (face == NORTH || face == SOUTH)
		ray.perp_wall_dist = ((double)ray.map_check.y - vars->player.y + (1 - ray.step.y) / 2) / ray.delta.y;
	else if (face == WEST || face == EAST)
		ray.perp_wall_dist = ((double)ray.map_check.x - vars->player.x + (1 - ray.step.x) / 2) / ray.delta.x;
	
	int	line_height = (int)(H_SIZE / ray.perp_wall_dist);
	int	draw_start = -line_height / 2 + H_SIZE / 2;
	if (draw_start < 0)
		draw_start = 0;
	int draw_end = line_height / 2 + H_SIZE / 2;
	if (draw_end >= H_SIZE)
		draw_end = H_SIZE - 1;
	double wall_x;
	int	texture_x;
	if (face == NORTH || face == SOUTH)
	{
		wall_x = ray.intersection.x - floor(ray.intersection.x);
		texture_x = (int)(wall_x * (double)2000);
		if (face == NORTH)
			texture_x = 2000 - texture_x - 1;
	}
	else if (face == EAST || face == WEST)
	{
		wall_x = ray.intersection.y - floor(ray.intersection.y);
		texture_x = (int)(wall_x * (double)2000);
		if (face == EAST)
			texture_x = 2000 - texture_x - 1;
	}
	t_image img = vars->texture.wall_image[face];
	double	step = 1.0 * 2000 / line_height;
	double	textPos = 0;
	int x = W_SIZE * (ray.dir + FOV_ANGLE / 2 - vars->viewing_angle) / FOV_ANGLE;
	for (int y=draw_start; y<draw_end; y++)
	{
		int texture_y = (int)textPos & (2000 - 1);
		textPos += step;
		int offset = (texture_y * img.size_line) + texture_x * (img.bits_per_pixel / 8);
		char*	dst = img.img_ptr + offset;
		unsigned int color = *(unsigned int *)dst;
		if (face == NORTH || face == SOUTH)
			color = (color >> 1) & 8355711;
		ft_pixel_put(&vars->view, x, y, color);
		ft_pixel_put(&vars->view, x+1, y, color);
		ft_pixel_put(&vars->view, x+2, y, color);
		ft_pixel_put(&vars->view, x+3, y, color);
	}
}

void	add_ray_to_minimap(t_vars *vars, t_ray ray)
{
	//add ray to minimap
	t_ivec	offset;
	offset.x = ray.intersection.x * TILE_SIZE;
	offset.y = ray.intersection.y * TILE_SIZE;
	draw_rect(&vars->minimap.img, offset, 2, 0xff);
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
	add_ray_to_minimap(vars, ray);
	//render_view(vars, ray);
	render_view_without_texture(vars, ray);
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
