/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:57:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 21:51:33 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_floor_rgb(t_texture *texture, int *bitflag, char *value)
{
	if (*bitflag & FLOOR_RGB)
		error_handler(DUPLICATED_TEXTURE);
	texture->floor_rgb = get_rgb(value);
	*bitflag |= FLOOR_RGB;
}
