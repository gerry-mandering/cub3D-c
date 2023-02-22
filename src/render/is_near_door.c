/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_near_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:19:38 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 20:17:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_heading_direction(double viewing_angle)
{
	if (viewing_angle > M_PI + M_PI_2 - (FOV_ANGLE / 2) && \
			viewing_angle <= M_PI + M_PI_2 + (FOV_ANGLE / 2))
		return (NORTH);
	else if (viewing_angle > M_PI_2 - (FOV_ANGLE / 2) && \
			viewing_angle <= M_PI_2 + (FOV_ANGLE / 2))
		return (SOUTH);
	else if (viewing_angle > (M_PI * 2) - (FOV_ANGLE / 2) && \
			viewing_angle <= FOV_ANGLE / 2)
		return (EAST);
	else if (viewing_angle > M_PI - (FOV_ANGLE / 2) && \
			viewing_angle <= M_PI + (FOV_ANGLE / 2))
		return (WEST);
	else
		return (-1);
}

static t_ivec	get_search_position(int heading_direction, t_dvec player)
{
	t_ivec	search_pos;

	search_pos.x = (int)player.x;
	search_pos.y = (int)player.y;
	if (heading_direction == NORTH)
		search_pos.y++;
	else if (heading_direction == SOUTH)
		search_pos.y--;
	else if (heading_direction == EAST)
		search_pos.x++;
	else if (heading_direction == WEST)
		search_pos.x--;
	return (search_pos);
}

bool	is_near_door(t_vars *vars)
{
	int		heading_direction;
	t_ivec	search_pos;

	heading_direction = get_heading_direction(vars->viewing_angle);
	if (heading_direction == -1)
		return (false);
	search_pos = get_search_position(heading_direction, vars->player);
	if (vars->map_elem[search_pos.y][search_pos.x] == DOOR)
		return (true);
	else
		return (false);
}
