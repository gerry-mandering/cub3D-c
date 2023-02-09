/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:15:16 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/09 16:35:27 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "const.h"
# include "struct.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

//parse_map
void	parse(t_element_data *element_data, t_map_data *map_data);
//error_handler
void	error_handler(const char *error_type);

#endif
