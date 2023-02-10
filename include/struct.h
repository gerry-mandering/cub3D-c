/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:33:52 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/10 15:27:18 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../lib/libft/libft.h"

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
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

typedef struct s_texture_data
{
	char			*texture_path[4];
	int				floor_rgb;
	int				ceiling_rgb;
}	t_texture_data;

typedef enum e_map
{
	NONE = -1,
	EMPTY_SPACE,
	WALL,
	PLAYER
}	t_map;

typedef struct s_minimap
{
	void	*bg_img;
	void	*wall;
	void	*player;
	int		x_offset;
	int		y_offset;
	int		x_scale;
	int		y_scale;
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
	t_texture_data	texture_data;
	t_coord			size;
	t_coord			player_position;
	t_direction		spawning_orientation;
	t_list			char_map;
	t_map			**map;
	t_minimap		minimap;
	t_texture		texture;
}	t_map_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

#endif
