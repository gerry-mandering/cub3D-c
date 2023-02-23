/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:34:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 10:36:29 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_player_position(t_vars *vars)
{
	t_ivec	index;

	index.y = 0;
	while (index.y < vars->map_size.y)
	{
		index.x = 0;
		while (index.x < vars->map_size.x)
		{
			if (vars->map[index.y][index.x] == PLAYER)
			{
				vars->player_pos.y = index.y;
				vars->player_pos.x = index.x;
				return ;
			}
			index.x++;
		}
		index.y++;
	}
}
