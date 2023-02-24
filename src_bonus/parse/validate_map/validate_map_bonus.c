/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:34 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 11:13:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	validate_map(t_vars *vars)
{
	check_player_is_exist(vars);
	check_player_is_duplicated(vars);
	check_map_is_closed(vars);
	check_door_position(vars);
}
