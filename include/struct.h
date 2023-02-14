/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:33:52 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/13 21:14:37 by minseok2         ###   ########.fr       */
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

typedef struct s_coord
{
	double	row;
	double	col;
}	t_coord;

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
	t_image	minimap_img;
	void	*empty_space;
	void	*wall;
	void	*player;
	int		x_offset;
	int		y_offset;
	int		x_scale;
	int		y_scale;
	int		w_size;
	int		h_size;
}	t_minimap;

typedef struct s_texture
{
	char	*wall[4];
	int		floor_rgb;
	int		ceiling_rgb;
}	t_texture;

typedef void	(*t_parse_texture_fp)(t_texture *texture, \
										int *bitflag, char *value);

typedef struct s_map_data
{
	t_coord			size;
	t_coord			player_position;
	t_direction		spawning_direction;
	int				**map;
	t_minimap		minimap;
	t_texture		texture;
}	t_map_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*mlx_img;
}	t_mlx;

typedef struct s_params
{
	t_mlx		*mlx;
	t_map_data	*map_data;
}	t_params;

#endif
