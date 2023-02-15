/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:58:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/15 17:34:25 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	wall_collision(void)
{
	
	return (0);
}

void	update_player_position(int keycode, t_vars *vars)
{
	double	viewing_angle;
	double	dx;
	double	dy;

	viewing_angle = vars->viewing_angle;
	if (keycode == KEY_D)
		viewing_angle += M_PI_2;
	else if (keycode == KEY_S)
		viewing_angle += M_PI;
	else if (keycode == KEY_A)
		viewing_angle += M_PI + M_PI_2;
	if (viewing_angle > 2 * M_PI)
		viewing_angle -= 2 * M_PI;
	dx = MOVING_SPEED * cos(viewing_angle);
	dy = MOVING_SPEED * sin(viewing_angle);
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
