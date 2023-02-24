/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_viewing_angle_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:37:27 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:13:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

static double	get_angle(char direction)
{
	if (direction == 'N')
		return (M_PI + M_PI_2);
	else if (direction == 'S')
		return (M_PI_2);
	else if (direction == 'E')
		return (0);
	else
		return (M_PI);
}

void	init_viewing_angle(t_vars *vars, t_list *list_map)
{
	t_list	*current_node;
	char	*map_description;
	t_ivec	index;

	current_node = list_map;
	index.y = 0;
	while (current_node != NULL)
	{
		map_description = current_node->content;
		index.x = 0;
		while (map_description[index.x] != '\0')
		{
			if (is_direction_character(map_description[index.x]))
				vars->viewing_angle = get_angle(map_description[index.x]);
			index.x++;
		}
		current_node = current_node->next;
		index.y++;
	}
}
