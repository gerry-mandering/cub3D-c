/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_north.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:01:05 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:02:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_north(t_vars *vars, int *texture_bitflag, char *texture_value)
{
	t_image	north_wall;

	if (*texture_bitflag & NORTH_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	north_wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, texture_value, \
										&north_wall.width, &north_wall.height);
	if (north_wall.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	north_wall.img_ptr = mlx_get_data_addr(north_wall.img, \
											&north_wall.bits_per_pixel, \
											&north_wall.size_line, \
											&north_wall.endian);
	vars->texture.wall[NORTH] = north_wall;
	*texture_bitflag |= NORTH_BITMASK;
}
