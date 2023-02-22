/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:05:27 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 11:07:40 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_mlx(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	mlx_mouse_show();
	mlx_mouse_move(vars->win_ptr, W_SIZE, H_SIZE);
	mlx_mouse_get_pos(vars->win_ptr, \
					&vars->previous_mouse_pos.x, &vars->previous_mouse_pos.y);
}
