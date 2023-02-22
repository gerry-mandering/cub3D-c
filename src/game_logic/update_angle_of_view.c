/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_angle_of_view.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:09:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 15:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	update_angle_of_view(int key_code, t_vars *vars)
{
	if (key_code == KEY_LEFT_ARROW)
	{
		vars->angle_of_view -= ROTATION_SPEED;
		if (vars->angle_of_view < 0)
			vars->angle_of_view += M_PI * 2;
	}
	else if (key_code == KEY_RIGHT_ARROW)
	{
		vars->angle_of_view += ROTATION_SPEED;
		if (vars->angle_of_view > M_PI * 2)
			vars->angle_of_view -= M_PI * 2;
	}
}
