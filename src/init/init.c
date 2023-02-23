/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:29:53 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 18:38:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_arguments_count(int argc)
{
	if (argc != 2)
		error_handler(WRONG_ARGUMENTS_COUNT);
}

static void	check_extension_format(char *file_path)
{
	char	*extension;
	int		length;

	length = ft_strlen(file_path);
	extension = file_path + (length - 4);
	if (ft_strncmp(extension, ".cub", 4) != 0)
		error_handler(INVALID_EXTENSION);
}

static int	open_description_file(int argc, char **argv)
{
	int	fd;

	check_arguments_count(argc);
	check_extension_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handler(SYSTEMCALL_ERROR);
	return (fd);
}

void	init(t_vars *vars, int argc, char **argv)
{
	int	fd;

	fd = open_description_file(argc, argv);
	ft_memset(vars, 0, sizeof(t_vars));
	init_texture(vars, fd);
	init_map(vars, fd);
}
