/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:58:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/14 21:28:33 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	wall_collision(void)
{
	return (0);
}

void	update_player_position(int keycode, t_vars *vars)
{
	double	dx;
	double	dy;

	if (keycode == KEY_D)
		vars->viewing_angle += M_PI_2;
	else if (keycode == KEY_S)
		vars->viewing_angle += M_PI;
	else if (keycode == KEY_A)
		vars->viewing_angle += M_PI + M_PI_2;
	if (vars->viewing_angle > 2 * M_PI)
		vars->viewing_angle -= 2 * M_PI;
	dx = MOVING_SPEED * cos(vars->viewing_angle);
	dy = MOVING_SPEED * sin(vars->viewing_angle);
	if (!wall_collision())
		vars->player.x += dx;
	if (!wall_collision())
		vars->player.y += dy;
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		update_player_position(keycode, vars);
	return (0);
}
