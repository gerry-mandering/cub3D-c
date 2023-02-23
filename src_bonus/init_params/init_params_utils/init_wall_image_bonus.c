/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:10:50 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:26:26 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_wall_image(t_image *wall, char **wall_path, void *mlx_ptr)
{
	t_direction	direction;

	direction = NORTH;
	while (direction < 4)
	{
		wall[direction].img = mlx_xpm_file_to_image(mlx_ptr, \
		wall_path[direction], &wall[direction].width, &wall[direction].height);
		if (wall[direction].img == NULL)
			error_handler(INVALID_IMAGE_PATH);
		wall[direction].img_ptr = mlx_get_data_addr(wall[direction].img, \
											&wall[direction].bits_per_pixel, \
											&wall[direction].size_line, \
											&wall[direction].endidan);
		direction++;
	}
}
