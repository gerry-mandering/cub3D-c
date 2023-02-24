/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_south_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:07:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:11:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_south(t_vars *vars, char *value)
{
	t_image	south_wall;

	if (vars->texture.bitflag & SOUTH_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	south_wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, value, \
										&south_wall.width, &south_wall.height);
	if (south_wall.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	south_wall.img_ptr = mlx_get_data_addr(south_wall.img, \
											&south_wall.bits_per_pixel, \
											&south_wall.size_line, \
											&south_wall.endian);
	vars->texture.wall[SOUTH] = south_wall;
	vars->texture.bitflag |= SOUTH_BITMASK;
}
