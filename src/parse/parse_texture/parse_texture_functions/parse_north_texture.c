/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_north_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:41:01 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 14:45:38 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_north_texture(t_texture *texture, int *bitflag, char *value)
{
	if (*bitflag & NORTH_TEXTURE)
		error_handler(DUPLICATED_TEXTURE);
	texture->wall[NORTH] = value;
	*bitflag |= NORTH_TEXTURE;
}
