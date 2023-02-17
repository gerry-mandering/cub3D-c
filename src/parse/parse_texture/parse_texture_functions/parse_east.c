/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_east.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 19:12:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_east(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & EAST_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall_path[EAST] = ft_strdup(value);
	*bitflag |= EAST_BITMASK;
}
