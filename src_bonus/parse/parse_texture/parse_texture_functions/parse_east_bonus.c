/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_east_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:34:56 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	parse_east(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & EAST_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall_path[EAST] = ft_strdup(value);
	*bitflag |= EAST_BITMASK;
}
