/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_copied_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:38:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 19:21:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	free_copied_map(int **copied_map, t_ivec map_size)
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
