/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:09:41 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:10:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

t_image	create_image(t_vars *vars, int img_w, int img_h)
{
	t_image	img;

	img.img = mlx_new_image(vars->mlx_ptr, img_w, img_h);
	img.img_ptr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
									&img.size_line, &img.endian);
	img.width = img_w;
	img.height = img_h;
	if (!img.img_ptr)
		error_handler(SYSTEMCALL_ERROR);
	return (img);
}
