/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:33:52 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/15 21:13:36 by jinholee         ###   ########.fr       */
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
	NORTH_TEXTURE = 1,
	SOUTH_TEXTURE = 2,
	WEST_TEXTURE = 4,
	EAST_TEXTURE = 8,
	FLOOR_RGB = 16,
	CEILING_RGB = 32,
	PARSED_EVERY_TEXTURE = 63
};

typedef enum e_map
{
	NONE = -1,
	EMPTY_SPACE,
	WALL,
	PLAYER,
	VISITED
}	t_map;

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
	char	*wall[4];
	void	*wall_img_ptr[4];
	int		floor_rgb;
	int		ceiling_rgb;
}	t_texture;

typedef void	(*t_parse_texture_fp)(t_texture *texture, \
										int *bitflag, char *value);

typedef struct s_vars
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			**map_elem;
	int			map_width;
	int			map_height;
	double		viewing_angle;
	t_image		view;
	t_dvec		player;
	t_direction	spawning_direction;
	t_image		view;
	t_minimap	minimap;
	t_texture	texture;
	t_ivec		mouse;
}	t_vars;

#endif
