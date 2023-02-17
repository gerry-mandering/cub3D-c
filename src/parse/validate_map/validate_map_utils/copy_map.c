/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:57:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 21:01:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

static t_map	**allocate_copied_map(t_vars *vars)
{
	t_map	**map;
	int		i;

	map = (t_map **)ft_calloc((int)vars->map_height + 2, sizeof(int *));
	if (map == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < vars->map_height + 2)
	{
		map[i] = (t_map *)ft_calloc((int)vars->map_width + 2, sizeof(int));
		if (map[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		ft_memset(map[i], NONE, sizeof(int) * (vars->map_width + 2));
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
			copied_map[height + 1][width + 1] = vars->map_elem[height][width];
			width++;
		}
		height++;
	}
	return (copied_map);
}
