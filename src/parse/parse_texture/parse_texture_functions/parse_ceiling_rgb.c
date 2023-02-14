/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ceiling_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:58:57 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 21:51:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_ceiling_rgb(t_texture *texture, int *bitflag, char *value)
{
	if (*bitflag & CEILING_RGB)
		error_handler(DUPLICATED_TEXTURE);
	texture->ceiling_rgb = get_rgb(value);
	*bitflag |= CEILING_RGB;
}
