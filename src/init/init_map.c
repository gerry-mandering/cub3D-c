/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:33:23 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:37:50 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_map(t_vars *vars, int fd)
{
	t_list	*list_map;

	make_list_map(&list_map, fd);
	init_map_size();
	allocate_map();
	labeling_map();
	ft_lstclear(&list_map, free);
	init_player_position();
	init_direction();
}
