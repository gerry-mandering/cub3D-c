/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_has_all_texture.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:26:47 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 19:32:14 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	check_map_has_all_texture(t_vars *vars)
{
	t_ivec	index;

	index.y = 0;
	while (index.y < vars->map_size.y)
	{
		index.x = 0;
		while (index.x < vars->map_size.x)
		{
			if (vars->map[index.y][index.x] == DOOR_CLOSED && \
				(vars->texture.bitflag & DOOR_BITMASK) == 0)
					error_handler(HAVE_NO_TEXTURE);
			if (vars->map[index.y][index.x] == OBJECT && \
				(vars->texture.bitflag & OBJECT_BITMASK) == 0)
					error_handler(HAVE_NO_TEXTURE);
			index.x++;
		}
		index.y++;
	}
}
