/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_west.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:02:39 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:02:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_west(t_vars *vars, int *texture_bitflag, char *texture_value)
{
	t_image	west_wall;

	if (*texture_bitflag & WEST_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	west_wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, texture_value, \
										&west_wall.width, &west_wall.height);
	if (west_wall.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	west_wall.img_ptr = mlx_get_data_addr(west_wall.img, \
											&west_wall.bits_per_pixel, \
											&west_wall.size_line, \
											&west_wall.endian);
	vars->texture.wall[WEST] = west_wall;
	*texture_bitflag |= WEST_BITMASK;
}
