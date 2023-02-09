/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:08 by jinholee          #+#    #+#             */
/*   Updated: 2023/02/09 14:45:16 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	usage(void)
{
	printf("usage: cub3d [map_file]");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (usage());
	printf("%s\n", argv[1]);
	return (0);
}
