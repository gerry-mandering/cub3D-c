/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:10:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 15:48:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static double	get_heading_angle(int key_code, double angle_of_view)
{
	double	heading_angle;

	heading_angle = 0;
	if (key_code == KEY_W)
		heading_angle = angle_of_view;
	else if (key_code == KEY_A)
		heading_angle = angle_of_view + M_PI + M_PI_2;
	else if (key_code == KEY_S)
		heading_angle = angle_of_view + M_PI;
	else if (key_code == KEY_D)
		heading_angle = angle_of_view + M_PI_2;
	if (heading_angle > M_PI * 2)
		heading_angle -= M_PI * 2;
	return (heading_angle);
}

static bool	detect_collision(int **map, t_dvec updated_pos)
{
	if (map[(int)(updated_pos.y - 0.01)][(int)updated_pos.x] == WALL)
		return (true);
	else if (map[(int)(updated_pos.y + 0.01)][(int)updated_pos.x] == WALL)
		return (true);
	else if (map[(int)(updated_pos.y)][(int)(updated_pos.x - 0.01)] == WALL)
		return (true);
	else if (map[(int)(updated_pos.y)][(int)(updated_pos.x + 0.01)] == WALL)
		return (true);
	else
		return (false);
}

void	update_player_position(int key_code, t_vars *vars)
{
	double	heading_angle;
	t_dvec	updated_pos;

	heading_angle = get_heading_angle(key_code, vars->angle_of_view);
	updated_pos.x = vars->player_pos.x + (MOVEMENT_SPEED * cos(heading_angle));
	updated_pos.y = vars->player_pos.y + (MOVEMENT_SPEED * sin(heading_angle));
	if (!detect_collision(vars->map, updated_pos))
	{
		vars->player_pos.y = updated_pos.y;
		vars->player_pos.x = updated_pos.x;
	}
}
