/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/20 14:54:36 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_vertical_line(t_image *img, t_ivec offset, \
							int length, unsigned int color)
{
	//this code is just for debugging;
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

int	check_wall_hit(t_vars *vars, t_ray *ray)
{
	if (ray->map_check.x >= 0 && ray->map_check.x < vars->map_width \
		&& ray->map_check.y >= 0 && ray->map_check.y < vars->map_height)
	{
		if (vars->map_elem[ray->map_check.y][ray->map_check.x] == WALL)
			return (1);
		else if (vars->map_elem[ray->map_check.y][ray->map_check.x] == OBJECT)
		{
			if (get_collision_direction(ray->map_check, ray->intersection) == EAST)
				return (1);
		}
		else if (ray->map_check.x > 0 && vars->map_elem[ray->map_check.y][ray->map_check.x - 1] == OBJECT)
		{
			if (get_collision_direction(ray->map_check, ray->intersection) == WEST)
			{
				return (1);
			}
		}
	}
	return (0);
}

void	render_view_without_texture(t_vars *vars, t_ray ray)
{
	//this function is just for debugging
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
}

int	get_texture_xpos(t_ray ray)
{
	double	wall_x;
	int		texture_x;

	texture_x = 0;
	if (ray.collision_direction == NORTH || ray.collision_direction == SOUTH)
	{
		wall_x = ray.intersection.x - floor(ray.intersection.x);
		texture_x = (int)(wall_x * 2000);
		if (ray.collision_direction == NORTH)
			texture_x = 2000 - texture_x - 1;
	}
	else if (ray.collision_direction == EAST || ray.collision_direction == WEST)
	{
		wall_x = ray.intersection.y - floor(ray.intersection.y);
		texture_x = (int)(wall_x * 2000);
		if (ray.collision_direction == EAST)
			texture_x = 2000 - texture_x - 1;
	}
	return (texture_x);
}

double	get_perp_wall_dist(t_vars *vars, t_ray ray)
{
	double	perp_wall_dist;

	perp_wall_dist = ray.dist;
	if (ray.collision_direction == NORTH || ray.collision_direction == SOUTH)
		perp_wall_dist = ((double)ray.map_check.y - vars->player.y \
						+ (1 - ray.step.y) / 2) / ray.delta.y;
	else if (ray.collision_direction == WEST || ray.collision_direction == EAST)
		perp_wall_dist = ((double)ray.map_check.x - vars->player.x \
						+ (1 - ray.step.x) / 2) / ray.delta.x;
	return (perp_wall_dist);
}

unsigned int	get_color_value(t_image *img, t_ivec offset)
{
	unsigned int	color;
	char			*dst;

	dst = img->img_ptr + (offset.y * img->size_line) + offset.x * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	return (color);
}

void	draw_texture_in_view(t_vars *vars, t_ray ray, t_ivec screen, t_ivec texture)
{
	const int		line_height = (int)(H_SIZE / ray.perp_wall_dist);
	const double	step = 1.0 * 2000 / line_height;
	double			textPos;
	unsigned int	color;
	int 			draw_end;

	draw_end = line_height / 2 + H_SIZE / 2;
	if (draw_end >= H_SIZE)
		draw_end = H_SIZE - 1;
	textPos = 0;
	while (screen.y < draw_end)
	{
		texture.y = (int)textPos;
		textPos += step;
		color = get_color_value(&vars->texture.wall[ray.collision_direction], texture);
		if (ray.collision_direction == NORTH || ray.collision_direction == SOUTH)
			color = (color >> 1) & 0x7f7f7f;
		ft_pixel_put(&vars->view, screen.x, screen.y, color);
		ft_pixel_put(&vars->view, screen.x + 1, screen.y, color);
		screen.y++;
	}
}

void	render_view(t_vars *vars, t_ray ray)
{
	t_ivec		texture;
	t_ivec		screen;

	ray.collision_direction = \
		get_collision_direction(ray.map_check, ray.intersection);
	ray.perp_wall_dist = get_perp_wall_dist(vars, ray);
	texture.x = get_texture_xpos(ray);
	texture.y = 0;
	screen.x = W_SIZE * (ray.dir + FOV_ANGLE / 2 - vars->viewing_angle) / FOV_ANGLE;
	screen.y = -(int)(H_SIZE / ray.perp_wall_dist) / 2  + H_SIZE / 2;
	if (screen.y < 0)
		screen.y = 0;
	draw_texture_in_view(vars, ray, screen, texture);
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
		ray.intersection.x = ray.start.x + ray.delta.x * ray.dist;
		ray.intersection.y = ray.start.y + ray.delta.y * ray.dist;
		hit = check_wall_hit(vars, &ray);
	}
	add_ray_to_minimap(vars, ray);
	render_view(vars, ray);
	//render_view_without_texture(vars, ray);
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
