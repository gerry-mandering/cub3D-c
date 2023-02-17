/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:40:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 20:41:27 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_door(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & DOOR_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.door_path = ft_strdup(value);
	*bitflag |= DOOR_BITMASK;
}
