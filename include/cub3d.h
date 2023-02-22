/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:40 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 11:52:39 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "library.h"
# include "keymapping.h"
# include "errormsg.h"
# include "setting.h"
# include "struct.h"

//init
void	init(t_vars *vars, int argc, char **argv);

//init_texture
void	init_texture(t_vars *vars, int fd);

//init_texture_functions
void	init_north(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_south(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_east(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_west(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_floor(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_ceiling(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_door(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_mob(t_vars *vars, int *texture_bitflag, char *texture_value);

//init_map
void	init_map(t_vars *vars, int fd);

//init_map_functions
void	make_list_map(t_list **list_map, int fd);
void	init_map_size(t_vars *vars, t_list *list_map);
void	allocate_map(t_vars *vars);
void	labeling_map(t_vars *vars, t_list *list_map);
void	init_player_position(t_vars *vars);
void	init_angle_of_view(t_vars *vars, t_list *list_map);
void	init_view(t_vars *vars);
void	init_background(t_vars *vars);
void	init_mlx(t_vars *vars);

//init_utils
int		count_strings(char **strings);
void	free_strings(char **strings);
int		get_rgb(char *texture_value);
bool	is_direction(char character);
t_image	create_image(t_vars *vars, int width, int height);
void	put_pixel(t_image *image, t_ivec vector, unsigned int color);

//game_logic
int		exit_game(t_vars *vars);

//error_handler
void	error_handler(const char *errormsg);

#endif
