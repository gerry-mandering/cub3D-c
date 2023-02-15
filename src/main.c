/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/15 21:13:41 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_direction	get_collision_direction(t_ivec wall_location, t_dvec collision_point)
{
	if ((int)collision_point.x == wall_location.x)
		return (WEST);
	else if ((int)collision_point.y == wall_location.y)
		return (NORTH);
	else if ((int)collision_point.x == wall_location.x + 1)
		return (EAST);
	else if ((int)collision_point.y == wall_location.y + 1)
		return (SOUTH);
	else
	{
		printf("ERROR - testcode");
		return (-1);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!argv || argc != 2)
		error_handler(WRONG_ARGUMENTS_COUNT);
	parse(&vars, argv);
	printf("parse_finished\n");
	init_params(&vars);
	init_view(&vars);
	mlx_hook(vars.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &vars);
	mlx_loop_hook(vars.mlx_ptr, &mouse, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
