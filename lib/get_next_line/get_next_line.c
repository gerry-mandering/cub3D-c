/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:41:28 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/09 16:00:10 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static int	init(int fd, char **line, t_gnl_info *info)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	else
	{
		*line = 0;
		info->total = 0;
		info->len = 0;
		return (1);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_info	info = {"", BUFFER_SIZE, 0, 0, BUFFER_SIZE};
	char				*line;

	if (!init(fd, &line, &info))
		return (0);
	while (1)
	{
		if ((size_t)info.rbyte == info.index)
		{
			line = join(line, &info);
			info.rbyte = read(fd, info.buffer, BUFFER_SIZE);
			if (buf_end(&line, &info))
				return (line);
			info.index = 0;
		}
		if (info.buffer[info.index] == '\n')
		{
			info.index++;
			info.len++;
			return (join(line, &info));
		}
		info.index++;
		info.len++;
	}
}
