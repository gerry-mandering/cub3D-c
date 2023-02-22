/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:00:20 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/22 19:19:33 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//this file is just for temporary.
//functions in this file will be replaced soon
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

void	draw_object_in_view(t_vars *vars, t_ray *ray, \
							t_ivec screen, t_ivec texture)
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
		if (ray->hit == DOOR)
			color = get_color_value(&vars->texture.door, texture);
		else
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

	object_ray->perp_wall_dist = object_ray->dist \
				* cos(fabs(vars->viewing_angle - object_ray->dir));
	if (object_ray->hit == DOOR)
		texture.x = get_texture_xpos(object_ray, &vars->texture.door);
	else
		texture.x = get_texture_xpos(object_ray, &vars->texture.object[0]);
	texture.y = 0;
	screen.x = W_SIZE \
		* (object_ray->dir + FOV_ANGLE / 2 - vars->viewing_angle) / FOV_ANGLE;
	screen.y = -(int)(H_SIZE / object_ray->perp_wall_dist) / 2  + H_SIZE / 2;
	if (screen.y < 0)
		screen.y = 0;
	draw_object_in_view(vars, object_ray, screen, texture);
}
