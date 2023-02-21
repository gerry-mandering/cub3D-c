/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:45:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:33:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_extension_format(char *file)
{
	char	*extension;
	int		length;

	length = ft_strlen(file);
	extension = file + (length - 4);
	if (ft_strncmp(extension, ".cub", 4) != 0)
		error_handler(INVALID_EXTENSION);
}

static int	open_scene_description_file(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error_handler(WRONG_ARGUMENTS_COUNT);
	check_extension_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handler(SYSTEMCALL_ERROR);
	return (fd);
}

void	init(t_vars *vars, int argc, char **argv)
{
	int	fd;

	fd = open_scene_description_file(argc, argv);
	ft_memset(vars, 0, sizeof(t_vars));
	init_texture(vars, fd);
	init_map(vars, fd);
}
