/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_map_size_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:14:55 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:33:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	measure_map_size(int *map_width, int *map_height, t_list *list_map)
{
	char	*line;
	int		length;

	while (list_map != NULL)
	{
		line = list_map->content;
		length = ft_strlen(line);
		if (length > *map_width)
			*map_width = length;
		(*map_height)++;
		list_map = list_map->next;
	}
	if (*map_height < 3 || *map_width < 3)
		error_handler(INVALID_MAP_SIZE);
}
