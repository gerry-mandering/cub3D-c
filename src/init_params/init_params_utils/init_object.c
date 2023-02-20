/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:51:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/20 16:22:42 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_object(t_image *object, char **object_path, void *mlx_ptr)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	while (i < SPRITE_COUNT)
	{
		object[i].img = mlx_xpm_file_to_image(mlx_ptr, \
											object_path[i], &width, &height);
		if (object[i].img == NULL)
			error_handler(INVALID_IMAGE_PATH);
		object[i].img_ptr = mlx_get_data_addr(object[i].img, \
												&object[i].bits_per_pixel, \
												&object[i].size_line, \
												&object[i].endidan);
		i++;
	}
}
