/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:39:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/18 20:45:58 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static double	get_perp_wall_dist(t_vars *vars, t_ray ray)
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

static int	get_texture_xpos(t_ray ray)
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

static unsigned int	get_color_value(t_image *img, t_ivec offset)
{
	unsigned int	color;
	char			*dst;

	dst = img->img_ptr + (offset.y * img->size_line) + offset.x * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	return (color);
}

static void	draw_object_in_view(t_vars *vars, t_ray ray, t_ivec screen, t_ivec texture, int count)
{
	const int		line_height = (int)(H_SIZE / ray.perp_wall_dist);
	const double	step = 1.0 * 2000 / line_height;
	double			text_pos;
	unsigned int	color;
	int				draw_end;

	draw_end = line_height / 2 + H_SIZE / 2;
	if (draw_end >= H_SIZE)
		draw_end = H_SIZE - 1;
	text_pos = 0;
	while (screen.y < draw_end)
	{
		texture.y = (int)text_pos;
		text_pos += step;
		if (count < 25)
			color = get_color_value(&vars->texture.object[0], texture);
		else
			color = get_color_value(&vars->texture.object[1], texture);
		if (ray.collision_direction == NORTH || ray.collision_direction == SOUTH)
			color = (color >> 1) & 0x7f7f7f;
		ft_pixel_put(&vars->view, screen.x, screen.y, color);
		ft_pixel_put(&vars->view, screen.x + 1, screen.y, color);
		screen.y++;
	}
}

void	render_object(t_vars *vars, t_ray ray, int count)
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
	draw_object_in_view(vars, ray, screen, texture, count);
}
