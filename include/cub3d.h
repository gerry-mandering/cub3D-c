/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:15:16 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/14 20:43:50 by jinholee         ###   ########.fr       */
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
void	make_list_map(t_list **list_map, int fd);
void	measure_map_size(t_coord *size, t_list *list_map);
void	allocate_map(t_map_data *map_data);
void	labeling_map(t_map_data *map_data, t_list *list_map);
void	set_player_position(t_map_data *map_data);

//validate_map
void	validate_map(t_map_data *map_data);

//validate_map_utils
t_map	**copy_map(t_map_data *map_data);

//error_handler
void	error_handler(const char *error_type);

//utils
int		count_strings(char **strings);
void	free_strings(char **strings);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(char character);

//hooks
int		key_press(int keycode, t_params *params);
void	update_player_position(int keycode, t_map_data *map_data);
int		wall_collision(void);
int		mouse(t_params *params);

//render
void	raycast(t_vars *vars);

void	plot_low(t_image *img, t_coord from, t_coord to);
void	plot_high(t_image *img, t_coord from, t_coord to);
void	draw_line(t_image *img, t_coord from, t_coord to);

void	ft_pixel_put(t_image *img, int x, int y, unsigned int color);
void	place_player(t_vars *vars);
void	place_wall(t_vars *vars);
void	render_minimap(t_vars *vars);

void	init_params(t_vars *vars);
void	read_images(t_vars *vars);
t_image	create_image(t_vars *vars, int img_w, int img_h);
void	create_minimap(t_vars *vars);

#endif
