/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 11:17:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	put_pixel(t_image *image, t_ivec vector, unsigned int color)
{
	int	offset;

	if (vector.y < 0 || vector.x < 0 || \
		vector.x >= image->width || vector.y >= image->height)
		return ;
	offset = (image->size_line * vector.y) + \
			(vector.x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->img_ptr + offset) = color;
}
