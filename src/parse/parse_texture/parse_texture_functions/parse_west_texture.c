/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_west_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 11:52:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_west_texture(t_vars *vars, int *bitflag, char *value)
{
	if (*bitflag & WEST_TEXTURE)
		error_handler(DUPLICATED_TEXTURE);
	vars->texture.wall[WEST] = \
					mlx_xpm_file_to_image(vars->mlx_ptr, value, NULL, NULL);
	if (vars->texture.wall[WEST] == NULL)
		error_handler(INVALID_IMAGE_PATH);
	*bitflag |= WEST_TEXTURE;
}
