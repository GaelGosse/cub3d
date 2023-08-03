/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:47:15 by mael              #+#    #+#             */
/*   Updated: 2023/08/03 11:25:14 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_is_w(t_game *g, int key)
{
	if (g->map->map_org[g->map->pos_y / g->img_size][(g->map->pos_x + 15) / \
	g->img_size] != '1' && g->fov->angle == 90)
		g->map->pos_x += 10;
	else if (g->map->map_org[(g->map->pos_y - 15) / \
	g->img_size][(g->map->pos_x) / g->img_size] != '1' && g->fov->angle == 0)
		g->map->pos_y -= 10;
	else if (g->map->map_org[g->map->pos_y / g->img_size][(g->map->pos_x - 15) \
	/ g->img_size] != '1' && g->fov->angle == 270)
		g->map->pos_x -= 10;
	else if (g->map->map_org[(g->map->pos_y + 15) \
	/ g->img_size][(g->map->pos_x) / \
	g->img_size] != '1' && g->fov->angle == 180)
		g->map->pos_y += 10;
	else
		move_w(g);
	reset_img(g);
	display_all(g, key);
}

void	key_is_s(t_game *game, int key)
{
	if (game->map->map_org[game->map->pos_y / \
	game->img_size][(game->map->pos_x - 15) / \
	game->img_size] != '1' && game->fov->angle == 90)
		game->map->pos_x -= 10;
	else if (game->map->map_org[(game->map->pos_y + 15) / \
	game->img_size][(game->map->pos_x) / \
	game->img_size] != '1' && game->fov->angle == 0)
		game->map->pos_y += 10;
	else if (game->map->map_org[game->map->pos_y / \
	game->img_size][(game->map->pos_x + 15) / \
	game->img_size] != '1' && game->fov->angle == 270)
		game->map->pos_x += 10;
	else if (game->map->map_org[(game->map->pos_y - 15) / \
	game->img_size][(game->map->pos_x) / \
	game->img_size] != '1' && game->fov->angle == 180)
		game->map->pos_y -= 10;
	else
		move_s(game);
	reset_img(game);
	display_all(game, key);
}

int	key_is_a(t_game *game, int key)
{
	if (game->map->map_org[(game->map->pos_y - 15) / \
	game->img_size][(game->map->pos_x) / \
	game->img_size] != '1' && game->fov->angle == 90)
		game->map->pos_y -= 10;
	else if (game->map->map_org[(game->map->pos_y) / \
	game->img_size][(game->map->pos_x - 15) / \
	game->img_size] != '1' && game->fov->angle == 0)
		game->map->pos_x -= 10;
	else if (game->map->map_org[(game->map->pos_y + 15) / \
	game->img_size][(game->map->pos_x) / \
	game->img_size] != '1' && game->fov->angle == 270)
		game->map->pos_y += 10;
	else if (game->map->map_org[(game->map->pos_y) / \
	game->img_size][(game->map->pos_x + 15) \
	/ game->img_size] != '1' && game->fov->angle == 180)
		game->map->pos_x += 10;
	else
	{
		if (calcul_step_for_key_a(game) == FAIL)
			return (FAIL);
	}
	reset_img(game);
	display_all(game, key);
	return (SUCCESS);
}

int	key_is_d(t_game *game, int key)
{
	if (game->map->map_org[(game->map->pos_y + 15) / \
	game->img_size][(game->map->pos_x) / game->img_size] != '1' \
	&& game->fov->angle == 90)
		game->map->pos_y += 10;
	else if (game->map->map_org[(game->map->pos_y) / \
	game->img_size][(game->map->pos_x + 15) / game->img_size] != '1' && \
	game->fov->angle == 0)
		game->map->pos_x += 10;
	else if (game->map->map_org[(game->map->pos_y - 15) / \
	game->img_size][(game->map->pos_x) / game->img_size] != '1' && \
	game->fov->angle == 270)
		game->map->pos_y -= 10;
	else if (game->map->map_org[(game->map->pos_y) / \
	game->img_size][(game->map->pos_x - 15) / game->img_size] != '1' && \
	game->fov->angle == 180)
		game->map->pos_x -= 10;
	else
	{
		if (calcul_step_for_key_d(game) == FAIL)
			return (FAIL);
	}
	reset_img(game);
	display_all(game, key);
	return (SUCCESS);
}
