/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:08:39 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 11:13:50 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_background(t_vars *vars)
{
	t_ivec	vector;

	vars->background = create_image(vars, W_SIZE, H_SIZE);
	vector.y = 0;
	while (vector.y < H_SIZE)
	{
		vector.x = 0;
		while (vector.x < W_SIZE)
		{
			if (vector.y < H_SIZE / 2)
				put_pixel(&vars->background, vector, vars->texture.ceiling_rgb);
			else
				put_pixel(&vars->background, vector, vars->texture.floor_rgb);
			vector.x++;
		}
		vector.y++;
	}
}
