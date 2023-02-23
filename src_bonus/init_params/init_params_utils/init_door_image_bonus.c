/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:11:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:25:01 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_door_image(t_image *door, char *door_path, void *mlx_ptr)
{
	door->img = mlx_xpm_file_to_image(mlx_ptr, \
										door_path, &door->width, &door->height);
	if (door->img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	door->img_ptr = mlx_get_data_addr(door->img, \
											&door->bits_per_pixel, \
											&door->size_line, \
											&door->endidan);
}
