/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:09:44 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:12:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_door(t_vars *vars, char *value)
{
	t_image		door;

	if (vars->texture.bitflag & DOOR_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	door.img = mlx_xpm_file_to_image(vars->mlx_ptr, value, \
										&door.width, &door.height);
	if (door.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	door.img_ptr = mlx_get_data_addr(door.img, \
											&door.bits_per_pixel, \
											&door.size_line, \
											&door.endian);
	vars->texture.door = door;
	vars->texture.bitflag |= DOOR_BITMASK;
}
