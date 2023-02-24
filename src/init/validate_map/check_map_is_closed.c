/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:27:51 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:23:38 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	flood_fill(int **map, int y, int x, t_ivec map_size)
{
	if (y < 0 || x < 0)
		return ;
	else if (y == map_size.y || x == map_size.x)
		return ;
	else if (map[y][x] == WALL || map[y][x] == VISITED)
		return ;
	else if (map[y][x] == NONE)
		error_handler(UNCLOSED_MAP);
	map[y][x] = VISITED;
	flood_fill(map, y - 1, x, map_size);
	flood_fill(map, y + 1, x, map_size);
	flood_fill(map, y, x - 1, map_size);
	flood_fill(map, y, x + 1, map_size);
}

void	check_map_is_closed(t_vars *vars)
{
	int		**copied_map;
	t_ivec	size;

	copied_map = copy_map(vars);
	size.y = vars->map_size.y + 2;
	size.x = vars->map_size.x + 2;
	flood_fill(copied_map, \
			vars->player_pos.y + 1, vars->player_pos.x + 1, size);
	free_copied_map(copied_map, size);
}
