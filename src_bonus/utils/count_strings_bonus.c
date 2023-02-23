/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strings_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:15:51 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:27:33 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

int	count_strings(char **strings)
{
	int	count;

	count = 0;
	while (strings != NULL && strings[count] != NULL)
		count++;
	return (count);
}
