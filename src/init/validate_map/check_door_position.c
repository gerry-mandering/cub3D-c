/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:29:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 19:23:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	check_four_direction(int **copied_map, t_ivec index)
{
	if (copied_map[index.y - 1][index.x] == ROAD && \
		copied_map[index.y + 1][index.x] == ROAD && \
		copied_map[index.y][index.x - 1] == WALL && \
		copied_map[index.y][index.x + 1] == WALL)
		return ;
	else if (copied_map[index.y - 1][index.x] == WALL && \
		copied_map[index.y + 1][index.x] == WALL && \
		copied_map[index.y][index.x - 1] == ROAD && \
		copied_map[index.y][index.x + 1] == ROAD)
		return ;
	else
		error_handler(WRONG_DOOR_POSITION);
}

void	check_door_position(t_vars *vars)
{
	int		**copied_map;
	t_ivec	size;
	t_ivec	index;

	copied_map = copy_map(vars, REPLACE_PLAYER);
	size.y = vars->map_size.y + 2;
	size.x = vars->map_size.x + 2;
	index.y = 0;
	while (index.y < size.y)
	{
		index.x = 0;
		while (index.x < size.x)
		{
			if (copied_map[index.y][index.x] == DOOR_CLOSED)
				check_four_direction(copied_map, index);
			index.x++;
		}
		index.y++;
	}
	free_copied_map(copied_map, size);
}
