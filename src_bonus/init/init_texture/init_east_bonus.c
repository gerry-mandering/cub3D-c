/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_east_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:08:51 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:12:40 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_east(t_vars *vars, char *value)
{
	t_image	east_wall;

	if (vars->texture.bitflag & EAST_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	east_wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, value, \
										&east_wall.width, &east_wall.height);
	if (east_wall.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	east_wall.img_ptr = mlx_get_data_addr(east_wall.img, \
											&east_wall.bits_per_pixel, \
											&east_wall.size_line, \
											&east_wall.endian);
	vars->texture.wall[EAST] = east_wall;
	vars->texture.bitflag |= EAST_BITMASK;
}
