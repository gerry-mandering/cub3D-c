/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:58:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/17 20:13:23 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	wall_collision(t_vars *vars, t_dvec delta)
{
	t_dvec	next_pos;

	next_pos.x = vars->player.x + delta.x;
	next_pos.y = vars->player.y + delta.y;
	if (vars->map_elem[(int)(next_pos.y - 0.01)][(int)(next_pos.x)] == WALL)
		return (1);
	if (vars->map_elem[(int)(next_pos.y + 0.01)][(int)(next_pos.x)] == WALL)
		return (1);
	if (vars->map_elem[(int)(next_pos.y)][(int)(next_pos.x - 0.01)] == WALL)
		return (1);
	if (vars->map_elem[(int)(next_pos.y)][(int)(next_pos.x + 0.01)] == WALL)
		return (1);
	return (0);
}

void	update_player_position(int keycode, t_vars *vars)
{
	double	viewing_angle;
	t_dvec	delta;

	viewing_angle = vars->viewing_angle;
	if (keycode == KEY_D)
		viewing_angle += M_PI_2;
	else if (keycode == KEY_S)
		viewing_angle += M_PI;
	else if (keycode == KEY_A)
		viewing_angle += M_PI + M_PI_2;
	if (viewing_angle > 2 * M_PI)
		viewing_angle -= 2 * M_PI;
	delta.x = MOVING_SPEED * cos(viewing_angle);
	delta.y = MOVING_SPEED * sin(viewing_angle);
	if (!wall_collision(vars, delta))
		vars->player.x += delta.x;
	if (!wall_collision(vars, delta))
		vars->player.y += delta.y;	
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		update_player_position(keycode, vars);
	else if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		{}
	return (0);
}
