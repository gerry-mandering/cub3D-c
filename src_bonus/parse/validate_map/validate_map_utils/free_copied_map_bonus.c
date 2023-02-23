/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_copied_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:38:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:31:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include_bonus/cub3d_bonus.h"

void	free_copied_map(t_map **copied_map, t_ivec map_size)
{
	int	i;

	i = 0;
	while (i < map_size.y)
	{
		free(copied_map[i]);
		i++;
	}
	free(copied_map);
}
