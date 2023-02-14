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
	int		col;
	int		row;

	col = 0;
	while (col < map_data->size.col)
	{
		row = 0;
		while (row < map_data->size.row)
		{
			if (map_data->map[col][row] == PLAYER)
			{
				map_data->player_position.col = col;
				map_data->player_position.row = row;
			}
			row++;
		}
		col++;
	}
}
