/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:15:16 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 17:05:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "const.h"
# include "struct.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

//parse
void	parse(t_map_data *map_data, char **argv);

//parse_texture
void	parse_texture(t_texture *texture, int fd);

//parse_texture_functions
void	parse_north_texture(t_texture *texture, int *bitflag, char *value);
void	parse_south_texture(t_texture *texture, int *bitflag, char *value);
void	parse_west_texture(t_texture *texture, int *bitflag, char *value);
void	parse_east_texture(t_texture *texture, int *bitflag, char *value);
void	parse_floor_rgb(t_texture *texture, int *bitflag, char *value);
void	parse_ceiling_rgb(t_texture *texture, int *bitflag, char *value);

//parse_texture_utils
int		get_rgb(char *value);

//parse_map
void	parse_map(t_map_data *map_data, int fd);

//error_handler
void	error_handler(const char *error_type);

//utils
int		count_strings(char **strings);
void	free_strings(char **strings);
int		ft_strcmp(const char *s1, const char *s2);

//render

#endif
