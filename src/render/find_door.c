/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:46:25 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 18:49:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_door	*find_door(t_vars *vars, t_ivec index)
{
	t_list	*current_node;
	t_door	*current_door;

	current_node = vars->door_list;
	while (current_node != NULL)
	{
		current_door = current_node->content;
		if (current_door->location.x == index.x && \
			current_door->location.y == index.y)
			break ;
		current_node = current_node->next;
	}
	return (current_door);
}
