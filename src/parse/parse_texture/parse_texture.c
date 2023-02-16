/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:41:00 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/16 11:42:12 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

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
	error_handler(INVALID_TEXTURE_FORMAT);
	return (-1);
}

static void	check_line_is_null(char *line)
{
	if (line == NULL)
		error_handler(LACKING_TEXTURE_INFO);
}

static int	is_newline(char *line)
{
	if (ft_strcmp(line, "\n") == 0)
	{
		free(line);
		return (1);
	}
	else
		return (0);
}

static void	check_splited_line(char **splited_line)
{
	if (count_strings(splited_line) != 2)
		error_handler(INVALID_TEXTURE_FORMAT);
}

void	parse_texture(t_vars *vars, int fd)
{
	const t_parse_texture_fp	parse_texture_fp[6] = {
		parse_north_texture, parse_south_texture, parse_west_texture, \
		parse_east_texture, parse_floor_rgb, parse_ceiling_rgb
	};
	char						*line;
	char						**splited_line;
	int							bitflag;
	int							fp_index;

	ft_memset(&bitflag, 0, sizeof(int));
	while (bitflag != PARSED_EVERY_TEXTURE)
	{
		line = get_next_line(fd);
		check_line_is_null(line);
		if (is_newline(line))
			continue ;
		splited_line = ft_split(line, WHITE_SPACE);
		free(line);
		check_splited_line(splited_line);
		fp_index = get_fp_index(splited_line[IDENTIFIER]);
		parse_texture_fp[fp_index](vars, &bitflag, splited_line[VALUE]);
		free_strings(splited_line);
	}
}
