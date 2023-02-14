/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:59:15 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/13 22:11:14 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_params(t_params *params)
{
	t_mlx		*mlx;
	t_map_data	*map_data;
	
	mlx = params->mlx;
	map_data = params->map_data;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	map_data->player_position.direction = M_PI + M_PI_2;
	map_data->minimap.x_offset = 0;
	map_data->minimap.y_offset = 0;
	read_images(mlx, map_data);
	create_minimap(mlx, map_data);
	mlx_mouse_show();
	mlx_mouse_move(mlx->win_ptr, W_SIZE / 2, H_SIZE / 2);
	mlx_mouse_get_pos(mlx->win_ptr, &mlx->mouse.x_pos, &mlx->mouse.y_pos);
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

void	read_images(t_mlx *mlx, t_map_data *map_data)
{
	int	w;
	int	h;

	map_data->texture.wall[NORTH] = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, NORTH_WALL, &w, &h);
	map_data->texture.wall[SOUTH] = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, SOUTH_WALL, &w, &h);
	map_data->texture.wall[EAST] = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, EAST_WALL, &w, &h);
	map_data->texture.wall[WEST] = \
		mlx_xpm_file_to_image(mlx->mlx_ptr, WEST_WALL, &w, &h);
	if (map_data->texture.wall[NORTH] == 0 || \
		map_data->texture.wall[SOUTH] == 0 || \
		map_data->texture.wall[EAST] == 0 || \
		map_data->texture.wall[WEST] == 0)
		error_handler(0);
}

void	create_image(t_mlx *mlx, t_image *img, int img_w, int img_h)
{
	img->img = mlx_new_image(mlx->mlx_ptr, img_w, img_h);
	img->img_ptr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endidan);
	img->width = img_w;
	img->height = img_h;
	if (!img->img_ptr)
		error_handler(SYSTEMCALL_ERROR);
}

void	create_minimap(t_mlx *mlx, t_map_data *map_data)
{
	int	w;
	int	h;

	tmp_make_map(map_data);
	map_data->minimap.h_size = map_data->size.row*TILE_SIZE;
	map_data->minimap.w_size = map_data->size.col*TILE_SIZE;
	create_image(mlx, &map_data->minimap.background_img, map_data->minimap.w_size, map_data->minimap.h_size);
	create_image(mlx, &map_data->minimap.minimap_img, map_data->minimap.w_size, map_data->minimap.h_size);
	h = 0;
	while (h < map_data->size.col)
	{
		w = 0;
		while (w < map_data->size.row)
		{
			if (map_data->map[h][w] == WALL)
				place_wall(&map_data->minimap.background_img, w * TILE_SIZE, h * TILE_SIZE);
			w++;
		}
		h++;
	}
	render_minimap(mlx, map_data);
}