/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:46:04 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/22 10:44:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//define sprite image count
# define SPRITE_COUNT	3

//define wall direction
enum e_wall_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

//define identifier
enum e_identifier
{
	ID_NORTH,
	ID_SOUTH,
	ID_EAST,
	ID_WEST,
	ID_FLOOR,
	ID_CEILING,
	ID_DOOR,
	ID_MOB
};

//define texture bitmask
enum e_texture_bitmask
{
	NORTH_BITMASK = 1,
	SOUTH_BITMASK = 2,
	EAST_BITMASK = 4,
	WEST_BITMASK = 8,
	FLOOR_BITMASK = 16,
	CEILING_BITMASK = 32,
	FINISHED_TEXTURE_INITIALIZE = 63
};

//define color bits
enum e_rgb
{
	RED = 16,
	GREEN = 8,
	BLUE = 0
};

//define map elements
enum e_map_label
{
	NONE = -1,
	ROAD,
	WALL,
	PLAYER,
	DOOR,
	MOB,
	VISITED
};

//define integer type vector
typedef struct e_ivec
{
	int	x;
	int	y;
}	t_ivec;

//define double type vector
typedef struct e_dvec
{
	double	x;
	double	y;
}	t_dvec;

//define image structure
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

//define texture asset structure
typedef struct s_texture
{
	int		floor_rgb;
	int		ceiling_rgb;
	t_image	wall[4];
	t_image	door;
	t_image	mob_sprite[SPRITE_COUNT];
}	t_texture;

//define game variables
typedef struct s_vars
{
	t_texture	texture;
	int			**map;
	t_ivec		map_size;
	t_dvec		player_pos;
	double		angle_of_view;
	t_ivec		previous_mouse_pos;
	t_image		view;
	t_image		background;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_vars;

typedef void	(*t_init_texture_fp)(t_vars *vars, \
									int *texture_bitflag, char *texture_value);

#endif
