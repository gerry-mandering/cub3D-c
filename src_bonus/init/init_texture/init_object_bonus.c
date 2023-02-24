/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:39:25 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:12:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_object(t_vars *vars, char *value)
{
	static int	sprite_index;
	t_image		object;

	if (sprite_index == SPRITE_COUNT)
		error_handler(DUPLICATED_TEXTURE);
	object.img = mlx_xpm_file_to_image(vars->mlx_ptr, value, \
										&object.width, &object.height);
	if (object.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	object.img_ptr = mlx_get_data_addr(object.img, \
											&object.bits_per_pixel, \
											&object.size_line, \
											&object.endian);
	vars->texture.object[sprite_index] = object;
	vars->texture.bitflag |= OBJECT_BITMASK << sprite_index;
	sprite_index++;
}
