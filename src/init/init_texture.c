/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 20:23:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*get_description(int fd)
{
	char	*description;

	while (1)
	{
		description = get_next_line(fd);
		if (description == NULL)
			error_handler(LACKING_TEXTURE_INFO);
		else if (ft_strcmp(description, "\n") == 0)
			free(description);
		else
			return (description);
	}
}

static enum e_identifier	get_identifier(char *str)
{
	enum e_identifier	identifier;
	const char			identifier_arr[8][3] = {"NO", "SO", "WE", "EA", \
												"F", "C", "D", "O"};

	identifier = ID_NORTH;
	while (identifier < 8)
	{
		if (ft_strcmp(str, identifier_arr[identifier]) == 0)
			return (identifier);
		identifier++;
	}
	error_handler(INVALID_IDENTIFIER);
	return (-1);
}

static void	separate_description(char *description, \
							enum e_identifier *identifier, char **texture_value)
{
	char	**strings;

	strings = ft_split(description, " ");
	if (strings == NULL)
		error_handler(SYSTEMCALL_ERROR);
	if (count_strings(strings) != 2)
		error_handler(INVALID_TEXTURE_FORMAT);
	*identifier = get_identifier(strings[0]);
	*texture_value = ft_strdup(strings[1]);
	free_strings(strings);
	free(description);
}

void	init_texture(t_vars *vars, int fd)
{
	const t_init_texture_fp	init_texture_fp[8] = {
		init_north, init_south, init_east, init_west, \
		init_floor, init_ceiling, init_door, init_mob
	};
	char					*description;
	char					*texture_value;
	enum e_identifier		identifier;
	int						texture_bitflag;

	texture_bitflag = 0;
	while (texture_bitflag != FINISHED_TEXTURE_INITIALIZE)
	{
		description = get_description(fd);
		separate_description(description, &identifier, &texture_value);
		init_texture_fp[identifier](vars, &texture_bitflag, texture_value);
	}
}
