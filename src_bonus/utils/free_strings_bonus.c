/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strings_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:03:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:27:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings != NULL && strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}
