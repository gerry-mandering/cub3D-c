/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:12:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 02:52:33 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_minimap(t_vars *vars)
{
	int	background_h;
	int	background_w;
	int	minimap_h;
	int	minimap_w;

	background_h = vars->map_height * TILE_SIZE;
	background_w = vars->map_width * TILE_SIZE;
	minimap_h = H_SIZE / 4;
	minimap_w = W_SIZE / 4;
	if (background_w < W_SIZE / 4)
		minimap_w = background_w;
	if (background_h < H_SIZE / 4)
		minimap_h = background_h;
	vars->minimap.h_size = minimap_h;
	vars->minimap.w_size = minimap_w;
	vars->minimap.background_img = \
				create_image(vars, background_w, background_h);
	vars->minimap.img = \
				create_image(vars, minimap_w, minimap_h);
	place_wall(vars);
	render_minimap(vars);
}
