/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:33:52 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/23 19:08:33 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../lib/libft/libft.h"

# define SPRITE_COUNT	3

# define NO_OPTION		0
# define REPLACE_PLAYER	1

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
	DONE_TEXTURE_INIT = 63,
	DOOR_BITMASK = 64,
	OBJECT_BITMASK = 128
};

typedef enum e_identifier
{
	ID_NORTH,
	ID_SOUTH,
	ID_EAST,
	ID_WEST,
	ID_FLOOR,
	ID_CEILING,
	ID_DOOR,
	ID_OBJECT
}	t_identifier;

typedef enum e_map_label
{
	NONE = -1,
	ROAD,
	WALL,
	PLAYER,
	DOOR_CLOSED,
	DOOR_OPENED,
	OBJECT,
	VISITED
}	t_map_label;

typedef struct s_image
{
	void	*img;
	char	*img_ptr;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_minimap
{
	t_image	background_img;
	t_image	img;
	t_image	crop;
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
	int		bitflag;
	int		floor_rgb;
	int		ceiling_rgb;
	t_image	wall[4];
	t_image	door;
	t_image	object[SPRITE_COUNT];
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
	int		hit;
}	t_ray;

typedef struct s_vars
{
	t_texture	texture;
	int			**map;
	t_ivec		map_size;
	t_dvec		player_pos;
	double		viewing_angle;
	t_image		view;
	t_image		background;
	t_minimap	minimap;
	t_ivec		mouse_pos;
	void		*mlx_ptr;
	void		*win_ptr;
	size_t		sprite_count;
}	t_vars;

typedef void	(*t_init_texture_fp)(t_vars *vars, char *value);

#endif
