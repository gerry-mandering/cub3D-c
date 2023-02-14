/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:18:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 11:18:40 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	set_player_position(t_map_data *map_data)
{
	int		height;
	int		width;

	height = 0;
	while (height < map_data->size.height)
	{
		width = 0;
		while (width < map_data->size.width)
		{
			if (map_data->map[height][width] == PLAYER)
			{
				map_data->player_position.height = height;
				map_data->player_position.width = width;
			}
			width++;
		}
		height++;
	}
}
