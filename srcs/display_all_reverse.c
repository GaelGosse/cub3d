/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:33:07 by mael              #+#    #+#             */
/*   Updated: 2023/07/05 16:32:57 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_all_reverse_d(t_game *game, int key, int len_side)
{
	if ((game->fov->angle > 0 && game->fov->angle < 90) && key == 'd' && \
	game->fov->toggle == 'N' && game->map->pos_x + len_side >= game->map->width * game->img_size)
	{
		printf(BACK_GREEN"N recur "RST"\n");
		
		game->line->x_dest = game->map->pos_x + len_side;
		return (display_all(game, key), FAIL);
	}
	if ((game->fov->angle > 90 && game->fov->angle < 180) && key == 'd' && \
	game->fov->toggle == 'E' && game->map->pos_y + len_side >= game->map->height * game->img_size)
	{
		printf(BACK_GREEN"E recur "RST"\n");
		game->line->y_dest = game->map->pos_y + len_side;
		return (display_all(game, key), FAIL);
	}
	if ((game->fov->angle > 180 && game->fov->angle < 270) && key == 'd' && \
	game->fov->toggle == 'S' && game->map->pos_x - len_side < 0)
	{
		printf(BACK_GREEN"S recur "RST"\n");
		game->line->x_dest = 0;
		return (display_all(game, key), FAIL);
	}
	if ((game->fov->angle > 270 && game->fov->angle < 360) && key == 'd' && \
	game->fov->toggle == 'W' && game->map->pos_y - len_side < 0)
	{
		printf(BACK_GREEN"W recur "RST"\n");
		game->line->y_dest = 0;
		return (display_all(game, key), FAIL);
	}
	return (SUCCESS);
}

int	display_all_reverse_a(t_game *game, int key, int len_side)
{
	if ((game->fov->angle < 360 && game->fov->angle > 270) &&key == 'a' && \
	game->fov->toggle == 'N' && game->map->pos_x - len_side < 0)
	{
		printf(BACK_RED"N recur "RST"\n");
		game->line->x_dest = 0;
		display_all(game, key);
		return (FAIL);
	}
	if ((game->fov->angle > 0 && game->fov->angle < 90) && key == 'a' && \
	game->fov->toggle == 'E' && game->map->pos_y -  len_side < 0)
	{
		printf(BACK_RED"E recur "RST"\n");
		game->line->y_dest = 0;
		display_all(game, key);
		return (FAIL);
	}
	if ((game->fov->angle > 90 && game->fov->angle < 180) && key == 'a' && \
	game->fov->toggle == 'S' && game->map->pos_x + len_side >= game->map->width * game->img_size)
	{
		printf(BACK_RED"S recur "RST"\n");
		game->line->x_dest = game->map->width * game->img_size;
		display_all(game, key);
		return (FAIL);
	}
	if ((game->fov->angle > 180 && game->fov->angle < 270) && key == 'a' && \
	game->fov->toggle == 'W' && game->map->pos_y + len_side >= game->map->height * game->img_size)
	{
		printf(BACK_RED"W recur "RST"\n");
		game->line->y_dest = game->map->height * game->img_size;
		display_all(game, key);
		return (FAIL);
	}
	return (SUCCESS);
}

