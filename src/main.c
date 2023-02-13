/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/13 22:09:46 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	init_params(&params);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &params);
	mlx_loop_hook(mlx.mlx_ptr, &mouse, &params);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
