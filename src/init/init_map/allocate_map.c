/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:48:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 09:51:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	allocate_map(t_vars *vars)
{
	int	i;

	vars->map = (int **)ft_calloc(vars->map_size.y, sizeof(int *));
	if (vars->map == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < vars->map_size.y)
	{
		vars->map[i] = (int *)ft_calloc(vars->map_size.x, sizeof(int));
		if (vars->map[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		ft_memset(vars->map[i], -1, vars->map_size.x * sizeof(int));
		i++;
	}
}
