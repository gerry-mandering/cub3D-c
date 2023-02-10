/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 18:15:40 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	place_wall(t_image	*img, int w, int h)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			ft_pixel_put(img, w + j, h + i, WALL_COLOR);
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

void	place_player(t_image *img, int w, int h)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			ft_pixel_put(img, w + j, h + i, PLAYER_COLOR);
			j++;
		}
		i++;
	}
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

void	draw_minimap(t_mlx *mlx, t_map_data *map_data)
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
	ft_memcpy(map_data->minimap.minimap_img.img_ptr, map_data->minimap.background_img.img_ptr, map_data->minimap.w_size * map_data->minimap.h_size * sizeof(int));
	place_player(&map_data->minimap.minimap_img, map_data->player_position.col, map_data->player_position.row);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, map_data->minimap.minimap_img.img, 0, 0);
}

int	wall_collision(void)
{
	return (0);
}

void	update_player_position(int keycode, t_coord *position)
{
	if (keycode == KEY_W && !wall_collision())
		position->row -= TILE_SIZE;
	else if (keycode == KEY_S && !wall_collision())
		position->row += TILE_SIZE;
	else if (keycode == KEY_A && !wall_collision())
		position->col -= TILE_SIZE;
	else if (keycode == KEY_D && !wall_collision())
		position->col += TILE_SIZE;
}

int	key_press(int keycode, t_params *params)
{
	t_mlx		*mlx = params->mlx;
	t_map_data	*map_data = params->map_data;

	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		update_player_position(keycode, &map_data->player_position);
	ft_memcpy(map_data->minimap.minimap_img.img_ptr, map_data->minimap.background_img.img_ptr, map_data->minimap.w_size * map_data->minimap.h_size * sizeof(int));
	place_player(&map_data->minimap.minimap_img, map_data->player_position.col, map_data->player_position.row);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, map_data->minimap.minimap_img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params		params;
	t_map_data		map_data;
	t_mlx			mlx;

	if (!argv || argc != 2)
		error_handler(WRONG_ARGUMENTS_COUNT);
	//parse(&map_data, argv);
	params.mlx = &mlx;
	params.map_data = &map_data;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	read_images(&mlx, &map_data);
	draw_minimap(&mlx, &map_data);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &params);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
