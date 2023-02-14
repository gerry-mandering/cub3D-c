/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:18:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 21:10:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	set_player_position(t_vars *vars)
{
	int		height;
	int		width;

	height = 0;
	while (height < vars->map_height)
	{
		width = 0;
		while (width < vars->map_width)
		{
			if (vars->map_elem[height][width] == PLAYER)
			{
				vars->player.y = height;
				vars->player.x = width;
			}
			width++;
		}
		height++;
	}
}
