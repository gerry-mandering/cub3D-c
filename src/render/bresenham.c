/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:47:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/13 21:47:53 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	plot_low(t_image *img, t_coord from, t_coord to)
{
	int	dx;
	int	dy;
	int	yi;
	int	p;

	dx = (int)(to.col - from.col);
	dy = (int)(to.row - from.row);
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p = 2 * dy - dx;
	while (from.col < to.col)
	{
		ft_pixel_put(img, from.col++, from.row, 0xff00);
		if (p > 0)
		{
			from.row += yi;
			p += 2 * (dy - dx);
		}
		else
			p += 2 * dy;
	}
}

void	plot_high(t_image *img, t_coord from, t_coord to)
{
	int	dx;
	int	dy;
	int	xi;
	int	p;

	dx = (int)(to.col - from.col);
	dy = (int)(to.row - from.row);
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p = 2 * dx - dy;
	while (from.row < to.row)
	{
		ft_pixel_put(img, from.col, from.row++, 0xff00);
		if (p > 0)
		{
			from.col += xi;
			p += 2 * (dx - dy);
		}
		else
			p += 2 * dx;
	}
}

void	draw_line(t_image *img, t_coord from, t_coord to)
{
	int	dx;
	int	dy;

	dx = (int)(to.col - from.col);
	dy = (int)(to.row - from.row);
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (dy < dx)
	{
		if (from.col > to.col)
			plot_low(img, to, from);
		else
			plot_low(img, from, to);
	}
	else
	{
		if (from.row > to.row)
			plot_high(img, to, from);
		else
			plot_high(img, from, to);
	}
}
