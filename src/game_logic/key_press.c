/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:21:21 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 15:54:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_press(int key_code, t_vars *vars)
{
	if (key_code == KEY_ESC)
		exit_game(vars);
	if (key_code == KEY_W || key_code == KEY_A || \
		key_code == KEY_S || key_code == KEY_D)
		update_player_position(key_code, vars);
	else if (key_code == KEY_LEFT_ARROW || key_code == KEY_RIGHT_ARROW)
		update_angle_of_view(key_code, vars);
	render_view(vars);
	return (0);
}
