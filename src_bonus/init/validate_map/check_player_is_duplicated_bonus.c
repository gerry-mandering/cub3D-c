/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_is_duplicated_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:27:06 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:10:10 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	check_player_is_duplicated(t_vars *vars)
{
	bool	player_flag;
	t_ivec	index;

	player_flag = false;
	index.y = 0;
	while (index.y < vars->map_size.y)
	{
		index.x = 0;
		while (index.x < vars->map_size.x)
		{
			if (vars->map[index.y][index.x] == PLAYER)
			{
				if (player_flag == false)
					player_flag = true;
				else
					error_handler(DUPLICATED_PLAYER);
			}
			index.x++;
		}
		index.y++;
	}
}
