/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:00:27 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 11:03:25 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

t_image	create_image(t_vars *vars, int width, int height)
{
	t_image	image;

	image.img = mlx_new_image(vars->mlx_ptr, width, height);
	if (image.img == NULL)
		error_handler(SYSTEMCALL_ERROR);
	image.img_ptr = mlx_get_data_addr(image.img, &image.bits_per_pixel, \
										&image.size_line, &image.endian);
	image.width = width;
	image.height = height;
	return (image);
}
