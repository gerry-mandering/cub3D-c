/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:57:44 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/14 21:29:47 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	mouse(t_vars *vars)
{
	int		cur_x;
	int		cur_y;

	mlx_mouse_get_pos(vars->win_ptr, &cur_x, &cur_y);
	if (vars->mouse.x >= W_SIZE || (vars->mouse.x < cur_x && cur_x < W_SIZE))
		vars->viewing_angle -= MOUSE_SPEED;
	else if (vars->mouse.x <= 0 || (vars->mouse.x > cur_x && cur_x > 0))
		vars->viewing_angle += MOUSE_SPEED;
	vars->mouse.x = cur_x;
	vars->mouse.y = cur_y;
	render_minimap(vars);
	return (0);
}
