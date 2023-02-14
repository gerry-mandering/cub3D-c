/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:40:23 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 10:41:37 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	allocate_map(t_map_data *map_data)
{
	t_map	**map;
	int		i;

	map = (t_map **)ft_calloc((int)map_data->size.col, sizeof(int *));
	if (map == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < map_data->size.col)
	{
		map[i] = (t_map *)ft_calloc((int)map_data->size.row, sizeof(int));
		if (map[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		ft_memset(map[i], -1, sizeof(int) * map_data->size.row);
		i++;
	}
	map_data->map = map;
}
