/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_west_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 14:45:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_west_texture(t_texture *texture, int *bitflag, char *value)
{
	if (*bitflag & WEST_TEXTURE)
		error_handler(DUPLICATED_TEXTURE);
	texture->wall[WEST] = value;
	*bitflag |= WEST_TEXTURE;
}
