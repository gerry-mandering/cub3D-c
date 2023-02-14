/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:43:26 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 10:43:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	set_spawning_direction(char character, t_map_data *map_data)
{
	if (character == 'N')
		map_data->spawning_direction = NORTH;
	else if (character == 'S')
		map_data->spawning_direction = SOUTH;
	else if (character == 'E')
		map_data->spawning_direction = EAST;
	else if (character == 'W')
		map_data->spawning_direction = WEST;
}

static int	get_label(char character, t_map_data *map_data)
{
	if (character == ' ')
		return (NONE);
	else if (character == '0')
		return (EMPTY_SPACE);
	else if (character == '1')
		return (WALL);
	else if (character == 'N' || character == 'S' || \
				character == 'E' || character == 'W')
	{
		set_spawning_direction(character, map_data);
		return (PLAYER);
	}
	else
	{
		error_handler(INVALID_MAP_FORMAT);
		return (-1);
	}
}

void	labeling_map(t_map_data *map_data, t_list *list_map)
{
	int		row;
	int		col;
	char	*line;

	col = 0;
	while (col < map_data->size.col)
	{
		row = 0;
		line = list_map->content;
		while (line[row] != '\0')
		{
			(map_data->map)[col][row] = get_label(line[row], map_data);
			row++;
		}
		col++;
		list_map = list_map->next;
	}
}
