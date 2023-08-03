/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:58:33 by mael              #+#    #+#             */
/*   Updated: 2023/08/03 11:26:04 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_for_wall_a(t_game *game)
{
	if (game->map->map_org[(game->map->pos_y + ((-1) * \
	(game->line->check_x))) / game->img_size][(game->map->pos_x + \
	(game->line->check_y)) / game->img_size] != '1')
	{
		game->map->pos_x += game->line->new_y;
		game->map->pos_y += ((-1) * game->line->new_x);
		game->line->x_dest += game->line->new_y;
		game->line->y_dest += ((-1) * game->line->new_x);
	}
}

int	calcul_step_for_key_a(t_game *game)
{
	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);
	game->line->xite = game->line->dx / (double)game->line->steps;
	game->line->yite = game->line->dy / (double)game->line->steps;
	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	if (calcul_corr_for_step(game) == 1)
		return (FAIL);
	game->line->new_x = round(game->line->corr_x) - game->map->pos_x;
	game->line->new_y = round(game->line->corr_y) - game->map->pos_y;
	if (game->line->new_x > 0)
		game->line->check_x = game->line->new_x + 5;
	else
		game->line->check_x = game->line->new_x - 5;
	if (game->line->new_y > 0)
		game->line->check_y = game->line->new_y + 5;
	else
		game->line->check_y = game->line->new_y - 5;
	check_for_wall_a(game);
	return (SUCCESS);
}

int	calcul_step_for_key_d(t_game *game)
{
	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);
	game->line->xite = game->line->dx / (double)game->line->steps;
	game->line->yite = game->line->dy / (double)game->line->steps;
	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	if (calcul_corr_for_step(game) == 1)
		return (FAIL);
	game->line->new_x = round(game->line->corr_x) - game->map->pos_x;
	game->line->new_y = round(game->line->corr_y) - game->map->pos_y;
	if (game->line->new_x < 0)
		game->line->check_x = game->line->new_x - 5;
	else
		game->line->check_x = game->line->new_x + 5;
	if (game->line->new_y < 0)
		game->line->check_y = game->line->new_y - 5;
	else
		game->line->check_y = game->line->new_y + 5;
	check_for_wall_d(game);
	return (SUCCESS);
}

void	check_for_wall_d(t_game *game)
{
	if (game->map->map_org[(game->map->pos_y + (game->line->check_x)) / \
	game->img_size][(game->map->pos_x + ((-1) * \
	(game->line->check_y))) / game->img_size] != '1')
	{
		game->map->pos_x += ((-1) * game->line->new_y);
		game->map->pos_y += game->line->new_x;
		game->line->x_dest += ((-1) * game->line->new_y);
		game->line->y_dest += game->line->new_x;
	}
}
