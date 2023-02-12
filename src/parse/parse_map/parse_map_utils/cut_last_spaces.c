/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_last_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:46:50 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/13 00:47:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3d.h"

void	cut_last_spaces(char *line, int length)
{
	int	i;

	i = length - 1;
	while (ft_isspace(line[i]))
		line[i--] = '\0';
}
