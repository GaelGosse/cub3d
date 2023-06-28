/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:45:51 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/28 12:18:59 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_game *game)
{
	if (game->line->x_dest > 0 && game->line->x_dest < (game->map->width * game->img_size) && (game->line->y_dest == 0 || game->line->y_dest == (game->map->height * game->img_size)))
		game->line->x_dest = game->line->x_dest - 15;
	else if ((game->line->x_dest == 0 || game->line->x_dest == (game->map->width * game->img_size)) && game->line->y_dest > 0 && game->line->y_dest < (game->map->height * game->img_size))
		game->line->y_dest = game->line->y_dest + 15;
}

void	rotate_right(t_game *game)
{
	if (game->line->x_dest > 0 && game->line->x_dest < (game->map->width * game->img_size) && (game->line->y_dest == 0 || game->line->y_dest == (game->map->height * game->img_size)))
		game->line->x_dest = game->line->x_dest + 15;
	else if ((game->line->x_dest == 0 || game->line->x_dest == (game->map->width * game->img_size)) && game->line->y_dest > 0 && game->line->y_dest < (game->map->height * game->img_size))
		game->line->y_dest = game->line->y_dest - 15;
	printf("game->line->x_dest: %i\n", game->line->x_dest);
}