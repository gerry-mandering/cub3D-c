/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:57:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 13:14:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

static t_map	**allocate_copied_map(t_coord size)
{
	t_map	**map;
	int		i;

	map = (t_map **)ft_calloc((int)size.col, sizeof(int *));
	if (map == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < size.col)
	{
		map[i] = (t_map *)ft_calloc((int)size.row, sizeof(int));
		if (map[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		ft_memset(map[i], -1, sizeof(int) * size.row);
		i++;
	}
	return (map);
}

t_map	**copy_map(t_map_data *map_data)
{
	t_map	**copied_map;
	int		col;
	int		row;

	copied_map = allocate_copied_map(map_data->size);
	col = 0;
	while (col < map_data->size.col)
	{
		row = 0;
		while (row < map_data->size.row)
		{
			copied_map[col][row] = map_data->map[col][row];
			row++;
		}
		col++;
	}
	return (copied_map);
}
