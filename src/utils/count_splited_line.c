/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_splited_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:15:51 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/09 20:16:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_splited_line(char **splited_line)
{
	int	count;

	count = 0;
	while (splited_line != NULL && splited_line[count] != NULL)
		count++;
	return (count);
}
