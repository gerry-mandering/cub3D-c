/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:17:28 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 20:18:25 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
