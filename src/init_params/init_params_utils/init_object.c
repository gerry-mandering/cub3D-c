/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:51:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/20 16:12:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_object(t_image *object, char **object_path, void *mlx_ptr)
{
	int	width;
	int	height;

	object[0].img = mlx_xpm_file_to_image(mlx_ptr, \
										object_path[0], &width, &height);
	if (object[0].img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	object[0].img_ptr = mlx_get_data_addr(object[0].img, \
											&object[0].bits_per_pixel, \
											&object[0].size_line, \
											&object[0].endidan);
	object[1].img = mlx_xpm_file_to_image(mlx_ptr, \
										object_path[1], &width, &height);
	if (object[1].img == NULL)
		error_handler(INVALID_IMAGE_PATH);
	object[1].img_ptr = mlx_get_data_addr(object[1].img, \
											&object[1].bits_per_pixel, \
											&object[1].size_line, \
											&object[1].endidan);
}
