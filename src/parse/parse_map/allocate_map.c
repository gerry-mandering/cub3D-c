/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:40:23 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 21:06:37 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	allocate_map(t_vars *vars)
{
	int	**map_elem;
	int	i;

	map_elem = (t_map **)ft_calloc((int)vars->map_height, sizeof(int *));
	if (map_elem == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < vars->map_height)
	{
		map_elem[i] = (t_map *)ft_calloc((int)vars->map_width, sizeof(int));
		if (map_elem[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		ft_memset(map_elem[i], -1, sizeof(int) * vars->map_width);
		i++;
	}
	vars->map_elem = map_elem;
}
