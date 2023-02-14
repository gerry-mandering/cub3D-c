/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:57:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 18:56:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

static t_map	**allocate_copied_map(t_coord size)
{
	t_map	**map;
	int		i;

	map = (t_map **)ft_calloc((int)size.height, sizeof(int *));
	if (map == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < size.height)
	{
		map[i] = (t_map *)ft_calloc((int)size.width, sizeof(int));
		if (map[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		ft_memset(map[i], -1, sizeof(int) * size.width);
		i++;
	}
	return (map);
}

t_map	**copy_map(t_map_data *map_data)
{
	t_map	**copied_map;
	int		height;
	int		width;

	copied_map = allocate_copied_map(map_data->size);
	height = 0;
	while (height < map_data->size.height)
	{
		width = 0;
		while (width < map_data->size.width)
		{
			copied_map[height][width] = map_data->map[height][width];
			width++;
		}
		height++;
	}
	return (copied_map);
}
