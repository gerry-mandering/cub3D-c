/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:11:41 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 18:59:58 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_view(t_vars *vars)
{
	vars->view = create_image(vars, W_SIZE, H_SIZE);
}