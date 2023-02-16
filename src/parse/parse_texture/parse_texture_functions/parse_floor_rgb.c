/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:57:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 11:50:16 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_floor_rgb(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & FLOOR_RGB)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.floor_rgb = get_rgb(value);
	*bitflag |= FLOOR_RGB;
}
