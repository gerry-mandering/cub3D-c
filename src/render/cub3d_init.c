/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:59:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/17 19:56:11 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_image	create_image(t_vars *vars, int img_w, int img_h)
{
	t_image	img;

	img.img = mlx_new_image(vars->mlx_ptr, img_w, img_h);
	img.img_ptr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
									&img.size_line, &img.endidan);
	img.width = img_w;
	img.height = img_h;
	if (!img.img_ptr)
		error_handler(SYSTEMCALL_ERROR);
	return (img);
}

static void	init_mlx_params(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	mlx_mouse_hide();
	mlx_mouse_move(vars->win_ptr, W_SIZE / 2, H_SIZE / 2);
	mlx_mouse_get_pos(vars->win_ptr, &vars->mouse.x, &vars->mouse.y);
}

static void	init_viewing_angle(t_vars *vars)
{
	if (vars->spawning_direction == NORTH)
		vars->viewing_angle = M_PI + M_PI_2;
	else if (vars->spawning_direction == SOUTH)
		vars->viewing_angle = M_PI_2;
	else if (vars->spawning_direction == EAST)
		vars->viewing_angle = 0;
	else if (vars->spawning_direction == WEST)
		vars->viewing_angle = M_PI;
}

static void	init_wall(t_image *wall, char **wall_path, void *mlx_ptr)
{
	t_direction	direction;
	int			width;
	int			height;

	direction = NORTH;
	while (direction < 4)
	{
		wall[direction].img = mlx_xpm_file_to_image(mlx_ptr, \
										wall_path[direction], &width, &height);
		if (wall[direction].img == NULL)
			error_handler(INVALID_IMAGE_PATH);
		wall[direction].img_ptr = mlx_get_data_addr(wall[direction].img, \
											&wall[direction].bits_per_pixel, \
											&wall[direction].size_line, \
											&wall[direction].endidan);
		direction++;
	}
}

static void	init_view(t_vars *vars)
{
	vars->view = create_image(vars, W_SIZE, H_SIZE);
}

static void	init_background(t_vars *vars, int ceiling_rgb, int floor_rgb)
{
	int	height;
	int	width;

	vars->background = create_image(vars, W_SIZE, H_SIZE);
	height = 0;
	while (height < H_SIZE)
	{
		width = 0;
		while (width < W_SIZE)
		{
			if (height < H_SIZE / 2)
				ft_pixel_put(&vars->background, width, height, ceiling_rgb);
			else
				ft_pixel_put(&vars->background, width, height, floor_rgb);
			width++;
		}
		height++;
	}
}

static void	init_minimap(t_vars *vars)
{
	vars->minimap.h_size = vars->map_height * TILE_SIZE;
	vars->minimap.w_size = vars->map_width * TILE_SIZE;
	vars->minimap.background_img = \
				create_image(vars, vars->minimap.w_size, vars->minimap.h_size);
	vars->minimap.img = \
				create_image(vars, vars->minimap.w_size, vars->minimap.h_size);
	place_wall(vars);
	render_minimap(vars);
}

void	init_params(t_vars *vars)
{
	init_mlx_params(vars);
	init_viewing_angle(vars);
	init_view(vars);
	init_wall(vars->texture.wall, vars->texture.wall_path, vars->mlx_ptr);
	init_background(vars, vars->texture.ceiling_rgb, vars->texture.floor_rgb);
	init_minimap(vars);
}
