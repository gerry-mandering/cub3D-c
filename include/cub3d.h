/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:15:16 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/17 20:19:59 by jinholee         ###   ########.fr       */
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
void		parse(t_vars *vars, char **argv);

//parse_texture
void		parse_texture(t_vars *vars, int fd);

//parse_texture_functions
void		parse_north(t_vars *vars, int *bitflag, char *value);
void		parse_south(t_vars *vars, int *bitflag, char *value);
void		parse_west(t_vars *vars, int *bitflag, char *value);
void		parse_east(t_vars *vars, int *bitflag, char *value);
void		parse_floor(t_vars *vars, int *bitflag, char *value);
void		parse_ceiling(t_vars *vars, int *bitflag, char *value);

//parse_texture_utils
int			get_rgb(char *value);

//parse_map
void		parse_map(t_vars *vars, int fd);
void		make_list_map(t_list **list_map, int fd);
void		measure_map_size(int *map_width, int *map_height, t_list *list_map);
void		allocate_map(t_vars *vars);
void		labeling_map(t_vars *vars, t_list *list_map);
void		set_player_position(t_vars *vars);

//validate_map
void		validate_map(t_vars *vars);

//validate_map_utils
t_map		**copy_map(t_vars *vars);
void		free_copied_map(t_map **copied_map, t_ivec map_size);

//error_handler
void		error_handler(const char *error_type);

//utils
int			count_strings(char **strings);
void		free_strings(char **strings);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(char character);

//hooks
int			key_press(int keycode, t_vars *vars);
void		update_player_position(int keycode, t_vars *vars);
int			wall_collision(t_vars *vars, t_dvec delta);
int			mouse(t_vars *vars);

//render
void		raycast(t_vars *vars, double ray_dir);
void		FOV(t_vars *vars);

void		plot_low(t_image *img, t_dvec from, t_dvec to);
void		plot_high(t_image *img, t_dvec from, t_dvec to);
void		draw_line(t_image *img, t_dvec from, t_dvec to);

void		ft_pixel_put(t_image *img, int x, int y, unsigned int color);
void		place_player(t_vars *vars);
void		place_wall(t_vars *vars);
void		draw_rect(t_image *image, \
								t_ivec offset, int size, unsigned int color);
void		render_minimap(t_vars *vars);

//init_params
void		init_params(t_vars *vars);

t_direction	get_collision_direction(t_ivec wall_location, \
													t_dvec collision_point);

int	render(t_vars *vars);
#endif
