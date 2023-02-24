/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:40:35 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 20:00:10 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_map(t_vars *vars, int fd)
{
	t_list	*list_map;

	make_list_map(&list_map, fd);
	init_map_size(vars, list_map);
	allocate_map(vars);
	labeling_map(vars, list_map);
	init_player_position(vars);
	init_viewing_angle(vars, list_map);
	ft_lstclear(&list_map, free);
}
