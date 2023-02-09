/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:15:16 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/09 16:18:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

# define SYSTEMCALL_ERROR		NULL
# define WRONG_ARGUMENTS_COUNT	"Wrong Arguments Count -"
# define INVALID_EXTENSION		"Invalid Expension - "
# define INVALID_ELEMENT_FORMAT	"Invalid Element Format - "
# define LACKING_ELEMENT		"Laking Element -"
# define INVALID_MAP_FORMAT		"Invalid Map Format - "
# define UNCLOSED_MAP			"Unclosed Map - "

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

typedef struct s_map_data
{
	t_coord			size;
	t_coord			player_position;
	t_direction		spawning_orientation;
	char			**char_map;
	t_map			**map;
}	t_map_data;

//parse_map
void	parse(t_element_data *element_data, t_map_data *map_data, char **argv);

//error_handler
void	error_handler(const char *error_type);

#endif
