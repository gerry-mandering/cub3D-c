/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:06:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 20:07:14 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
		free(strings[i++]);
	free(strings);
}
