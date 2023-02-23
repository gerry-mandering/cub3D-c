/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:49:10 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/23 16:24:15 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rect(t_image *image, t_ivec offset, int size, unsigned int color)
{
	t_ivec	index;
	t_ivec	draw_pos;

	index.y = 0;
	while (index.y < size)
	{
		index.x = 0;
		while (index.x < size)
		{
			draw_pos.x = offset.x + index.x;
			draw_pos.y = offset.y + index.y;
			put_pixel(image, draw_pos, color);
			index.x++;
		}
		index.y++;
	}
}

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

unsigned int	get_color_value(t_image *img, t_ivec offset)
{
	unsigned int	color;
	char			*dst;

	dst = img->img_ptr + (offset.y * img->size_line) \
		+ offset.x * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	return (color);
}

t_direction	get_collision_direction(t_ivec wall_location, \
											t_dvec collision_point)
{
	if (fabs((double)wall_location.x - collision_point.x) < 0.0000001)
		return (WEST);
	else if (fabs((double)wall_location.x + 1 - collision_point.x) < 0.0000001)
		return (EAST);
	else if (fabs((double)wall_location.y - collision_point.y) < 0.0000001)
		return (NORTH);
	else if (fabs((double)wall_location.y + 1 - collision_point.y) < 0.0000001)
		return (SOUTH);
	else
		return (-1);
}
