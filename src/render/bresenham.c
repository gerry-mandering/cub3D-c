/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:47:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/14 21:30:35 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	plot_low(t_image *img, t_dvec from, t_dvec to)
{
	int	dx;
	int	dy;
	int	yi;
	int	p;

	dx = (int)(to.x - from.x);
	dy = (int)(to.y - from.y);
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p = 2 * dy - dx;
	while (from.y < to.y)
	{
		ft_pixel_put(img, from.x++, from.y, 0xff00);
		if (p > 0)
		{
			from.y += yi;
			p += 2 * (dy - dx);
		}
		else
			p += 2 * dy;
	}
}

void	plot_high(t_image *img, t_dvec from, t_dvec to)
{
	int	dx;
	int	dy;
	int	xi;
	int	p;

	dx = (int)(to.y - from.y);
	dy = (int)(to.x - from.x);
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p = 2 * dx - dy;
	while (from.x < to.x)
	{
		ft_pixel_put(img, from.y, from.x++, 0xff00);
		if (p > 0)
		{
			from.y += xi;
			p += 2 * (dx - dy);
		}
		else
			p += 2 * dx;
	}
}

void	draw_line(t_image *img, t_dvec from, t_dvec to)
{
	int	dx;
	int	dy;

	dx = (int)(to.x - from.x);
	dy = (int)(to.y - from.y);
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (dy < dx)
	{
		if (from.x > to.x)
			plot_low(img, to, from);
		else
			plot_low(img, from, to);
	}
	else
	{
		if (from.y > to.y)
			plot_high(img, to, from);
		else
			plot_high(img, from, to);
	}
}
