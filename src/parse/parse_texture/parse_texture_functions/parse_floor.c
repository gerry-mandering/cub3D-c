/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:57:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 19:11:56 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_floor(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & FLOOR_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.floor_rgb = get_rgb(value);
	*bitflag |= FLOOR_BITMASK;
}
