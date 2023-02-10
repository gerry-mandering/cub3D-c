/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:57:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 15:14:10 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static char	*skip_newlines(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			error_handler(HAVE_NO_MAP_INPUT);
		if (ft_strcmp(line, "\n") != 0)
			break ;
	}
	return (line);
}

void	parse_map(t_map_data *map_data, int fd)
{
	char	*line;

	line = skip_newlines(fd);
	while (line != NULL)
	{

		line = get_next_line(fd);
	}
}
