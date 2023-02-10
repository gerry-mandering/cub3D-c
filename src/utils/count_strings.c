/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_splited_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:15:51 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 14:44:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_strings(char **strings)
{
	int	count;

	count = 0;
	while (strings != NULL && strings[count] != NULL)
		count++;
	return (count);
}
