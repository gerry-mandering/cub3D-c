/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:26:09 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 20:00:32 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	init_background_color(t_image *view, t_vars *vars)
{
	t_ivec	index;

	index.y = 0;
	while (index.y < H_SIZE)
	{
		index.x = 0;
		while (index.x < W_SIZE)
		{
			if (index.y < H_SIZE / 2)
				ft_pixel_put(view, index.x, index.y, vars->texture.ceiling_rgb);
			else
				ft_pixel_put(view, index.x, index.y, vars->texture.floor_rgb);
			index.x++;
		}
		index.y++;
	}
}

void	init_wall_image(t_vars *vars)
{
	int	index;
	int	width;
	int	height;

	index = 0;
	while (index < 4)
	{
		vars->texture.wall_image[index].img = mlx_xpm_file_to_image(vars->mlx_ptr, vars->texture.wall[index], &width, &height);
		if (vars->texture.wall_image[index].img == NULL)
			error_handler(INVALID_IMAGE_PATH);
		vars->texture.wall_image[index].img_ptr = mlx_get_data_addr(vars->texture.wall_image[index].img, &vars->texture.wall_image[index].bits_per_pixel, &vars->texture.wall_image[index].size_line, &vars->texture.wall_image[index].endidan);
		printf("pointer = %p\n", vars->texture.wall_image[index].img_ptr);
		index++;
	}
}

void	init_view(t_vars *vars)
{
	vars->view = create_image(vars, W_SIZE, H_SIZE);
	init_background_color(&vars->backgroud, vars);
	init_wall_image(vars);
}
