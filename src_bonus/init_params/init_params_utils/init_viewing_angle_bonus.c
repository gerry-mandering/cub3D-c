/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_viewing_angle_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:10:35 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:26:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_viewing_angle(t_vars *vars)
{
	if (vars->spawning_direction == NORTH)
		vars->viewing_angle = M_PI + M_PI_2;
	else if (vars->spawning_direction == SOUTH)
		vars->viewing_angle = M_PI_2;
	else if (vars->spawning_direction == EAST)
		vars->viewing_angle = 0;
	else if (vars->spawning_direction == WEST)
		vars->viewing_angle = M_PI;
}
