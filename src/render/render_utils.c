/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:49:10 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/23 19:58:40 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rect(t_image *image, t_ivec offset, int size, unsigned int color)
{
	t_ivec	index;
	t_ivec	draw_pos;

	index.y = 0;
	while (index.y < size)
	{
		index.x = 0;
		while (index.x < size)
		{
			draw_pos.x = offset.x + index.x;
			draw_pos.y = offset.y + index.y;
			put_pixel(image, draw_pos, color);
			index.x++;
		}
		index.y++;
	}
}

unsigned int	get_color_value(t_image *img, t_ivec offset)
{
	unsigned int	color;
	char			*dst;

	dst = img->img_ptr + (offset.y * img->size_line) \
		+ offset.x * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	return (color);
}
