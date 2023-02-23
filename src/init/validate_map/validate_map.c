/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:34 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 19:26:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	validate_map(t_vars *vars)
{
	check_map_has_all_texture(vars);
	check_player_is_exist(vars);
	check_player_is_duplicated(vars);
	check_map_is_closed(vars);
	check_door_position(vars);
}
