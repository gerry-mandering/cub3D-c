/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_south.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:02:08 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:02:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_south(t_vars *vars, int *texture_bitflag, char *texture_value)
{
	t_image	south_wall;

	if (*texture_bitflag & SOUTH_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	south_wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, texture_value, \
										&south_wall.width, &south_wall.height);
	if (south_wall.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	south_wall.img_ptr = mlx_get_data_addr(south_wall.img, \
											&south_wall.bits_per_pixel, \
											&south_wall.size_line, \
											&south_wall.endian);
	vars->texture.wall[SOUTH] = south_wall;
	*texture_bitflag |= SOUTH_BITMASK;
}
