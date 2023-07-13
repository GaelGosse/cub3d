/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:35:52 by mael              #+#    #+#             */
/*   Updated: 2023/07/13 12:45:32 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	calcul_corr_for_step(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->line->steps)
	{
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		if (game->map->map_org[(int)(round(game->line->corr_y) / game->img_size)][(int)(round(game->line->corr_x) / game->img_size)] == '1')
			return (1);
		if (i == 10)
			break ;
		i++;
	}
	return (0);
}

void	move_w(t_game *game)
{
	game->line->dx = game->line->x_dest - game->line->x_src;
	game->line->dy = game->line->y_dest - game->line->y_src;
	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);
	game->line->xite = game->line->dx / (float)game->line->steps;
	game->line->yite = game->line->dy / (float)game->line->steps;
	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	if (calcul_corr_for_step(game) == 1)
		return ;
	game->map->pos_x = round(game->line->corr_x);
	game->map->pos_y = round(game->line->corr_y);
}

void	init_direction_for_s(t_game *game)
{
	int	dest_y;
	int	dest_x;

	dest_y = 0;
	dest_x = 0;
	if (game->fov->toggle == 'E')
	{
		dest_x = (2 * game->map->pos_x - game->line->x_dest);
		dest_y = (2 * game->map->pos_y - game->line->y_dest);
		game->line->dx = dest_x - game->line->x_src;
		game->line->dy = dest_y - game->line->y_src;
	}
	if (game->fov->toggle == 'W')
	{
		dest_x = (2 * game->map->pos_x - game->line->x_dest);
		dest_y = (2 * game->map->pos_y - game->line->y_dest);
		game->line->dx = dest_x - game->line->x_src;
		game->line->dy = dest_y - game->line->y_src;
	}
}

void	init_direction_for_s_2(t_game *game)
{
	int	dest_y;
	int	dest_x;

	dest_y = 0;
	dest_x = 0;
	if (game->fov->toggle == 'S')
	{
		dest_x = (2 * game->map->pos_x - game->line->x_dest);
		dest_y = (2 * game->map->pos_y - game->line->y_dest);
		game->line->dx = dest_x - game->line->x_src;
		game->line->dy = dest_y - game->line->y_src;
	}
	if (game->fov->toggle == 'N')
	{
		dest_x = (2 * game->map->pos_x - game->line->x_dest);
		dest_y = (2 * game->map->pos_y - game->line->y_dest);
		game->line->dx = dest_x - game->line->x_src;
		game->line->dy = dest_y - game->line->y_src;
	}
}

void	move_s(t_game *game)
{
	init_direction_for_s(game);
	init_direction_for_s_2(game);
	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);
	game->line->xite = game->line->dx / (float)game->line->steps;
	game->line->yite = game->line->dy / (float)game->line->steps;
	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	if (calcul_corr_for_step(game) == 1)
		return ;
	game->map->pos_x = round(game->line->corr_x);
	game->map->pos_y = round(game->line->corr_y);
}
