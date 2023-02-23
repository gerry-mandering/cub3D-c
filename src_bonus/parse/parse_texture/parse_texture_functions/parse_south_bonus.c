/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_south_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:53:40 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:35:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	parse_south(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & SOUTH_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall_path[SOUTH] = ft_strdup(value);
	*bitflag |= SOUTH_BITMASK;
}
