/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:18:06 by mael              #+#    #+#             */
/*   Updated: 2023/07/06 16:19:42 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

	// while (i < 15)
	// {
	// 	if (game->perso == 'N')
	// 	{
	// 		game->line->x_dest = game->line->x_dest + len_side;
	// 		game->line->y_dest = 0;
	// 	}
	// 	else if (game->perso == 'S')
	// 	{
	// 		game->line->x_dest = game->line->x_dest + len_side;
	// 		game->line->y_dest = game->map->height * game->img_size;
	// 	}
	// 	else if (game->perso == 'E')
	// 	{
	// 		game->line->x_dest = game->map->width * game->img_size;
	// 		game->line->y_dest = game->line->y_dest + len_side;
	// 	}
	// 	else if (game->perso == 'W')
	// 	{
	// 		game->line->x_dest = 0;
	// 		game->line->y_dest = game->line->y_dest + len_side;
	// 	}
	// 	game->fov->lines_vision[i] = draw_line_vision(game);
	// 	len_side = calcul_opposite_side(game, i, game->fov->angle);
	// 	i++;
	// }
	// i++;
	// //i = 0;
	// game->line->x_dest = game->map->pos_x;
	// game->line->y_dest = game->map->pos_y;
	// len_side = calcul_opposite_side(game, i, game->fov->angle);
	// while (i < 31)
	// {
	// 	if (game->perso == 'N')
	// 	{
	// 		game->line->x_dest = game->line->x_dest - len_side;
	// 		game->line->y_dest = 0;
	// 	}
	// 	else if (game->perso == 'S')
	// 	{
	// 		game->line->x_dest = game->line->x_dest - len_side;
	// 		game->line->y_dest = game->map->height * game->img_size;
	// 	}
	// 	else if (game->perso == 'E')
	// 	{
	// 		game->line->x_dest = game->map->width * game->img_size;
	// 		game->line->y_dest = game->line->y_dest - len_side;
	// 	}
	// 	else if (game->perso == 'W')
	// 	{
	// 		game->line->x_dest = 0;
	// 		game->line->y_dest = game->line->y_dest - len_side;
	// 	}
	// 	game->fov->lines_vision[i] = draw_line_vision(game);
	// 	len_side = calcul_opposite_side(game, i, game->fov->angle);
	// 	i++;
	// }