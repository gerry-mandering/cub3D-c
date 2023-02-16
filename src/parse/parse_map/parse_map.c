/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:57:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 20:40:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	parse_map(t_vars *vars, int fd)
{
	t_list	*list_map;

	make_list_map(&list_map, fd);
	measure_map_size(&vars->map_width, &vars->map_height, list_map);
	allocate_map(vars);
	labeling_map(vars, list_map);
	set_player_position(vars);
	ft_lstclear(&list_map, free);
}
