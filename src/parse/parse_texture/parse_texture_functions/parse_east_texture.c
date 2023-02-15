/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_east_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 21:50:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_east_texture(t_texture *texture, int *bitflag, char *value)
{
	if (*bitflag & EAST_TEXTURE)
		error_handler(DUPLICATED_TEXTURE);
	texture->wall[EAST] = ft_strdup(value);
	*bitflag |= EAST_TEXTURE;
}
