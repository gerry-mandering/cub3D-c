/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:21:26 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 21:26:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	size_t			length;

	length = 0;
	while (s1[length] != '\0' && s1[length] == s2[length])
		length++;
	if (length == s1_len && length == s2_len)
		return (0);
	else
		return (s1[length] - s2[length]);
}
