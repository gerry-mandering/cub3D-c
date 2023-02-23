/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:29:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:30:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

static void	check_four_direction(t_map **copied_map, t_ivec index)
{
	if (copied_map[index.y - 1][index.x] == EMPTY_SPACE && \
		copied_map[index.y + 1][index.x] == EMPTY_SPACE && \
		copied_map[index.y][index.x - 1] == WALL && \
		copied_map[index.y][index.x + 1] == WALL)
		return ;
	else if (copied_map[index.y - 1][index.x] == WALL && \
		copied_map[index.y + 1][index.x] == WALL && \
		copied_map[index.y][index.x - 1] == EMPTY_SPACE && \
		copied_map[index.y][index.x + 1] == EMPTY_SPACE)
		return ;
	else
		error_handler(WRONG_DOOR_POSITION);
}

void	check_door_position(t_vars *vars)
{
	t_map	**copied_map;
	t_ivec	map_size;
	t_ivec	index;

	copied_map = copy_map(vars, REPLACE_PLAYER);
	map_size.y = vars->map_height + 2;
	map_size.x = vars->map_width + 2;
	index.y = 0;
	while (index.y < map_size.y)
	{
		index.x = 0;
		while (index.x < map_size.x)
		{
			if (copied_map[index.y][index.x] == DOOR_CLOSED)
				check_four_direction(copied_map, index);
			index.x++;
		}
		index.y++;
	}
	free_copied_map(copied_map, map_size);
}
