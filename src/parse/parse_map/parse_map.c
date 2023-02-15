/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:57:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 21:03:33 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	print_map(t_vars *vars)
{
	int	width;
	int	height;

	printf("<%s>\n", __func__);
	height = 0;
	while (height < vars->map_height)
	{
		width = 0;
		while (width < vars->map_width)
		{
			if (vars->map_elem[height][width] == NONE)
				printf(" ");
			else if (vars->map_elem[height][width] == EMPTY_SPACE)
				printf("0");
			else if (vars->map_elem[height][width] == WALL)
				printf("1");
			else if (vars->map_elem[height][width] == PLAYER)
				printf("P");
			width++;
		}
		printf("\n");
		height++;
	}
}

void	parse_map(t_vars *vars, int fd)
{
	t_list	*list_map;

	make_list_map(&list_map, fd);
	measure_map_size(&vars->map_width, &vars->map_height, list_map);
	allocate_map(vars);
	labeling_map(vars, list_map);
	set_player_position(vars);
	print_map(vars);
}
