/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:00:08 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 18:00:27 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
