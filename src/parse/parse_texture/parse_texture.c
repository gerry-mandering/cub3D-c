/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:41:00 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/20 14:53:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	get_fp_index(char *identifier)
{
	const char	identifier_arr[8][3] = \
								{"NO", "SO", "WE", "EA", "F", "C", "D", "O"};
	int			i;

	i = 0;
	while (i < 8)
	{
		if (ft_strcmp(identifier, identifier_arr[i]) == 0)
			return (i);
		i++;
	}
	error_handler(INVALID_IDENTIFIER);
	return (-1);
}

static void	store_texture_info(t_vars *vars, int *bitflag, char *line)
{
	const t_parse_texture_fp	parse_texture_fp[8] = {
		parse_north, parse_south, parse_west, parse_east, \
		parse_floor, parse_ceiling, parse_door, parse_object
	};
	int							fp_index;
	char						**splited_line;
	char						*identifier;
	char						*value;

	splited_line = ft_split(line, WHITE_SPACE);
	if (count_strings(splited_line) != 2)
		error_handler(INVALID_TEXTURE_FORMAT);
	identifier = splited_line[0];
	value = splited_line[1];
	fp_index = get_fp_index(identifier);
	parse_texture_fp[fp_index](vars, bitflag, value);
	free_strings(splited_line);
	free(line);
}

void	parse_texture(t_vars *vars, int fd)
{
	char				*line;
	int					bitflag;

	bitflag = 0;
	while (bitflag != PARSED_EVERY_TEXTURE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			error_handler(LACKING_TEXTURE_INFO);
		if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		store_texture_info(vars, &bitflag, line);
	}
}
