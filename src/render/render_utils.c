/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:49:10 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/22 01:55:46 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	offset = (y * img->size_line + x * (img->bits_per_pixel / 8));
	dst = img->img_ptr + offset;
	*(unsigned int *)dst = color;
}

void	draw_rect(t_image *image, t_ivec offset, int size, unsigned int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_pixel_put(image, offset.x + x, offset.y + y, color);
			x++;
		}
		y++;
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
