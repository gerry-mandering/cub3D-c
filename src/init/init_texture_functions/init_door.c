/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:10:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:17:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_door(t_vars *vars, int *texture_bitflag, char *texture_value)
{
	static bool	init_door_flag;
	t_image		door;

	if (init_door_flag == true)
		error_handler(DUPLICATED_TEXTURE);
	door.img = mlx_xpm_file_to_image(vars->mlx_ptr, texture_value, \
									&door.width, &door.height);
	if (door.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	door.img_ptr = mlx_get_data_addr(door.img, \
									&door.bits_per_pixel, \
									&door.size_line, \
									&door.endian);
	vars->texture.door = door;
	init_door_flag = true;
	(void)texture_bitflag;
}
