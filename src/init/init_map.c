/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:33:23 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 10:48:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_map(t_vars *vars, int fd)
{
	t_list	*list_map;

	make_list_map(&list_map, fd);
	init_map_size(vars, list_map);
	allocate_map(vars);
	labeling_map(vars, list_map);
	init_player_position(vars);
	init_angle_of_view(vars, list_map);
	ft_lstclear(&list_map, free);
}
