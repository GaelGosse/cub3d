/* ************************************************************************** */
/*                                                                        +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:27:15 by mael              #+#    #+#             */
/*   Updated: 2023/07/04 11:59:26 by mael             ###   ######           */
/*                                                        :::      ::::::::   */
/*   toggle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+##.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	change_toggle_d(t_game *game)
{
	if (game->line->x_dest_prev < game->map->width * game->img_size && \
	game->line->x_dest >= game->map->width * game->img_size && 
	game->fov->toggle == 'N')
	{
		game->fov->toggle = 'E';
		game->line->x_dest = game->map->width * game->img_size;
	}
	if (game->line->y_dest_prev < game->map->height * game->img_size && \
	game->line->y_dest >= game->map->height * game->img_size && 
	game->fov->toggle == 'E')
	{
		game->fov->toggle = 'S';
		game->line->y_dest = game->map->height * game->img_size;
	}
	if (game->line->x_dest_prev > 0 && \
	game->line->x_dest <= 0 && 
	game->fov->toggle == 'S')
	{
		game->fov->toggle = 'W';
		game->line->x_dest = 0;
	}
	if (game->line->y_dest_prev > 0 && \
	game->line->y_dest <= 0 && 
	game->fov->toggle == 'W')
	{
		game->fov->toggle = 'N';
		game->line->y_dest = 0;
	}
}

void	change_toggle_a(t_game *game)
{
	if (game->line->y_dest_prev > 0 && \
	game->line->y_dest <= 0 && 
	game->fov->toggle == 'E')
	{
		game->fov->toggle = 'N';
		game->line->y_dest = 0;
	}
	if (game->line->x_dest_prev < game->map->width * game->img_size && \
	game->line->x_dest >= game->map->width * game->img_size && 
	game->fov->toggle == 'S')
	{
		game->fov->toggle = 'E';
		game->line->x_dest = game->map->width * game->img_size;
	}
	if (game->line->y_dest_prev < game->map->height * game->img_size && \
	game->line->y_dest >= game->map->height * game->img_size && 
	game->fov->toggle == 'W')
	{
		game->fov->toggle = 'S';
		game->line->y_dest = game->map->height * game->img_size;
	}
	if (game->line->x_dest_prev > 0 && \
	game->line->x_dest <= 0 && 
	game->fov->toggle == 'N')
	{
		game->fov->toggle = 'W';
		game->line->x_dest = 0;
	}
}

	// if (game->line->x_dest >= game->map->width * game->img_size) // E
	// 	game->line->x_dest = game->map->width * game->img_size;
	// if (game->line->y_dest >= game->map->height * game->img_size) // S
	// 	game->line->y_dest = game->map->height * game->img_size;