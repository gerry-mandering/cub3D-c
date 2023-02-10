/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:57:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 18:49:46 by minseok2         ###   ########.fr       */
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

static int	ft_isspace(char character)
{
	if (ft_strchr(WHITE_SPACE, character) != NULL)
		return (1);
	else
		return (0);
}

static void	cut_last_spaces(char *line, int length)
{
	int	i;

	i = length - 1;
	while (ft_isspace(line[i]))
		line[i--] = '\0';
}

static void	allocate_map(t_map **map, t_coord size)
{
	int	i;

	map = (t_map **)ft_calloc(size.col, sizeof(t_map *));
	if (map == NULL)
		error_handler(SYSTEMCALL_ERROR);
	i = 0;
	while (i < size.col)
	{
		map[i] = (t_map *)ft_calloc(size.row, sizeof(t_map));
		if (map[i] == NULL)
			error_handler(SYSTEMCALL_ERROR);
		i++;
	}
}

static void	labeling_map(t_map **map, t_coord size, t_list *list_map)
{
	t_coord	coord;

	ft_memset(&coord, 0, sizeof(t_coord));
}

static void	init_map_data(t_map_data *map_data, t_list *list_map)
{
	allocate_map(map_data->map, map_data->size);
	labeling_map(map_data->map, map_data->size, list_map);
}

void	parse_map(t_map_data *map_data, int fd)
{
	t_list	*list_map;
	char	*line;
	int		length;

	ft_memset(&map_data->size, 0, sizeof(t_coord));
	line = skip_newlines(fd);
	while (line != NULL && ft_strcmp(line, "\n") != 0)
	{
		cut_last_spaces(line, ft_strlen(line));
		ft_lstadd_back(&list_map, ft_lstnew(line));
		length = ft_strlen(line);
		if (length > map_data->size.row)
			map_data->size.row = length;
		map_data->size.col++;
		line = get_next_line(fd);
	}
	init_map_data(map_data, list_map);
}