/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:10:06 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 16:29:11 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_floor(t_vars *vars, char *value)
{
	if (vars->texture.bitflag & FLOOR_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.floor_rgb = get_rgb(value);
	vars->texture.bitflag |= FLOOR_BITMASK;
}
