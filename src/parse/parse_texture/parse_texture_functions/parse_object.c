/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:15:05 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/20 14:50:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_object(t_vars *vars, int *bitflag, char *value)
{
	static int	sprite_count;

	vars->texture.object_path[sprite_count] = ft_strdup(value);
	sprite_count++;
	(void)bitflag;
}
