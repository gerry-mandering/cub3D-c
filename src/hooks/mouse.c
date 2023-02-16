/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:57:44 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/15 22:09:26 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	mouse(t_vars *vars)
{
	int		cur_x;
	int		cur_y;

	mlx_mouse_get_pos(vars->win_ptr, &cur_x, &cur_y);
	if (vars->mouse.x >= W_SIZE || (vars->mouse.x < cur_x && cur_x < W_SIZE))
		vars->viewing_angle -= MOUSE_SPEED;
	else if (vars->mouse.x <= 0 || (vars->mouse.x > cur_x && cur_x > 0))
		vars->viewing_angle += MOUSE_SPEED;
	if (vars->viewing_angle < 0)
		vars->viewing_angle += 2 * M_PI;
	else if (vars->viewing_angle > 2 * M_PI)
		vars->viewing_angle -= 2 * M_PI;
	vars->mouse.x = cur_x;
	vars->mouse.y = cur_y;
	ft_memcpy(vars->view.img_ptr, vars->backgroud.img_ptr, sizeof(int) * W_SIZE * H_SIZE);
	render_minimap(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->view.img, 0, 0);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->minimap.img.img, MINIMAP_XOFFSET, MINIMAP_YOFFSET);
	return (0);
}
