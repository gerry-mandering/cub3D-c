/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_north_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:41:01 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:35:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	parse_north(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & NORTH_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall_path[NORTH] = ft_strdup(value);
	*bitflag |= NORTH_BITMASK;
}
