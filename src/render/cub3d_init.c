/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:59:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/16 15:27:35 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_params(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	vars->viewing_angle = M_PI + M_PI_2;
	vars->view = create_image(vars, W_SIZE, H_SIZE);
	vars->backgroud = create_image(vars, W_SIZE, H_SIZE);
	//read_images(vars);
	create_minimap(vars);
	mlx_mouse_show();
	mlx_mouse_move(vars->win_ptr, W_SIZE / 2, H_SIZE / 2);
	mlx_mouse_get_pos(vars->win_ptr, &vars->mouse.x, &vars->mouse.y);
	vars->texture.ceiling_rgb = 0x00ccff;
	vars->texture.floor_rgb = 0x7ec850;
	// for (int i=0; i<H_SIZE/2; i++)
	// {
	// 	for (int j=0; j<W_SIZE; j++)
	// 		ft_pixel_put(&vars->backgroud, j, i, vars->texture.ceiling_rgb);
	// }
	// for (int i=H_SIZE/2; i<H_SIZE; i++)
	// {
	// 	for (int j=0; j<W_SIZE; j++)
	// 		ft_pixel_put(&vars->backgroud, j, i, vars->texture.floor_rgb);
	// }
}

void	read_images(t_vars *vars)
{
	int	w;
	int	h;

	vars->texture.wall[NORTH] = \
		mlx_xpm_file_to_image(vars->mlx_ptr, NORTH_WALL, &w, &h);
	vars->texture.wall[SOUTH] = \
		mlx_xpm_file_to_image(vars->mlx_ptr, SOUTH_WALL, &w, &h);
	vars->texture.wall[EAST] = \
		mlx_xpm_file_to_image(vars->mlx_ptr, EAST_WALL, &w, &h);
	vars->texture.wall[WEST] = \
		mlx_xpm_file_to_image(vars->mlx_ptr, WEST_WALL, &w, &h);
	if (vars->texture.wall[NORTH] == 0 || \
		vars->texture.wall[SOUTH] == 0 || \
		vars->texture.wall[EAST] == 0 || \
		vars->texture.wall[WEST] == 0)
		error_handler(0);
}

t_image	create_image(t_vars *vars, int img_w, int img_h)
{
	t_image	img;

	img.img = mlx_new_image(vars->mlx_ptr, img_w, img_h);
	img.img_ptr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endidan);
	img.width = img_w;
	img.height = img_h;
	if (!img.img_ptr)
		error_handler(SYSTEMCALL_ERROR);
	return (img);
}

void	create_minimap(t_vars *vars)
{
	vars->minimap.h_size = vars->map_height * TILE_SIZE;
	vars->minimap.w_size = vars->map_width * TILE_SIZE;
	vars->minimap.background_img = create_image(vars, vars->minimap.w_size, vars->minimap.h_size);
	vars->minimap.img = create_image(vars, vars->minimap.w_size, vars->minimap.h_size);
	place_wall(vars);
	render_minimap(vars);
}
