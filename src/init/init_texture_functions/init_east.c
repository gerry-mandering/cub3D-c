/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_east.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:23:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:01:45 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_east(t_vars *vars, int *texture_bitflag, char *texture_value)
{
	t_image	east_wall;

	if (*texture_bitflag & EAST_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	east_wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, texture_value, \
										&east_wall.width, &east_wall.height);
	if (east_wall.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	east_wall.img_ptr = mlx_get_data_addr(east_wall.img, \
											&east_wall.bits_per_pixel, \
											&east_wall.size_line, \
											&east_wall.endian);
	vars->texture.wall[EAST] = east_wall;
	*texture_bitflag |= EAST_BITMASK;
}
