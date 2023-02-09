/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:33:52 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/09 20:19:07 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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

typedef struct s_texture_path
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_texture_path;

typedef struct s_element_data
{
	t_texture_path	texture_path;
	int				floor_rgb;
	int				ceiling_rgb;
}	t_element_data;

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

typedef struct s_textures
{
	void	*north_wall;
	void	*south_wall;
	void	*east_wall;
	void	*west_wall;
	int		floor_rgb;
	int		ceiling_rgb;
}	t_textures;

typedef struct s_map_data
{
	t_coord			size;
	t_coord			player_position;
	t_direction		spawning_orientation;
	char			**char_map;
	t_map			**map;
	t_minimap		minimap;
	t_textures		textures;
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
