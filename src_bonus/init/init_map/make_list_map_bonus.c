/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:33:39 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:14:12 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

static char	*get_map_description(int fd)
{
	char	*map_description;

	while (1)
	{
		map_description = get_next_line(fd);
		if (map_description == NULL)
			error_handler(HAVE_NO_MAP_INPUT);
		else if (ft_strcmp(map_description, "\n") == 0)
			free(map_description);
		else
			return (map_description);
	}
}

static void	cut_last_spaces(char *map_description)
{
	int	last_index;

	last_index = ft_strlen(map_description) - 1;
	while (ft_strchr(" \t\n\v\f\r", map_description[last_index]) != NULL)
		map_description[last_index--] = '\0';
}

void	make_list_map(t_list **list_map, int fd)
{
	char	*map_description;

	*list_map = NULL;
	map_description = get_map_description(fd);
	while (true)
	{
		cut_last_spaces(map_description);
		ft_lstadd_back(list_map, ft_lstnew(map_description));
		map_description = get_next_line(fd);
		if (map_description == NULL)
			break ;
		if (ft_strcmp(map_description, "\n") == 0)
		{
			free(map_description);
			break ;
		}
	}
}
