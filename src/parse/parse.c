/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:11:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 11:11:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_extension_format(char *scene_description_file)
{
	char	*extension;
	int		length;

	length = ft_strlen(scene_description_file);
	extension = scene_description_file + (length - 4);
	if (ft_strncmp(extension, ".cub", 4) != 0)
		error_handler(INVALID_EXTENSION);
}

void	parse(t_map_data *map_data, char **argv)
{
	int	fd;

	ft_memset(map_data, 0, sizeof(t_map_data));
	check_extension_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handler(SYSTEMCALL_ERROR);
	parse_texture(&map_data->texture, fd);
	parse_map(map_data, fd);
	validate_map(map_data);
}
