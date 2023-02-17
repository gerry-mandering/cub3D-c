/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:10:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 20:10:25 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_mlx_params(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	mlx_mouse_hide();
	mlx_mouse_move(vars->win_ptr, W_SIZE / 2, H_SIZE / 2);
	mlx_mouse_get_pos(vars->win_ptr, &vars->mouse.x, &vars->mouse.y);
}
