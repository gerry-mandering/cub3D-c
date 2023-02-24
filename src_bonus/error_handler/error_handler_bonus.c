/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:24:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:09:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	error_handler(const char *error_type)
{
	write(STDOUT_FILENO, "Error\n", 6);
	if (error_type == SYSTEMCALL_ERROR)
		perror(error_type);
	else
		write(STDOUT_FILENO, error_type, ft_strlen(error_type));
	exit(EXIT_FAILURE);
}
