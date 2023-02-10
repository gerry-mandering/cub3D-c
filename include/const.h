/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:33:25 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/10 17:52:45 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define WHITE_SPACE			" \t\n\v\f\r"
# define W_SIZE					1920
# define H_SIZE					1080
# define TILE_SIZE				24

# define SYSTEMCALL_ERROR		NULL
# define WRONG_ARGUMENTS_COUNT	"Wrong Arguments Count -"
# define INVALID_EXTENSION		"Invalid Expension - "
# define INVALID_TEXTURE_FORMAT	"Invalid Texture Format - "
# define INVALID_RGB_FORMAT		"Invalid RGB Format - "
# define DUPLICATED_TEXTURE		"Duplicated Texture - "
# define LACKING_TEXTURE_INFO	"Laking Texture Info -"
# define HAVE_NO_MAP_INPUT		"Have No Map Input -"
# define INVALID_MAP_FORMAT		"Invalid Map Format - "
# define UNCLOSED_MAP			"Unclosed Map - "

# define NORTH_WALL				"images/north_wall.xpm"
# define SOUTH_WALL				"images/south_wall.xpm"
# define EAST_WALL				"images/east_wall.xpm"
# define WEST_WALL				"images/west_wall.xpm"
# define MINIMAP_BG				"images/minimap_background.xpm"
# define MINIMAP_WALL			"images/minimap_wall.xpm"
# define MINIMAP_PLAYER			"images/minimap_player.xpm"

# define WALL_COLOR 0xffffff
# define PLAYER_COLOR 0xff0000
# define EMPTY_SPACE_COLOR 0

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_Q					12
# define KEY_E					14
# define KEY_R					15
# define KEY_I					34
# define KEY_O					31
# define KEY_P					35
# define KEY_J					38
# define KEY_K					40
# define KEY_L					37
# define KEY_ESC				53
# define KEY_PLUS				24
# define KEY_MINUS				27
# define KEY_ARROW_UP			126
# define KEY_ARROW_DOWN			125
# define KEY_ARROW_LEFT			123
# define KEY_ARROW_RIGHT		124

#endif
