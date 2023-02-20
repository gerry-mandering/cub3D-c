/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:11:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/20 16:13:38 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_door(t_image *door, char *door_path, void *mlx_ptr)
{
	int	width;
	int	height;

	door->img = mlx_xpm_file_to_image(mlx_ptr, \
										door_path, &width, &height);
	if (door->img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	door->img_ptr = mlx_get_data_addr(door->img, \
											&door->bits_per_pixel, \
											&door->size_line, \
											&door->endidan);
}
