/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:54:58 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/24 13:27:14 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	else if (ray->collision_direction == EAST \
			|| ray->collision_direction == WEST)
	{
		wall_x = ray->intersection.y - floor(ray->intersection.y);
		texture_x = (int)(wall_x * img->width);
		if (ray->collision_direction == EAST)
			texture_x = img->width - texture_x - 1;
	}
	return (texture_x);
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
		put_pixel(&vars->view, \
					screen.x, screen.y, get_color_value(img, texture));
		put_pixel(&vars->view, \
					screen.x + 1, screen.y, get_color_value(img, texture));
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
		put_pixel(&vars->view, \
					screen.x, screen.y, get_color_value(img, texture));
		put_pixel(&vars->view, \
					screen.x + 1, screen.y, get_color_value(img, texture));
		next_pos += step;
		texture.y = (int)(next_pos);
	}
}

void	render_view(t_vars *vars, t_ray *ray)
{
	t_image	*img;

	ray->collision_direction = \
		get_collision_direction(ray->map_check, ray->intersection);
	ray->perp_wall_dist = ray->dist * cos(fabs(vars->viewing_angle - ray->dir));
	img = &vars->texture.wall[ray->collision_direction];
	render_upper_texture(vars, ray, img);
	render_lower_texture(vars, ray, img);
}
