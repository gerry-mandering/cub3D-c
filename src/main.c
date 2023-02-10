/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 15:34:51 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	ft_pixel_put(t_map_data *map_data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= map_data->minimap.w_size || y < 0 || y >= map_data->minimap.h_size)
		return ;
	offset = (y * map_data->minimap.size_line + x * (map_data->minimap.bits_per_pixel / 8));
	dst = map_data->minimap.minimap_img + offset;
	*(unsigned int *)dst = color;
}

void	place_wall(t_map_data *map_data, int w, int h)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			printf("w: %d, h: %d\n", w + j, h + i);
			ft_pixel_put(map_data, w + j, h + i, 0x00ffffff);
			j++;
		}
		i++;
	}
}

void	tmp_make_map(t_map_data *map_data)
{
	map_data->size.row = 10;
	map_data->size.col = 10;
	map_data->player_position.row = 4;
	map_data->player_position.col = 5;
	map_data->map = ft_calloc(1, sizeof(t_map *) * map_data->size.col);
	for (int i=0; i<map_data->size.col; i++)
	{
		map_data->map[i] = ft_calloc(1, sizeof(t_map) * map_data->size.row);
		for (int j=0; j<map_data->size.row; j++)
		{
			if (i == 0 || i + 1 == map_data->size.col || \
				j == 0 || j + 1 == map_data->size.row)
				map_data->map[i][j] = WALL;
			else
				map_data->map[i][j] = EMPTY_SPACE;
		}
	}
	map_data->map[(int)map_data->player_position.row][(int)map_data->player_position.col] = PLAYER;
}

void	draw_minimap(t_mlx *mlx, t_map_data *map_data)
{
	int	w;
	int	h;

	tmp_make_map(map_data);
	map_data->minimap.w_size = map_data->size.row*TILE_SIZE;
	map_data->minimap.h_size = map_data->size.col*TILE_SIZE;
	map_data->minimap.minimap_img = mlx_new_image(mlx->mlx_ptr, map_data->minimap.w_size, map_data->minimap.h_size);
	mlx_get_data_addr(map_data->minimap.minimap_img, &map_data->minimap.size_line, &map_data->minimap.bits_per_pixel, &map_data->minimap.endidan);
	h = 0;
	while (h < map_data->size.col)
	{
		w = 0;
		while (w < map_data->size.row)
		{
			if (map_data->map[h][w] == WALL)
				place_wall(map_data, w * TILE_SIZE, h * TILE_SIZE);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, map_data->minimap.minimap_img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_map_data		map_data;
	t_mlx			mlx;

	if (argc != 2)
		error_handler(WRONG_ARGUMENTS_COUNT);
	// parse(&element_data, &map_data, argv);
	if (argv)
		mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	read_images(&mlx, &map_data);
	draw_minimap(&mlx, &map_data);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
