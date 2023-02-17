/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:12:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 20:12:24 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_minimap(t_vars *vars)
{
	vars->minimap.h_size = vars->map_height * TILE_SIZE;
	vars->minimap.w_size = vars->map_width * TILE_SIZE;
	vars->minimap.background_img = \
				create_image(vars, vars->minimap.w_size, vars->minimap.h_size);
	vars->minimap.img = \
				create_image(vars, vars->minimap.w_size, vars->minimap.h_size);
	place_wall(vars);
	render_minimap(vars);
}
