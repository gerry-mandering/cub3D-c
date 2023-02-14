/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_map_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:14:55 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 11:17:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	measure_map_size(t_coord *size, t_list *list_map)
{
	char	*line;
	int		length;

	while (list_map != NULL)
	{
		line = list_map->content;
		length = ft_strlen(line);
		if (length > size->width)
			size->width = length;
		size->height++;
		list_map = list_map->next;
	}
}
