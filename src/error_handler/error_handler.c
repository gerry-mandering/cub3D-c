/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:24:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/09 15:33:33 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error_handler(const char *error_type)
{
	write(STDOUT_FILENO, error_type, ft_strlen(error_type));
	write(STDOUT_FILENO, "Error\n", 6);
	exit(1);
}
