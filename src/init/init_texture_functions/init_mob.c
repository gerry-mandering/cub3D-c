/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:14:08 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:19:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_mob(t_vars *vars, int *texture_bitflag, char *texture_value)
{
	static int	sprite_index;
	t_image		mob_sprite;

	if (sprite_index == SPRITE_COUNT)
		error_handler(DUPLICATED_TEXTURE);
	mob_sprite.img = mlx_xpm_file_to_image(vars->mlx_ptr, texture_value, \
										&mob_sprite.width, &mob_sprite.height);
	if (mob_sprite.img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	mob_sprite.img_ptr = mlx_get_data_addr(mob_sprite.img, \
											&mob_sprite.bits_per_pixel, \
											&mob_sprite.size_line, \
											&mob_sprite.endian);
	vars->texture.mob_sprite[sprite_index] = mob_sprite;
	sprite_index++;
	(void)texture_bitflag;
}
