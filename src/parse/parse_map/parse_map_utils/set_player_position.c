/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:18:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 16:14:16 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

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
	vars->player.x += 0.5;
	vars->player.y += 0.5;
}
