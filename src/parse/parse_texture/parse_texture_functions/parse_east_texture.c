/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_east_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 11:49:45 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_east_texture(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & EAST_TEXTURE)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall[EAST] = \
					mlx_xpm_file_to_image(vars->mlx_ptr, value, NULL, NULL);
	if (vars->texture.wall[EAST] == NULL)
		error_handler(INVALID_IMAGE_PATH);
	*bitflag |= EAST_TEXTURE;
}
