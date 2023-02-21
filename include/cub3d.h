/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:40 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/21 21:10:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "library.h"
# include "keymapping.h"
# include "errormsg.h"
# include "setting.h"
# include "struct.h"

//init
void	init(t_vars *vars, int argc, char **argv);
void	init_texture(t_vars *vars, int fd);
void	init_north(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_south(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_east(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_west(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_floor(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_ceiling(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_door(t_vars *vars, int *texture_bitflag, char *texture_value);
void	init_mob(t_vars *vars, int *texture_bitflag, char *texture_value);

//init_utils
int		count_strings(char **strings);
void	free_strings(char **strings);
int		get_rgb(char *texture_value);

//error_handler
void	error_handler(const char *errormsg);

#endif
