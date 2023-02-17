/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:43:26 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 19:02:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

static void	set_spawning_direction(char character, t_vars *vars)
{
	if (character == 'N')
		vars->spawning_direction = NORTH;
	else if (character == 'S')
		vars->spawning_direction = SOUTH;
	else if (character == 'E')
		vars->spawning_direction = EAST;
	else if (character == 'W')
		vars->spawning_direction = WEST;
}

static int	is_direction(char character)
{
	if (character == 'N' || character == 'S' || \
			character == 'W' || character == 'E')
		return (1);
	else
		return (0);
}

static int	get_label(char character)
{
	if (character == ' ')
		return (NONE);
	else if (character == '0')
		return (EMPTY_SPACE);
	else if (character == '1')
		return (WALL);
	else if (character == 'N' || character == 'S' || \
				character == 'E' || character == 'W')
		return (PLAYER);
	else
	{
		error_handler(INVALID_MAP_FORMAT);
		return (-1);
	}
}

void	labeling_map(t_vars *vars, t_list *list_map)
{
	int		width;
	int		height;
	char	*line;

	height = 0;
	while (height < vars->map_height)
	{
		width = 0;
		line = list_map->content;
		while (line[width] != '\0')
		{
			vars->map_elem[height][width] = get_label(line[width]);
			if (is_direction(line[width]))
				set_spawning_direction(line[width], vars);
			width++;
		}
		height++;
		list_map = list_map->next;
	}
}
