/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_is_duplicated_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:27:06 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:31:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	check_player_is_duplicated(t_vars *vars)
{
	bool	player_flag;
	int		height;
	int		width;

	player_flag = false;
	height = 0;
	while (height < vars->map_height)
	{
		width = 0;
		while (width < vars->map_width)
		{
			if (vars->map_elem[height][width] == PLAYER)
			{
				if (player_flag == false)
					player_flag = true;
				else
					error_handler(DUPLICATED_PLAYER);
			}
			width++;
		}
		height++;
	}
}
