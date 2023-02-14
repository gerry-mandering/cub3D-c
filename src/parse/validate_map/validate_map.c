/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:34 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 13:14:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static bool	is_player_exist(t_map_data *map_data)
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
				return (true);
			row++;
		}
		col++;
	}
	return (false);
}

static bool	is_player_duplicated(t_map_data *map_data)
{
	bool	player_flag;
	int		col;
	int		row;

	player_flag = false;
	col = 0;
	while (col < map_data->size.col)
	{
		row = 0;
		while (row < map_data->size.row)
		{
			if (map_data->map[col][row] == PLAYER)
			{
				if (player_flag == false)
					player_flag = true;
				else
					return (true);
			}
			row++;
		}
		col++;
	}
	return (false);
}

static void	flood_fill(t_map **map, int col, int row, t_coord size)
{
	if (col < 0 || row < 0)
		return ;
	else if (col == size.col || row == size.row)
		return ;
	else if (map[col][row] == WALL || map[col][row] == VISITED)
		return ;
	else if (map[col][row] == NONE)
		error_handler(UNCLOSED_MAP);
	map[col][row] = VISITED;
	flood_fill(map, col - 1, row, size);
	flood_fill(map, col + 1, row, size);
	flood_fill(map, col, row - 1, size);
	flood_fill(map, col, row + 1, size);
}

static void	check_map_is_closed(t_map_data *map_data)
{
	t_map	**copied_map;
	t_coord	player_position;
	t_coord	size;

	copied_map = copy_map(map_data);
	player_position = map_data->player_position;
	size = map_data->size;
	flood_fill(copied_map, player_position.col, player_position.row, size);
}

void	validate_map(t_map_data *map_data)
{
	if (!is_player_exist(map_data))
		error_handler(HAVE_NO_PLAYER);
	if (is_player_duplicated(map_data))
		error_handler(DUPLICATED_PLAYER);
	check_map_is_closed(map_data);
	printf("validate_map success\n");
}
