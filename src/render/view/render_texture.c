/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:55:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 13:45:11 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

t_direction	get_collision_direction(t_ivec wall_location, t_dvec collision_point)
{
	if (collision_point.x == wall_location.x)
		return (WEST);
	else if (collision_point.y == wall_location.y)
		return (NORTH);
	else if (collision_point.x == wall_location.x + 1)
		return (EAST);
	else if (collision_point.y == wall_location.y + 1)
		return (SOUTH);
	else
	{
		printf("ERROR - testcode");
		return (-1);
	}
}

static void	*get_vertical_line_of_texture(vars)
{

}

void	render_texture(t_vars *vars, t_ivec wall_location, \
						t_dvec collision_point, double dist, int ray_index)
{
	t_direction	collision_direction;
	void		*vertical_line_of_texture;
	int			start;
	int			end;

	collision_direction = get_collision_direction(wall_location, collision_point);
	vertical_line_of_texture = get_vertical_line_of_texture();
	start = W_SIZE * (ray_index / NUMBER_OF_RAYS);
	end = W_SIZE * (ray_index + 1 / NUMBER_OF_RAYS);
	while (start < end)
	{
		start++;
	}
}
