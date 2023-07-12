/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:17:16 by gael              #+#    #+#             */
/*   Updated: 2023/07/12 18:20:08 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_3d(t_game *game)
{
	int	i_midline;
	int	i_draw;
	int	x;
	int	y;
	int	x_check;
	int	y_check;
	int	i_main;

	fill_ceil_floor(game);
	i_main = 0;
	x_check = 0;
	y_check = 0;
	x = 0;
	i_draw = 0;
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	i_midline = game->fov->nbr_ray;
	while (i_midline > game->fov->nbr_ray / 2)
	{
		x = i_midline;
		game->line->x_dest = i_main;
		game->line->x_src = i_main;

		game->line->y_src = (game->win_height / 2) + (game->map->height * game->img_size);
		game->line->y_dest = (game->win_height / 2) + (game->map->height * game->img_size);
		game->line->y_dest += (game->fov->lines_vision[i_midline] / 2) * (-1);
	
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
		i_draw = 0;
		while (i_draw <= game->line->steps)
		{
			img_pix_put(game, round(game->line->corr_x), 
			round(game->line->corr_y), get_color(0, 255, 0));
			game->line->corr_x = game->line->corr_x + game->line->xite;
			game->line->corr_y = game->line->corr_y + game->line->yite;
			y_check = (int)(game->line->corr_y / game->img_size);
			x_check = (int)(game->line->corr_x / game->img_size);
			i_draw++;
		}
		printf(BACK_PURPLE"game->line->corr_y: %f"RST"\n", game->line->corr_y);
		printf(BACK_PURPLE"game->line->corr_x: %f"RST"\n", game->line->corr_x);
		printf("\n");
		i_midline--;
		i_main++;
	}
	x_check = 0;
	y_check = 0;
	x = 0;
	i_draw = 0;
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	i_midline = 0;
	while (i_midline < game->fov->nbr_ray / 2)
	{
		x = i_midline;
		game->line->x_dest = i_main;
		game->line->x_src = i_main;

		game->line->y_src = (game->win_height / 2) + (game->map->height * game->img_size);
		game->line->y_dest = (game->win_height / 2) + (game->map->height * game->img_size);
		game->line->y_dest += (game->fov->lines_vision[i_midline] / 2) * (-1);
	
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
		i_draw = 0;
		while (i_draw <= game->line->steps)
		{
			img_pix_put(game, round(game->line->corr_x), 
			round(game->line->corr_y), get_color(0, 255, 0));
			game->line->corr_x = game->line->corr_x + game->line->xite;
			game->line->corr_y = game->line->corr_y + game->line->yite;
			y_check = (int)(game->line->corr_y / game->img_size);
			x_check = (int)(game->line->corr_x / game->img_size);
			i_draw++;
		}
		printf(BACK_PURPLE"game->line->corr_y: %f"RST"\n", game->line->corr_y);
		printf(BACK_PURPLE"game->line->corr_x: %f"RST"\n", game->line->corr_x);
		printf("\n");
		i_midline++;
		i_main++;
	}
	return (SUCCESS);
	(void)game;
	(void)y;
	(void)x;
	(void)y_check;
	(void)x_check;
}

void	fill_ceil_floor(t_game *game)
{
	int	y;
	int	x;

	y = (game->map->height * game->img_size) + 4;
	x = 0;
	while (++y < (game->win_height / 2) + (game->map->height * game->img_size))
	{
		x = 0;
		while (x < game->win_width)
		{
			img_pix_put(game, x, y, get_color(255, 140, 20));
			x++;
		}
	}
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	while (++y < game->win_height + (game->map->height * game->img_size))
	{
		x = 0;
		while (x < game->win_width)
		{
			img_pix_put(game, x, y, get_color(20, 140, 255));
			x++;
		}
	}
}
