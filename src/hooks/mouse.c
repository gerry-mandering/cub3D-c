/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:57:44 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/21 16:47:57 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	render(t_vars *vars)
{
	ft_memcpy(vars->view.img_ptr, vars->background.img_ptr, sizeof(int) * W_SIZE * H_SIZE);
	render_minimap(vars);
	FOV(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->view.img, 0, 0);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->minimap.img.img, MINIMAP_XOFFSET, MINIMAP_YOFFSET);
	return (0);
}

int	mouse(t_vars *vars)
{
	int		cur_x;
	int		cur_y;

	mlx_mouse_get_pos(vars->win_ptr, &cur_x, &cur_y);
	if (cur_x >= W_SIZE - 1)
	{
		mlx_mouse_move(vars->win_ptr, W_SIZE, cur_y);
		vars->viewing_angle += ROTATE_SPEED;
	}
	else if (cur_x <= 0)
	{
		mlx_mouse_move(vars->win_ptr, 0, cur_y);
		vars->viewing_angle -= ROTATE_SPEED;
	}
	if (vars->viewing_angle < 0)
		vars->viewing_angle += 2 * M_PI;
	else if (vars->viewing_angle > 2 * M_PI)
		vars->viewing_angle -= 2 * M_PI;
	render(vars);
	return (0);
}
