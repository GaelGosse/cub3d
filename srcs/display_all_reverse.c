/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:33:07 by mael              #+#    #+#             */
/*   Updated: 2023/07/19 19:43:45 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_all_reverse_d(t_game *g, int k, int l)
{
	if ((g->fov->angle > 0 && g->fov->angle < 90) && k == 65363 && \
	g->fov->toggle == 'N' && g->map->pos_x + l >= g->map->width * g->img_size)
	{
		if (g->map->pos_x + l >= g->map->width * g->img_size)
			g->line->x_dest = g->map->width * g->img_size;
		else
			g->line->x_dest = g->map->width * g->img_size;
		printf(BACK_PURPLE"g->line->x_dest: %i"RST"\n", g->line->x_dest);
		printf(BACK_RED"rev D \t 0 - 90"RST"\n");
		// g->fov->toggle = 'E';
				// l = calcul_opposite_side(g, g->fov->angle);
		// g->line->x_dest_prev = g->line->x_dest;
		// g->line->y_dest_prev = g->line->y_dest;
		change_toggle_d(g);
		return (FAIL);
	}
	if ((g->fov->angle > 90 && g->fov->angle < 180) && k == 65363 && \
	g->fov->toggle == 'E' && g->map->pos_y + l >= g->map->height * g->img_size)
	{
		g->line->y_dest = g->map->pos_y + l;
		printf(BACK_RED"rev D \t 90 - 180"RST"\n");
		// g->fov->toggle = 'S';
		change_toggle_d(g);
		l = calcul_opposite_side(g, g->fov->angle);
		g->line->x_dest_prev = g->line->x_dest;
		g->line->y_dest_prev = g->line->y_dest;
		return (FAIL);
	}
	if ((g->fov->angle > 180 && g->fov->angle < 270) && k == 65363 && \
	g->fov->toggle == 'S' && g->map->pos_x - l < 0)
	{
		g->line->x_dest = 0;
		printf(BACK_RED"rev D \t 180 - 270"RST"\n");
		// g->fov->toggle = 'W';
		change_toggle_d(g);
		l = calcul_opposite_side(g, g->fov->angle);
		g->line->x_dest_prev = g->line->x_dest;
		g->line->y_dest_prev = g->line->y_dest;
		return (FAIL);
	}
	if ((g->fov->angle > 270 && g->fov->angle < 360) && k == 65363 && \
	g->fov->toggle == 'W' && g->map->pos_y - l < 0)
	{
		g->line->y_dest = 0;
		printf(BACK_RED"rev D \t 270 - 360"RST"\n");
		// g->fov->toggle = 'N';
		change_toggle_d(g);
		l = calcul_opposite_side(g, g->fov->angle);
		g->line->x_dest_prev = g->line->x_dest;
		g->line->y_dest_prev = g->line->y_dest;
		return (FAIL);
	}
	return (SUCCESS);
}

int	display_all_reverse_a(t_game *game, int key, int len_side)
{
	if ((game->fov->angle < 360 && game->fov->angle > 270) && key == 65361 && \
	game->fov->toggle == 'N' && game->map->pos_x - len_side < 0)
	{
		game->line->x_dest = 0;
		printf("rev A \t\t 360 - 270\n");
		// display_all(game, key);
		change_toggle_a(game);
		// game->fov->toggle = 'W';
		return (printf(BACK_RED"fail"RST"\n"), FAIL);
	}
	if ((game->fov->angle > 0 && game->fov->angle < 90) && key == 65361 && \
	game->fov->toggle == 'E' && game->map->pos_y -  len_side < 0)
	{
		game->line->y_dest = 0;
		printf("rev A \t\t 0 - 90\n");
		// display_all(game, key);
		change_toggle_a(game);
		// game->fov->toggle = 'N';
		return (printf(BACK_RED"fail"RST"\n"), FAIL);
	}
	if ((game->fov->angle > 90 && game->fov->angle < 180) && key == 65361 && \
	game->fov->toggle == 'S' && game->map->pos_x + len_side >= game->map->width * game->img_size)
	{
		game->line->x_dest = game->map->width * game->img_size;
		printf("rev A \t\t 90 - 180\n");
		// display_all(game, key);
		change_toggle_a(game);
		// game->fov->toggle = 'E';
		return (printf(BACK_RED"fail"RST"\n"), FAIL);
	}
	if ((game->fov->angle > 180 && game->fov->angle < 270) && key == 65361 && \
	game->fov->toggle == 'W' && game->map->pos_y + len_side >= game->map->height * game->img_size)
	{
		game->line->y_dest = game->map->height * game->img_size;
		printf("rev A \t\t 180 - 270\n");
		// display_all(game, key);
		change_toggle_a(game);
		// game->fov->toggle = 'S';
		return (printf(BACK_RED"fail"RST"\n"), FAIL);
	}
	return (SUCCESS);
}

