/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/09 16:37:47 by jinholee         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_element_data	element_data;
	t_map_data		map_data;
	t_mlx			mlx;

	if (argc != 2)
		return (usage());
	printf("%s\n", argv[1]);
	parse(&element_data, &map_data);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_SIZE, H_SIZE, "cub3D");
	mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, &mlx.size_line, &mlx.endian);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
