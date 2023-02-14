/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:58:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/14 20:43:26 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	wall_collision(void)
{
	return (0);
}

void	update_player_position(int keycode, t_vars *vars)
{
	double	direction;
	double	dx;
	double	dy;

	direction = map_data->player_position.direction;
	if (keycode == KEY_D)
		direction += M_PI_2;
	else if (keycode == KEY_S)
		direction += M_PI;
	else if (keycode == KEY_A)
		direction += M_PI + M_PI_2;
	if (direction > 2 * M_PI)
		direction -= 2 * M_PI;
	dx = MOVING_SPEED * cos(direction);
	dy = MOVING_SPEED * sin(direction);
	if (!wall_collision())
		map_data->player_position.col += dx;
	if (!wall_collision())
		map_data->player_position.row += dy;
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		update_player_position(keycode, vars);
	return (0);
}
