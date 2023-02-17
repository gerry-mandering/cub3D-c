/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_west.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 19:12:16 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_west(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & WEST_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall_path[WEST] = ft_strdup(value);
	*bitflag |= WEST_BITMASK;
}
