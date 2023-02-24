/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:44:34 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 09:47:59 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_map_size(t_vars *vars, t_list *list_map)
{
	t_list	*current_node;
	char	*map_description;
	int		length;

	current_node = list_map;
	while (current_node != NULL)
	{
		map_description = current_node->content;
		length = ft_strlen(map_description);
		if (length > vars->map_size.x)
			vars->map_size.x = length;
		vars->map_size.y++;
		current_node = current_node->next;
	}
	if (vars->map_size.x < 3 || vars->map_size.y < 3)
		error_handler(INVALID_MAP_SIZE);
}
