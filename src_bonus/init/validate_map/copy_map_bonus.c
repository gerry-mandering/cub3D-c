/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:57:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:09:57 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

static int	**allocate_copied_map(t_vars *vars)
{
	int	**map;
	int	i;

	map = (int **)ft_calloc((int)vars->map_size.y + 2, sizeof(int *));
	if (map == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < vars->map_size.y + 2)
	{
		map[i] = (int *)ft_calloc((int)vars->map_size.x + 2, sizeof(int));
		if (map[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		ft_memset(map[i], NONE, sizeof(int) * (vars->map_size.x + 2));
		i++;
	}
	return (map);
}

int	**copy_map(t_vars *vars, int option)
{
	int		**copied_map;
	t_ivec	index;

	copied_map = allocate_copied_map(vars);
	index.y = 0;
	while (index.y < vars->map_size.y)
	{
		index.x = 0;
		while (index.x < vars->map_size.x)
		{
			copied_map[index.y + 1][index.x + 1] = vars->map[index.y][index.x];
			if (copied_map[index.y + 1][index.x + 1] == PLAYER && \
					option == REPLACE_PLAYER)
				copied_map[index.y + 1][index.x + 1] = ROAD;
			index.x++;
		}
		index.y++;
	}
	return (copied_map);
}
