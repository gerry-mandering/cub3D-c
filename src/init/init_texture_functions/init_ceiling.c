/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:05:09 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:06:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_ceiling(t_vars *vars, int *texture_bitflag, char *texture_value)
{
	if (*texture_bitflag & CEILING_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.ceiling_rgb = get_rgb(texture_value);
	*texture_bitflag |= CEILING_BITMASK;
}
