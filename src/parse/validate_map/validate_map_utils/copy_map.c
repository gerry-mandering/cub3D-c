/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:57:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 20:38:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

static t_map	**allocate_copied_map(t_vars *vars)
{
	t_map	**map;
	int		i;

	map = (t_map **)ft_calloc((int)vars->map_height, sizeof(int *));
	if (map == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < vars->map_height)
	{
		map[i] = (t_map *)ft_calloc((int)vars->map_width, sizeof(int));
		if (map[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		ft_memset(map[i], -1, sizeof(int) * vars->map_width);
		i++;
	}
	return (map);
}

t_map	**copy_map(t_vars *vars)
{
	int	**copied_map;
	int	width;
	int	height;

	copied_map = allocate_copied_map(vars);
	height = 0;
	while (height < vars->map_height)
	{
		width = 0;
		while (width < vars->map_width)
		{
			copied_map[height][width] = vars->map_elem[height][width];
			width++;
		}
		height++;
	}
	return (copied_map);
}
