/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:22:19 by mael              #+#    #+#             */
/*   Updated: 2023/06/30 11:49:48 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	updt_first_line(t_game *game)
{
	int	i;

	i = game->map->pos_y;
	while (i > 0)
	{
		if (game->map->map_org[i / game->img_size][game->map->pos_x / game->img_size] == '1')
			break ;
		i--;
	}
	game->fov->len_first_line = game->map->pos_y - i;
	printf("game->fov->len_first_line: %i\n", game->fov->len_first_line);
}