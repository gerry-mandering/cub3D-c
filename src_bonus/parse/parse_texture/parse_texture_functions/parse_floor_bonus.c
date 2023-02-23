/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:57:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:35:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	parse_floor(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & FLOOR_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.floor_rgb = get_rgb(value);
	*bitflag |= FLOOR_BITMASK;
}
