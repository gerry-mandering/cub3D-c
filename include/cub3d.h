/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:15:16 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/23 16:29:29 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "library.h"
# include "setting.h"
# include "keymapping.h"
# include "errormsg.h"

//init
void		init(t_vars *vars, int argc, char **argv);

//init_texture
void		init_mlx(t_vars *vars);
void		init_texture(t_vars *vars, int fd);
void		init_north(t_vars *vars, char *value);
void		init_south(t_vars *vars, char *value);
void		init_east(t_vars *vars, char *value);
void		init_west(t_vars *vars, char *value);
void		init_floor(t_vars *vars, char *value);
void		init_ceiling(t_vars *vars, char *value);
void		init_door(t_vars *vars, char *value);
void		init_object(t_vars *vars, char *value);

//init_map
void		init_map(t_vars *vars, int fd);
void		make_list_map(t_list **list_map, int fd);
void		init_map_size(t_vars *vars, t_list *list_map);
void		allocate_map(t_vars *vars);
void		labeling_map(t_vars *vars, t_list *list_map);
void		init_player_position(t_vars *vars);
void		init_viewing_angle(t_vars *vars, t_list *list_map);

//validate_map
void		validate_map(t_vars *vars);

//validate_map_utils
void		check_map_has_all_texture(t_vars *vars);
void		check_player_is_exist(t_vars *vars);
void		check_player_is_duplicated(t_vars *vars);
void		check_map_is_closed(t_vars *vars);
void		check_door_position(t_vars *vars);
int			**copy_map(t_vars *vars, int option);
void		free_copied_map(int **copied_map, t_ivec map_size);

//init_view
void		init_view(t_vars *vars);

//init_background
void		init_background(t_vars *vars);

//init_minimap
void		init_minimap(t_vars *vars);

//init_utils
int			get_rgb(char *value);
int			count_strings(char **strings);
void		free_strings(char **strings);
bool		is_direction_character(char character);
void		put_pixel(t_image *img, t_ivec vector, unsigned int color);
t_image		create_image(t_vars *vars, int img_w, int img_h);

//hooks
int			key_press(int keycode, t_vars *vars);
void		update_player_position(int keycode, t_vars *vars);
int			wall_collision(t_vars *vars, t_dvec delta);
int			mouse(t_vars *vars);

//render
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
t_image		*get_object_img(t_vars *vars);
void		render_upper_texture(t_vars *vars, t_ray *ray, t_image *img);
void		render_lower_texture(t_vars *vars, t_ray *ray, t_image *img);
void		render_view(t_vars *vars, t_ray *ray, t_ray *obj_ray);

//raycast
void		check_object_hit(t_vars *vars, t_ray *ray, t_ray *obj_ray);
int			check_wall_hit(t_vars *vars, t_ray *ray, t_ray *object_ray);
void		raycast(t_vars *vars, double ray_dir);
void		field_of_view(t_vars *vars);
int			render(t_vars *vars);

//door
t_ivec		get_heading_position(t_vars *vars);
bool		is_near_door(t_vars *vars);

//error_handler
void		error_handler(const char *error_type);

int			render(t_vars *vars);
int			cub3d_exit(t_vars *vars);

#endif
