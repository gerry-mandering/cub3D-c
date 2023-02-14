/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:34 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 21:19:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static bool	is_player_exist(t_vars *vars)
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
				return (true);
			width++;
		}
		height++;
	}
	return (false);
}

static bool	is_player_duplicated(t_vars *vars)
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
					return (true);
			}
			width++;
		}
		height++;
	}
	return (false);
}

static void	flood_fill(t_map **map, int y, int x, t_ivec map_size)
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

static void	check_map_is_closed(t_vars *vars)
{
	t_map	**copied_map;
	t_ivec	map_size;

	copied_map = copy_map(vars);
	map_size.y = vars->map_height;
	map_size.x = vars->map_width;
	flood_fill(copied_map, vars->player.y, vars->player.x, map_size);
}

void	validate_map(t_vars *vars)
{
	if (!is_player_exist(vars))
		error_handler(HAVE_NO_PLAYER);
	if (is_player_duplicated(vars))
		error_handler(DUPLICATED_PLAYER);
	check_map_is_closed(vars);
	printf("validate_map success\n");
}
