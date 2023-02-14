/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:27:24 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 11:14:26 by minseok2         ###   ########.fr       */
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

static void	cut_last_spaces(char *line, int length)
{
	int	i;

	i = length - 1;
	while (ft_isspace(line[i]))
		line[i--] = '\0';
}

void	make_list_map(t_list **list_map, int fd)
{
	char	*line;

	*list_map = NULL;
	line = skip_newlines(fd);
	while (line != NULL)
	{
		cut_last_spaces(line, ft_strlen(line));
		ft_lstadd_back(list_map, ft_lstnew(line));
		line = get_next_line(fd);
	}
}
