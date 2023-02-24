/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ceiling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:16:49 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:12:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	init_ceiling(t_vars *vars, char *value)
{
	if (vars->texture.bitflag & CEILING_BITMASK)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.ceiling_rgb = get_rgb(value);
	vars->texture.bitflag |= CEILING_BITMASK;
}
