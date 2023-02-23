/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ceiling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:58:57 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:34:31 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	parse_ceiling(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & CEILING_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.ceiling_rgb = get_rgb(value);
	*bitflag |= CEILING_BITMASK;
}
