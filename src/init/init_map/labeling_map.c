/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:52:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:21:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static t_map_label	get_label(char character)
{
	if (character == ' ')
		return (NONE);
	else if (character == '0')
		return (ROAD);
	else if (character == '1')
		return (WALL);
	else if (is_direction_character(character))
		return (PLAYER);
	else
		error_handler(INVALID_MAP_FORMAT);
	return (-1);
}

void	labeling_map(t_vars *vars, t_list *list_map)
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
			vars->map[index.y][index.x] = get_label(map_description[index.x]);
			index.x++;
		}
		current_node = current_node->next;
		index.y++;
	}
}
