/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_is_exist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:26:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 19:13:53 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	check_player_is_exist(t_vars *vars)
{
	t_ivec	index;

	index.y = 0;
	while (index.y < vars->map_size.y)
	{
		index.x = 0;
		while (index.x < vars->map_size.x)
		{
			if (vars->map[index.y][index.x] == PLAYER)
				return ;
			index.x++;
		}
		index.y++;
	}
	error_handler(HAVE_NO_PLAYER);
}
