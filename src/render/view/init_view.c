/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:26:09 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 11:39:08 by minseok2         ###   ########.fr       */
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

void	init_view(t_vars *vars)
{
	create_view(&vars->view, vars);
	init_background_color(&vars->view, vars);
}
