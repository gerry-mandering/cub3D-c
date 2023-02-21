/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:17:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/22 00:28:57 by jinholee         ###   ########.fr       */
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
				object_ray->hit = 1;
				object_ray->collision_direction = WEST;
			}
		}
		else if (ray->map_check.x > 0 && vars->map_elem[ray->map_check.y][ray->map_check.x - 1] == OBJECT && !object_ray->hit)
		{
			if (fabs((double)ray->map_check.x - ray->intersection.x) < 0.005)
			{
				ft_memcpy(object_ray, ray, sizeof(t_ray));
				object_ray->hit = 1;
				object_ray->collision_direction = WEST;
			}
		}
	}
	return (0);
}

int	get_texture_xpos(t_ray *ray, t_image *img)
{
	double	wall_x;
	int		texture_x;

	texture_x = 0;
	if (ray->collision_direction == NORTH || ray->collision_direction == SOUTH)
	{
		wall_x = ray->intersection.x - floor(ray->intersection.x);
		texture_x = (int)(wall_x * img->width);
		if (ray->collision_direction == NORTH)
			texture_x = img->width - texture_x - 1;
	}
	else if (ray->collision_direction == EAST || ray->collision_direction == WEST)
	{
		wall_x = ray->intersection.y - floor(ray->intersection.y);
		texture_x = (int)(wall_x * img->width);
		if (ray->collision_direction == EAST)
			texture_x = img->width - texture_x - 1;
	}
	return (texture_x);
}

unsigned int	get_color_value(t_image *img, t_ivec offset)
{
	unsigned int	color;
	char			*dst;

	dst = img->img_ptr + (offset.y * img->size_line) + offset.x * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	return (color);
}

void	render_upper_texture(t_vars *vars, t_ray *ray, t_image *img)
{
	t_ivec	texture;
	t_ivec	screen;
	double	step;
	double	next_pos;
	int		draw_end;

	texture.x = get_texture_xpos(ray, img);
	texture.y = img->height / 2;
	screen.x = W_SIZE * \
		(ray->dir + FOV_ANGLE / 2 - vars->viewing_angle) / FOV_ANGLE;
	screen.y = H_SIZE / 2 + 1;
	step = 1.0 * img->height / (int)(H_SIZE / ray->perp_wall_dist);
	draw_end = H_SIZE / 2 - (int)(H_SIZE / ray->perp_wall_dist) / 2;
	if (draw_end < 0)
		draw_end = 0;
	next_pos = texture.y;
	while (texture.y >= 0 && screen.y-- >= draw_end)
	{
		ft_pixel_put(&vars->view, screen.x, screen.y, \
						get_color_value(img, texture));
		ft_pixel_put(&vars->view, screen.x + 1, screen.y, \
						get_color_value(img, texture));
		next_pos -= step;
		texture.y = (int)(next_pos);
	}
}

void	render_lower_texture(t_vars *vars, t_ray *ray, t_image *img)
{
	t_ivec			texture;
	t_ivec			screen;
	double			step;
	double			next_pos;
	int				draw_end;

	texture.x = get_texture_xpos(ray, img);
	texture.y = img->height / 2;
	screen.x = W_SIZE * \
		(ray->dir + FOV_ANGLE / 2 - vars->viewing_angle) / FOV_ANGLE;
	screen.y = H_SIZE / 2 - 1;
	step = 1.0 * img->height / (int)(H_SIZE / ray->perp_wall_dist);
	draw_end = H_SIZE / 2 + (int)(H_SIZE / ray->perp_wall_dist) / 2;
	if (draw_end >= H_SIZE)
		draw_end = H_SIZE - 1;
	next_pos = texture.y;
	while (texture.y < img->height && screen.y++ <= draw_end)
	{
		ft_pixel_put(&vars->view, screen.x, screen.y, \
						get_color_value(img, texture));
		ft_pixel_put(&vars->view, screen.x + 1, screen.y, \
						get_color_value(img, texture));
		next_pos += step;
		texture.y = (int)(next_pos);
	}
}

void	render_view(t_vars *vars, t_ray *ray)
{
	t_image	img;

	ray->collision_direction = \
		get_collision_direction(ray->map_check, ray->intersection);
	ray->perp_wall_dist = ray->dist * cos(fabs(vars->viewing_angle - ray->dir));
	img = vars->texture.wall[ray->collision_direction];
	render_upper_texture(vars, ray, &img);
	render_lower_texture(vars, ray, &img);
}

void	add_ray_to_minimap(t_vars *vars, t_ray *ray)
{
	//add ray to minimap
	t_ivec	offset;

	offset.x = ray->intersection.x * TILE_SIZE;
	offset.y = ray->intersection.y * TILE_SIZE;
	draw_rect(&vars->minimap.img, offset, 2, 0xff);
}

unsigned int	get_sprite_color_value(t_vars *vars, t_ivec texture)
{
	unsigned int	color;

	if (vars->sprite_count < 70)
		color = get_color_value(&vars->texture.object[0], texture);
	else if (vars->sprite_count < 80)
		color = get_color_value(&vars->texture.object[1], texture);
	else if (vars->sprite_count < 90)
		color = get_color_value(&vars->texture.object[2], texture);
	else
		color = get_color_value(&vars->texture.object[1], texture);
	return (color);
}

void	draw_object_in_view(t_vars *vars, t_ray *ray, t_ivec screen, t_ivec texture)
{
	const int		line_height = (int)(H_SIZE / ray->perp_wall_dist);
	const double	step = 1.0 * 240 / line_height;
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
		color = get_sprite_color_value(vars, texture);
		ft_pixel_put(&vars->view, screen.x, screen.y, color);
		ft_pixel_put(&vars->view, screen.x + 1, screen.y, color);
		screen.y++;
	}
}

void	render_object(t_vars *vars, t_ray *object_ray)
{
	t_ivec	texture;
	t_ivec	screen;

	object_ray->perp_wall_dist = object_ray->dist * cos(fabs(vars->viewing_angle - object_ray->dir));
	texture.x = get_texture_xpos(object_ray, &vars->texture.object[0]);
	texture.y = 0;
	screen.x = W_SIZE * (object_ray->dir + FOV_ANGLE / 2 - vars->viewing_angle) / FOV_ANGLE;
	screen.y = -(int)(H_SIZE / object_ray->perp_wall_dist) / 2  + H_SIZE / 2;
	if (screen.y < 0)
		screen.y = 0;
	draw_object_in_view(vars, object_ray, screen, texture);
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
	add_ray_to_minimap(vars, &ray);
	render_view(vars, &ray);
	if (object_ray.hit)
		render_object(vars, &object_ray);
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
