/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all_blue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:37:27 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 15:46:57 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	display_all_blue(t_game *g, int i_rotate, int len_vision)
{
	i_rotate = 1;
	if (g->display_all_angle > 180)
		g->display_all_angle = abs_dble(g->display_all_angle - 360);
	while (i_rotate <= g->fov->nbr_ray / 2)
	{
		display_all_blue_first(g, i_rotate, len_vision);
		display_all_blue_second(g, i_rotate, len_vision);
		g->fov->lines_vision[i_rotate + g->fov->nbr_ray / 2] = \
		draw_line_vision(g);
		g->fov->lines_vision[i_rotate + g->fov->nbr_ray / 2] = \
		abs_flt(cos(deg_to_radian(g->fov->deg * i_rotate))) * \
		g->fov->lines_vision[i_rotate + g->fov->nbr_ray / 2];
		if (g->fov->lines_vision[i_rotate + g->fov->nbr_ray / 2] == 0)
			g->fov->lines_vision[i_rotate + g->fov->nbr_ray / 2] = 1;
		g->fov->wall_witch[i_rotate + g->fov->nbr_ray / 2][0] = g->line->corr_x;
		g->fov->wall[i_rotate + g->fov->nbr_ray / 2][0] = \
		g->line->corr_x / g->img_size;
		g->fov->wall_witch[i_rotate + g->fov->nbr_ray / 2][1] = \
		g->line->corr_y;
		g->fov->wall[i_rotate + g->fov->nbr_ray / 2][1] = \
		g->line->corr_y / g->img_size;
		set_toggle(g, i_rotate + g->fov->nbr_ray / 2);
		i_rotate++;
	}
}

void	display_all_blue_first(t_game *game, int i_rotate, int len_vision)
{
	if (game->fov->angle >= 0 && game->fov->angle < 90)
	{
		len_vision = tan(deg_to_radian(abs_dble(game->display_all_angle - \
		(game->fov->deg * i_rotate)))) * game->map->pos_y;
		if (game->display_all_angle - (game->fov->deg * i_rotate) > 0)
			game->line->x_dest = game->map->pos_x + len_vision;
		else
			game->line->x_dest = game->map->pos_x - len_vision;
		game->line->y_dest = 0;
	}
	if (game->fov->angle >= 90 && game->fov->angle < 180)
	{
		len_vision = tan(deg_to_radian(abs_dble(game->display_all_angle - \
		(game->fov->deg * i_rotate) - 90))) * \
		(game->map->width * game->img_size - game->map->pos_x);
		if ((game->display_all_angle - (game->fov->deg * i_rotate)) > 90)
			game->line->y_dest = game->map->pos_y + len_vision;
		else
			game->line->y_dest = game->map->pos_y - len_vision;
		game->line->x_dest = game->map->width * game->img_size;
	}
}

void	display_all_blue_second(t_game *game, int i_rotate, int len_vision)
{
	if (game->fov->angle >= 180 && game->fov->angle < 270)
	{
		len_vision = tan(deg_to_radian(abs_dble(180 - game->display_all_angle \
		- (game->fov->deg * i_rotate)))) * \
		(game->map->height * game->img_size - game->map->pos_y);
		if (180 - game->display_all_angle - (game->fov->deg * i_rotate) > 0)
			game->line->x_dest = game->map->pos_x - len_vision;
		else
			game->line->x_dest = game->map->pos_x + len_vision;
		game->line->y_dest = game->map->height * game->img_size;
	}
	if (game->fov->angle >= 270 && game->fov->angle < 360)
	{
		len_vision = tan(deg_to_radian(abs_dble(90 - game->display_all_angle \
		- (game->fov->deg * i_rotate)))) * (game->map->pos_x);
		if (90 - game->display_all_angle - (game->fov->deg * i_rotate) > 0)
			game->line->y_dest = game->map->pos_y - len_vision;
		else
			game->line->y_dest = game->map->pos_y + len_vision;
		game->line->x_dest = 0;
	}
}
