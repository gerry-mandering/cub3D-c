/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:26:09 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/15 22:09:47 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	create_view(t_image *view, t_vars *vars)
{
	view->img = mlx_new_image(vars->mlx_ptr, W_SIZE, H_SIZE);
	view->img_ptr = mlx_get_data_addr(view->img, &view->bits_per_pixel, \
										&view->size_line, &view->endidan);
	view->width = W_SIZE;
	view->height = H_SIZE;
	if (!view->img_ptr)
		error_handler(SYSTEMCALL_ERROR);
}

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

static void	init_wall_img_ptr(void *mlx_ptr, t_texture *texture)
{
	int	width;
	int	height;

	texture->wall_img_ptr[NORTH] = \
		mlx_xpm_file_to_image(mlx_ptr, texture->wall[NORTH], &width, &height);
	texture->wall_img_ptr[SOUTH] = \
		mlx_xpm_file_to_image(mlx_ptr, texture->wall[SOUTH], &width, &height);
	texture->wall_img_ptr[EAST] = \
		mlx_xpm_file_to_image(mlx_ptr, texture->wall[EAST], &width, &height);
	texture->wall_img_ptr[WEST] = \
		mlx_xpm_file_to_image(mlx_ptr, texture->wall[WEST], &width, &height);
	if (texture->wall_img_ptr[NORTH] == NULL || \
		texture->wall_img_ptr[SOUTH] == NULL || \
		texture->wall_img_ptr[EAST] == NULL || \
		texture->wall_img_ptr[WEST] == NULL)
		error_handler(INVALID_IMAGE_PATH);
}

void	init_view(t_vars *vars)
{
	create_view(&vars->view, vars);
	init_background_color(&vars->backgroud, vars);
	init_wall_img_ptr(vars->mlx_ptr, &vars->texture);
}
