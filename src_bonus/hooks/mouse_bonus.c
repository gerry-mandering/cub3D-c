/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:57:44 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/23 21:23:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

int	mouse(t_vars *vars)
{
	int		cur_x;
	int		cur_y;

	mlx_mouse_get_pos(vars->win_ptr, &cur_x, &cur_y);
	if (cur_x >= W_SIZE - 1)
	{
		mlx_mouse_move(vars->win_ptr, W_SIZE, cur_y);
		vars->viewing_angle += ROTATE_SPEED;
	}
	else if (cur_x <= 0)
	{
		mlx_mouse_move(vars->win_ptr, 0, cur_y);
		vars->viewing_angle -= ROTATE_SPEED;
	}
	if (vars->viewing_angle < 0)
		vars->viewing_angle += 2 * M_PI;
	else if (vars->viewing_angle > 2 * M_PI)
		vars->viewing_angle -= 2 * M_PI;
	render(vars);
	return (0);
}
