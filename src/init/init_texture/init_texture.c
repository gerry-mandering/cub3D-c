/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:38:18 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 20:15:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static char	*get_description_line(int fd)
{
	char	*description_line;

	while (true)
	{
		description_line = get_next_line(fd);
		if (description_line == NULL)
			error_handler(LACKING_TEXTURE_INFO);
		else if (ft_strcmp(description_line, "\n") == 0)
			free(description_line);
		else
			return (description_line);
	}
}

static t_identifier	get_identifier(char *input)
{
	const char		identifier_arr[8][3] = {
		"NO", "SO", "EA", "WE", "F", "C", "D", "O"};
	t_identifier	identifier;

	identifier = ID_NORTH;
	while (identifier < 8)
	{
		if (ft_strcmp(input, identifier_arr[identifier]) == 0)
			return (identifier);
		identifier++;
	}
	error_handler(INVALID_IDENTIFIER);
	return (-1);
}

static void	separate_description_line(char *description_line, \
										t_identifier *identifier, char **value)
{
	char	**strings;

	strings = ft_split(description_line, " \t\n\v\f\r");
	if (strings == NULL)
		error_handler(SYSTEMCALL_ERROR);
	if (count_strings(strings) != 2)
		error_handler(INVALID_TEXTURE_FORMAT);
	*identifier = get_identifier(strings[0]);
	*value = ft_strdup(strings[1]);
	free_strings(strings);
	free(description_line);
}

void	init_texture(t_vars *vars, int fd)
{
	const t_init_texture_fp	init_texture_fp[8] = {
		init_north, init_south, init_east, init_west, \
		init_floor, init_ceiling, init_door, init_object
	};
	char					*description_line;
	t_identifier			identifier;
	char					*value;

	while ((vars->texture.bitflag & DONE_TEXTURE_INIT) != DONE_TEXTURE_INIT)
	{
		description_line = get_description_line(fd);
		separate_description_line(description_line, &identifier, &value);
		init_texture_fp[identifier](vars, value);
		free(value);
	}
}
