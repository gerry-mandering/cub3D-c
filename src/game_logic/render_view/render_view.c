/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:55:08 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 16:19:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	overwrite_background(char *view, char *background)
{
	ft_memcpy(view, background, (H_SIZE * W_SIZE) * sizeof(int));
}

void	render_view(t_vars *vars)
{
	double	angle_interval;
	double	start_angle;
	double	end_angle;

	overwrite_background(vars->view.img_ptr, vars->background.img_ptr);
	angle_interval = FOV_ANGLE / NUMBER_OF_RAYS;
	start_angle = vars->angle_of_view - (FOV_ANGLE / 2);
	end_angle = vars->angle_of_view + (FOV_ANGLE / 2);
	while (start_angle < end_angle)
	{
		raycast(vars, start_angle);
		start_angle += angle_interval;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->view.img, 0, 0);
}
