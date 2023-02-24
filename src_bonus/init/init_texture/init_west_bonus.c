/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_west_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:08:27 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:11:39 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_west(t_vars *vars, char *value)
{
	t_image	west_wall;

	if (vars->texture.bitflag & WEST_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	west_wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, value, \
										&west_wall.width, &west_wall.height);
	if (west_wall.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	west_wall.img_ptr = mlx_get_data_addr(west_wall.img, \
											&west_wall.bits_per_pixel, \
											&west_wall.size_line, \
											&west_wall.endian);
	vars->texture.wall[WEST] = west_wall;
	vars->texture.bitflag |= WEST_BITMASK;
}
