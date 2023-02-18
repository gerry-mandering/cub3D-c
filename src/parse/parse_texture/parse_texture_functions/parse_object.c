/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:15:05 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/18 19:11:57 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	parse_object(t_vars *vars, int *bitflag, char *value)
{
	static int	count;

	if (count == 0)
		vars->texture.object_path[0] = ft_strdup(value);
	else
		vars->texture.object_path[1] = ft_strdup(value);
	count++;
	(void)bitflag;
}
