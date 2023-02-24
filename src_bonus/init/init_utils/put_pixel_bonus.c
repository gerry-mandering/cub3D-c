/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:06:23 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 13:11:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include_bonus/cub3d_bonus.h"

void	put_pixel(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= img->width || \
		y < 0 || y >= img->height)
		return ;
	offset = (y * img->size_line + x * (img->bits_per_pixel / 8));
	dst = img->img_ptr + offset;
	*(unsigned int *)dst = color;
}
