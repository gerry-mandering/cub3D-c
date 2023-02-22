/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:40:57 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 10:41:53 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool	is_direction(char character)
{
	if (character == 'N' || character == 'S' || \
		character == 'E' || character == 'W')
		return (true);
	else
		return (false);
}
