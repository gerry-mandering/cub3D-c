/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:57:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 11:18:53 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	print_map(t_map_data *map_data)
{
	int	row;
	int	col;

	printf("<%s>\n", __func__);
	col = 0;
	while (col < map_data->size.col)
	{
		row = 0;
		while (row < map_data->size.row)
		{
			if (map_data->map[col][row] == NONE)
				printf(" ");
			else if (map_data->map[col][row] == EMPTY_SPACE)
				printf("0");
			else if (map_data->map[col][row] == WALL)
				printf("1");
			else if (map_data->map[col][row] == PLAYER)
				printf("P");
			row++;
		}
		printf("\n");
		col++;
	}
}

void	parse_map(t_map_data *map_data, int fd)
{
	t_list	*list_map;

	make_list_map(&list_map, fd);
	measure_map_size(&map_data->size, list_map);
	allocate_map(map_data);
	labeling_map(map_data, list_map);
	set_player_position(map_data);
	print_map(map_data);
}
