/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_is_exist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:26:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/20 15:26:18 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	check_player_is_exist(t_vars *vars)
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
				return ;
			width++;
		}
		height++;
	}
	error_handler(HAVE_NO_PLAYER);
}
