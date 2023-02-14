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
	int		height;
	int		width;

	height = 0;
	while (height < map_data->size.height)
	{
		width = 0;
		while (width < map_data->size.width)
		{
			if (map_data->map[height][width] == PLAYER)
				return (true);
			width++;
		}
		height++;
	}
	return (false);
}

static bool	is_player_duplicated(t_map_data *map_data)
{
	bool	player_flag;
	int		height;
	int		width;

	player_flag = false;
	height = 0;
	while (height < map_data->size.height)
	{
		width = 0;
		while (width < map_data->size.width)
		{
			if (map_data->map[height][width] == PLAYER)
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

static void	flood_fill(t_map **map, int height, int width, t_coord size)
{
	if (height < 0 || width < 0)
		return ;
	else if (height == size.height || width == size.width)
		return ;
	else if (map[height][width] == WALL || map[height][width] == VISITED)
		return ;
	else if (map[height][width] == NONE)
		error_handler(UNCLOSED_MAP);
	map[height][width] = VISITED;
	flood_fill(map, height - 1, width, size);
	flood_fill(map, height + 1, width, size);
	flood_fill(map, height, width - 1, size);
	flood_fill(map, height, width + 1, size);
}

static void	check_map_is_closed(t_map_data *map_data)
{
	t_map	**copied_map;
	t_coord	player_position;
	t_coord	size;

	copied_map = copy_map(map_data);
	player_position = map_data->player_position;
	size = map_data->size;
	flood_fill(copied_map, player_position.height, player_position.width, size);
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
