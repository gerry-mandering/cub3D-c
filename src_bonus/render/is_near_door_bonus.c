/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_near_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:19:38 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:08:16 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

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

t_ivec	get_heading_position(t_vars *vars)
{
	int		heading_direction;
	t_ivec	heading_pos;

	heading_direction = get_heading_direction(vars->viewing_angle);
	if (heading_direction == -1)
	{
		heading_pos.x = -1;
		heading_pos.y = -1;
		return (heading_pos);
	}
	heading_pos.x = (int)vars->player_pos.x;
	heading_pos.y = (int)vars->player_pos.y;
	if (heading_direction == NORTH)
		heading_pos.y--;
	else if (heading_direction == SOUTH)
		heading_pos.y++;
	else if (heading_direction == EAST)
		heading_pos.x++;
	else if (heading_direction == WEST)
		heading_pos.x--;
	return (heading_pos);
}

bool	is_near_door(t_vars *vars)
{
	t_ivec	heading_pos;

	heading_pos = get_heading_position(vars);
	if (heading_pos.x == -1 && heading_pos.y == -1)
		return (false);
	if (vars->map[heading_pos.y][heading_pos.x] == DOOR_CLOSED || \
		vars->map[heading_pos.y][heading_pos.x] == DOOR_OPENED)
		return (true);
	else
		return (false);
}
