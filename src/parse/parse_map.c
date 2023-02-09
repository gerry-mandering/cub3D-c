/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:11:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/09 16:13:37 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse(t_element_data *element_data, t_map_data *map_data)
{
	element_data->ceiling_rgb.blue = 0;
	map_data->char_map = 0;
}
