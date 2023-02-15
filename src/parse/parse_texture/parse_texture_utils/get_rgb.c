/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:10:51 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 22:00:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

static int	get_component_value(char *rgb_component)
{
	int		value;
	size_t	i;

	i = 0;
	while (i < ft_strlen(rgb_component))
	{
		if (!ft_isdigit(rgb_component[i]))
			error_handler(INVALID_RGB_FORMAT);
		i++;
	}
	value = ft_atoi(rgb_component);
	if (!(value >= 0 && value <= 255))
		error_handler(INVALID_RGB_FORMAT);
	return (value);
}

int	get_rgb(char *value)
{
	int		rgb;
	char	**rgb_components;

	rgb_components = ft_split(value, ",");
	if (count_strings(rgb_components) != 3)
		error_handler(INVALID_RGB_FORMAT);
	ft_memset(&rgb, 0, sizeof(int));
	rgb |= get_component_value(rgb_components[0]) << RED;
	rgb |= get_component_value(rgb_components[1]) << GREEN;
	rgb |= get_component_value(rgb_components[2]) << BLUE;
	free_strings(rgb_components);
	return (rgb);
}
