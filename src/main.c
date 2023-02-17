/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 16:07:53 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_direction	get_collision_direction(t_ivec wall_location, \
											t_dvec collision_point)
{
	if (fabs((double)wall_location.x - collision_point.x) < 0.0000001)
		return (WEST);
	else if (fabs((double)wall_location.x + 1 - collision_point.x) < 0.0000001)
		return (EAST);
	else if (fabs((double)wall_location.y - collision_point.y) < 0.0000001)
		return (NORTH);
	else if (fabs((double)wall_location.y + 1 - collision_point.y) < 0.0000001)
		return (SOUTH);
	else
	{
		printf("wall x:%d, y:%d, hit x:%.20f, y:%.20f\n", wall_location.x, wall_location.y, collision_point.x, collision_point.y);
		//printf("ERROR - testcode");
		return (-1);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!argv || argc != 2)
		error_handler(WRONG_ARGUMENTS_COUNT);
	parse(&vars, argv);
	init_params(&vars);
	mlx_hook(vars.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &vars);
	mlx_loop_hook(vars.mlx_ptr, &mouse, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
