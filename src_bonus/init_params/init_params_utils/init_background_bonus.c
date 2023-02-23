/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:12:01 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:24:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_background(t_vars *vars, int ceiling_rgb, int floor_rgb)
{
	int	height;
	int	width;

	vars->background = create_image(vars, W_SIZE, H_SIZE);
	height = 0;
	while (height < H_SIZE)
	{
		width = 0;
		while (width < W_SIZE)
		{
			if (height < H_SIZE / 2)
				ft_pixel_put(&vars->background, width, height, ceiling_rgb);
			else
				ft_pixel_put(&vars->background, width, height, floor_rgb);
			width++;
		}
		height++;
	}
}
