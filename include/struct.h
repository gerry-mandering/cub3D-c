/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:33:52 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/17 20:38:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../lib/libft/libft.h"

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_direction;

typedef struct s_ivec
{
	int	x;
	int	y;
}	t_ivec;

typedef struct s_dvec
{
	double	x;
	double	y;
}	t_dvec;

enum e_rgb
{
	BLUE = 0,
	GREEN = 8,
	RED = 16
};

enum e_texture_bitmask
{
	NORTH_BITMASK = 1,
	SOUTH_BITMASK = 2,
	WEST_BITMASK = 4,
	EAST_BITMASK = 8,
	FLOOR_BITMASK = 16,
	CEILING_BITMASK = 32,
	DOOR_BITMASK = 64,
	PARSED_EVERY_TEXTURE = 127
};

typedef enum e_map
{
	NONE = -1,
	EMPTY_SPACE,
	WALL,
	PLAYER,
	DOOR,
	VISITED
}	t_map;

typedef enum e_door_state
{
	OPEN,
	CLOSE
}	t_door_state;

typedef struct s_door
{
	t_door_state	state;
}	t_door;

typedef struct s_image
{
	void	*img;
	char	*img_ptr;
	int		size_line;
	int		bits_per_pixel;
	int		endidan;
	int		width;
	int		height;
}	t_image;

typedef struct s_minimap
{
	t_image	background_img;
	t_image	img;
	void	*empty_space;
	void	*wall;
	void	*player;
	int		x_scale;
	int		y_scale;
	int		w_size;
	int		h_size;
}	t_minimap;

typedef struct s_texture
{
	char	*wall_path[4];
	char	*door_path;
	t_image	wall[4];
	t_image	door;
	int		floor_rgb;
	int		ceiling_rgb;
}	t_texture;

typedef struct s_ray
{
	t_dvec	start;
	t_dvec	length;
	t_dvec	delta;
	t_dvec	unit_step;
	t_dvec	intersection;
	t_ivec	step;
	t_ivec	map_check;
	t_ivec	offset;
	double	dir;
	double	dist;
	double	perp_wall_dist;
	int		collision_direction;
}	t_ray;

typedef struct s_vars
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			**map_elem;
	int			map_width;
	int			map_height;
	double		viewing_angle;
	t_image		view;
	t_image		background;
	t_dvec		player;
	t_direction	spawning_direction;
	t_minimap	minimap;
	t_texture	texture;
	t_ivec		mouse;
}	t_vars;

typedef void	(*t_parse_texture_fp)(t_vars *vars, int *bitflag, char *value);

#endif
