/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:56:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/20 20:38:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static t_door	*make_new_door(t_vars *vars, t_ivec index)
{
	t_door	*door;

	door = ft_calloc(1, sizeof(t_door));
	if (door == NULL)
		error_handler(SYSTEMCALL_ERROR);
	door->state = CLOSE;
	door->location = index;
	if (vars->map_elem[index.y - 1][index.x] == EMPTY_SPACE && \
		vars->map_elem[index.y + 1][index.x] == EMPTY_SPACE && \
		vars->map_elem[index.y][index.x - 1] == WALL && \
		vars->map_elem[index.y][index.x + 1] == WALL)
		door->direction = HORIZONTAL;
	else if (vars->map_elem[index.y - 1][index.x] == WALL && \
		vars->map_elem[index.y + 1][index.x] == WALL && \
		vars->map_elem[index.y][index.x - 1] == EMPTY_SPACE && \
		vars->map_elem[index.y][index.x + 1] == EMPTY_SPACE)
		door->direction = VERTICAL;
	return (door);
}

void	init_door_list(t_vars *vars)
{
	t_ivec	index;
	t_door	*door;

	index.y = 0;
	while (index.y < vars->map_height)
	{
		index.x = 0;
		while (index.x < vars->map_width)
		{
			if (vars->map_elem[index.y][index.x] == DOOR)
			{
				door = make_new_door(vars, index);
				ft_lstadd_back(&vars->door_list, ft_lstnew(door));
			}
			index.x++;
		}
		index.y++;
	}
}
