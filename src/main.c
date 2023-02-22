/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:37:35 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 11:56:33 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	init(&vars, argc, argv);
	mlx_hook(vars.win_ptr, KEY_PRESS, 0, &key_press, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
