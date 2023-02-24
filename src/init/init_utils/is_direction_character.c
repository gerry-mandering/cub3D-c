/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_direction_character.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:54:05 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 18:55:02 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool	is_direction_character(char character)
{
	if (character == 'N' || character == 'S' || \
		character == 'E' || character == 'W')
		return (true);
	else
		return (false);
}
