/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_south_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:53:40 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 14:45:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_south_texture(t_texture *texture, int *bitflag, char *value)
{
	if (*bitflag & SOUTH_TEXTURE)
		error_handler(DUPLICATED_TEXTURE);
	texture->wall[SOUTH] = value;
	*bitflag |= SOUTH_TEXTURE;
}
