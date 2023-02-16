/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_north_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:41:01 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 11:50:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_north_texture(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & NORTH_TEXTURE)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall[NORTH] = \
					mlx_xpm_file_to_image(vars->mlx_ptr, value, NULL, NULL);
	if (vars->texture.wall[NORTH] == NULL)
		error_handler(INVALID_IMAGE_PATH);
	*bitflag |= NORTH_TEXTURE;
}
