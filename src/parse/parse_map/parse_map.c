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
	int	width;
	int	height;

	printf("<%s>\n", __func__);
	height = 0;
	while (height < map_data->size.height)
	{
		width = 0;
		while (width < map_data->size.width)
		{
			if (map_data->map[height][width] == NONE)
				printf(" ");
			else if (map_data->map[height][width] == EMPTY_SPACE)
				printf("0");
			else if (map_data->map[height][width] == WALL)
				printf("1");
			else if (map_data->map[height][width] == PLAYER)
				printf("P");
			width++;
		}
		printf("\n");
		height++;
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
