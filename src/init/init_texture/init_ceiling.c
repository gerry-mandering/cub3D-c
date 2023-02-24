/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:16:49 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 16:28:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_ceiling(t_vars *vars, char *value)
{
	if (vars->texture.bitflag & CEILING_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.ceiling_rgb = get_rgb(value);
	vars->texture.bitflag |= CEILING_BITMASK;
}
