/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:12:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 15:45:07 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_minimap(t_vars *vars)
{
	int	minimap_h;
	int	minimap_w;
	int	crop_h;
	int	crop_w;

	minimap_h = vars->map_height * TILE_SIZE;
	minimap_w = vars->map_width * TILE_SIZE;
	vars->minimap.h_size = minimap_h;
	vars->minimap.w_size = minimap_w;
	crop_h = H_SIZE / 4;
	crop_w = W_SIZE / 4;
	if (minimap_h < crop_h)
		crop_h = minimap_h;
	if (minimap_w < crop_w)
		crop_w = minimap_w;
	vars->minimap.background_img = create_image(vars, minimap_w, minimap_h);
	vars->minimap.img = create_image(vars, minimap_w, minimap_h);
	vars->minimap.crop = create_image(vars, crop_w, crop_h);
	place_wall(vars);
	render_minimap(vars);
}
