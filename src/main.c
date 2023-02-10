/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 13:04:53 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	usage(void)
{
	printf("usage: cub3d [map_file]");
	return (1);
}

int	key_press(int keycode, t_mlx *mlx)
{
	mlx = 0;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void	read_images(t_mlx *mlx, t_map_data *map_data)
{
	int	w;
	int	h;

	map_data->textures.north_wall = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, NORTH_WALL, &w, &h);
	map_data->textures.south_wall = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, SOUTH_WALL, &w, &h);
	map_data->textures.east_wall = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, EAST_WALL, &w, &h);
	map_data->textures.west_wall = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, WEST_WALL, &w, &h);
	map_data->minimap.bg_img = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, MINIMAP_BG, &w, &h);
	map_data->minimap.wall = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, MINIMAP_WALL, &w, &h);
	map_data->minimap.player = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, MINIMAP_PLAYER, &w, &h);
	if (map_data->textures.north_wall == 0 || \
		map_data->textures.south_wall == 0 || \
		map_data->textures.east_wall == 0 || \
		map_data->textures.west_wall == 0 || \
		map_data->minimap.bg_img == 0 || \
		map_data->minimap.wall == 0 || \
		map_data->minimap.player == 0)
		error_handler(0);
}

int	main(int argc, char **argv)
{
	t_map_data		map_data;
	t_mlx			mlx;

	if (argc != 2)
		error_handler(WRONG_ARGUMENTS_COUNT);
	parse(&map_data, argv);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	read_images(&mlx, &map_data);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, \
							map_data.textures.north_wall, 0, 0);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
