/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:11:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/09 20:59:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

#define IDENTIFIER	0
#define VALUE		1

static int	get_fp_index(char *identifier)
{
	const char	identifier_arr[6][3] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;

	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(identifier, identifier_arr[i]) == 0)
			return (i);
		i++;
	}
	error_handler(INVALID_ELEMENT_FORMAT);
	return (-1);
}

void	parse_element(t_element_data *element_data, int fd)
{
	const t_parse_element_fp	*parse_element_fp[6] = {
		parse_north_texture, parse_south_texture, \
		parse_west_texture, parse_east_texture, \
		parse_floor_rgb, parse_ceiling_rgb
	}
	char						*line;
	char						**splited_line;
	int							bitflag;
	int							fp_index;

	ft_memset(&bitflag, 0, sizeof(int));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		splited_line = ft_split(line, WHITE_SPACE);
		if (count_splited_line(splited_line) != 2)
			error_handler(INVALID_ELEMENT_FORMAT);
		fp_index = get_fp_index(splited_line[IDENTIFIER]);
		parse_element_fp[fp_index](element_data, &bitflag, splited_line[VALUE]);
	}
}

void	parse_map(t_map_data *map_data, int fd)
{

}

void	parse(t_map_data *map_data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handler(SYSTEMCALL_ERROR);
	parse_element(element_data, fd);
}
