/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:15:16 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/24 10:56:37 by minseok2         ###   ########.fr       */
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
void		measure_map_size(int *map_width, int *map_height, \
							t_list *list_map);
void		allocate_map(t_vars *vars);
void		labeling_map(t_vars *vars, t_list *list_map);
void		set_player_position(t_vars *vars);

//validate_map
void		validate_map(t_vars *vars);

//validate_map_utils
void		check_player_is_exist(t_vars *vars);
void		check_player_is_duplicated(t_vars *vars);
void		check_map_is_closed(t_vars *vars);
t_map		**copy_map(t_vars *vars);
void		free_copied_map(t_map **copied_map, t_ivec map_size);

//init_params
void		init_params(t_vars *vars);

//init_params_utils
t_image		create_image(t_vars *vars, int img_w, int img_h);
void		init_mlx_params(t_vars *vars);
void		init_viewing_angle(t_vars *vars);
void		init_view(t_vars *vars);
void		init_wall_image(t_image *wall, char **wall_path, void *mlx_ptr);
void		init_background(t_vars *vars, int ceiling_rgb, int floor_rgb);
void		init_minimap(t_vars *vars);

//hooks
int			key_press(int keycode, t_vars *vars);
void		update_player_position(int keycode, t_vars *vars);
int			wall_collision(t_vars *vars, t_dvec delta);
int			mouse(t_vars *vars);

//render
//utils
void		ft_pixel_put(t_image *img, int x, int y, unsigned int color);
void		draw_rect(t_image *image, t_ivec offset, \
						int size, unsigned int color);
t_ray		init_ray(t_vars *vars, double ray_dir);
u_int32_t	get_color_value(t_image *img, t_ivec offset);
t_direction	get_collision_direction(t_ivec wall_location, \
													t_dvec collision_point);

//minimap
void		place_wall(t_vars *vars);
void		place_player(t_vars *vars);
t_ivec		get_crop_offset(t_vars *vars);
void		crop_minimap(t_vars *vars);
void		render_minimap(t_vars *vars);

//view
int			get_texture_xpos(t_ray *ray, t_image *img);
void		render_upper_texture(t_vars *vars, t_ray *ray, t_image *img);
void		render_lower_texture(t_vars *vars, t_ray *ray, t_image *img);
void		render_view(t_vars *vars, t_ray *ray);

//raycast
int			check_wall_hit(t_vars *vars, t_ray *ray);
void		raycast(t_vars *vars, double ray_dir);
void		field_of_view(t_vars *vars);
int			render(t_vars *vars);

//utils
int			count_strings(char **strings);
void		free_strings(char **strings);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(char character);

//error_handler
void		error_handler(const char *error_type);

int			render(t_vars *vars);
int			cub3d_exit(t_vars *vars);

//sprite_image
t_ray		init_ray(t_vars *vars, double ray_dir);

#endif
