/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:05:09 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/20 20:46:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_params(t_vars *vars)
{
	init_mlx_params(vars);
	init_viewing_angle(vars);
	init_view(vars);
	init_wall_image(vars->texture.wall, vars->texture.wall_path, vars->mlx_ptr);
	if (vars->texture.door_path != NULL)
		init_door_image(&vars->texture.door, \
										vars->texture.door_path, vars->mlx_ptr);
	if (vars->texture.object_path[0] != NULL)
		init_object_image(vars->texture.object, \
									vars->texture.object_path, vars->mlx_ptr);
	init_background(vars, vars->texture.ceiling_rgb, vars->texture.floor_rgb);
	init_minimap(vars);
	init_door_list(vars);
}