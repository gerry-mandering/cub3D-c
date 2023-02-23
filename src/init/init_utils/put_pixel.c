/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:06:23 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 19:06:29 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	put_pixel(t_image *img, t_ivec vector, unsigned int color)
{
	char	*dst;
	int		offset;

	if (vector.x < 0 || vector.x >= img->width || \
		vector.y < 0 || vector.y >= img->height)
		return ;
	offset = (vector.y * img->size_line + vector.x * (img->bits_per_pixel / 8));
	dst = img->img_ptr + offset;
	*(unsigned int *)dst = color;
}
