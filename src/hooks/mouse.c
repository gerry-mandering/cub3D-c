/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:57:44 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/14 11:53:10 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	mouse(t_params *params)
{
	int		cur_x;
	int		cur_y;

	mlx_mouse_get_pos(params->mlx->win_ptr, &cur_x, &cur_y);
	if (params->mlx->mouse.x_pos >= W_SIZE || (params->mlx->mouse.x_pos < cur_x && cur_x < W_SIZE))
		params->map_data->player_position.direction -= MOUSE_SPEED;
	else if (params->mlx->mouse.x_pos <= 0 || (params->mlx->mouse.x_pos > cur_x && cur_x > 0))
		params->map_data->player_position.direction += MOUSE_SPEED;
	params->mlx->mouse.x_pos = cur_x;
	params->mlx->mouse.y_pos = cur_y;
	render_minimap(params->mlx, params->map_data);
	return (0);
}
