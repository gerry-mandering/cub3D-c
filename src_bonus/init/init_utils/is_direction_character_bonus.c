/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_direction_character_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:54:05 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:11:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

bool	is_direction_character(char character)
{
	if (character == 'N' || character == 'S' || \
		character == 'E' || character == 'W')
		return (true);
	else
		return (false);
}
