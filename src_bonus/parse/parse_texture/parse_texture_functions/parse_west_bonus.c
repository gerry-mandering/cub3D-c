/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_west_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:36:02 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	parse_west(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & WEST_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall_path[WEST] = ft_strdup(value);
	*bitflag |= WEST_BITMASK;
}
