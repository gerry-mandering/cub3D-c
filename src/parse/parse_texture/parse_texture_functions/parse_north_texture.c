/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_north_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:41:01 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 21:51:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_north_texture(t_texture *texture, int *bitflag, char *value)
{
	if (*bitflag & NORTH_TEXTURE)
		error_handler(DUPLICATED_TEXTURE);
	texture->wall[NORTH] = ft_strdup(value);
	*bitflag |= NORTH_TEXTURE;
}
