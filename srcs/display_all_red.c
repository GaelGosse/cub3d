/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all_red.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:35:59 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 15:48:07 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	display_all_red(t_game *game, int i_rotate, int len_vision)
{
	while (i_rotate < game->fov->nbr_ray / 2)
	{
		game->display_all_angle_2 = 0;
		display_all_red_first(game, i_rotate, len_vision);
		display_all_red_second(game, i_rotate, len_vision);
		display_all_red_third(game, i_rotate, len_vision);
		game->fov->lines_vision[i_rotate] = draw_line_vision(game);
		game->fov->lines_vision[i_rotate] = \
		abs_flt(cos(deg_to_radian(game->fov->deg * i_rotate))) * \
		game->fov->lines_vision[i_rotate];
		if (game->fov->lines_vision[i_rotate] == 0)
			game->fov->lines_vision[i_rotate] = 1;
		game->fov->wall_witch[i_rotate][0] = game->line->corr_x;
		game->fov->wall_witch[i_rotate][1] = game->line->corr_y;
		game->fov->wall[i_rotate][0] = game->line->corr_x / game->img_size;
		game->fov->wall[i_rotate][1] = game->line->corr_y / game->img_size;
		set_toggle(game, i_rotate);
		i_rotate++;
	}
}

void	display_all_red_first(t_game *game, int i_rotate, int len_vision)
{
	if (game->fov->angle >= 0 && game->fov->angle < 60)
	{
		game->display_all_angle_2 = game->display_all_angle + \
		(game->fov->deg * i_rotate);
		len_vision = tan(deg_to_radian(abs_dble(game->display_all_angle_2))) \
		* game->map->pos_y;
		if (game->display_all_angle_2 > 0)
			game->line->x_dest = game->map->pos_x + len_vision;
		game->line->y_dest = 0;
	}
	if (game->fov->angle >= 330 && game->fov->angle < 360)
	{
		game->display_all_angle_2 = 360 - game->display_all_angle - \
		(game->fov->deg * i_rotate);
		len_vision = tan(deg_to_radian(abs_dble(game->display_all_angle_2))) \
		* game->map->pos_y;
		if (game->display_all_angle_2 > 0)
			game->line->x_dest = game->map->pos_x - len_vision;
		else
			game->line->x_dest = game->map->pos_x + len_vision;
		game->line->y_dest = 0;
	}
}

void	display_all_red_second(t_game *game, int i_rotate, int len_vision)
{
	if (game->fov->angle < 330 && game->fov->angle >= 270)
	{
		game->display_all_angle_2 = 270 - game->display_all_angle - \
		(game->fov->deg * i_rotate);
		len_vision = tan(deg_to_radian(abs_dble(game->display_all_angle_2))) \
		* game->map->pos_x;
		if (game->display_all_angle_2 > 0)
			game->line->y_dest = game->map->pos_y + len_vision;
		else
			game->line->y_dest = game->map->pos_y - len_vision;
		game->line->x_dest = 0;
	}
	if (game->fov->angle >= 60 && game->fov->angle < 150)
	{
		game->display_all_angle_2 = 90 - game->display_all_angle - \
		(game->fov->deg * i_rotate);
		len_vision = tan(deg_to_radian(abs_dble(game->display_all_angle_2))) \
		* (game->map->width * game->img_size - game->map->pos_x);
		if ((game->display_all_angle_2) > 0)
			game->line->y_dest = game->map->pos_y - len_vision;
		else
			game->line->y_dest = game->map->pos_y + len_vision;
		game->line->x_dest = game->map->width * game->img_size;
	}
}

void	display_all_red_third(t_game *game, int i_rotate, int len_vision)
{
	if (game->fov->angle >= 150 && game->fov->angle < 240)
	{
		game->display_all_angle_2 = 180 - game->display_all_angle - \
		(game->fov->deg * i_rotate);
		len_vision = tan(deg_to_radian(abs_dble(game->display_all_angle_2))) * \
		(game->map->height * game->img_size - game->map->pos_y);
		if (game->display_all_angle_2 > 0)
			game->line->x_dest = game->map->pos_x + len_vision;
		else
			game->line->x_dest = game->map->pos_x - len_vision;
		game->line->y_dest = game->map->height * game->img_size;
	}
	if (game->fov->angle >= 240 && game->fov->angle < 270)
	{
		game->display_all_angle_2 = 270 - game->display_all_angle - \
		(game->fov->deg * i_rotate);
		len_vision = tan(deg_to_radian(abs_dble(game->display_all_angle_2))) * \
		game->map->pos_x;
		if (game->display_all_angle_2 > 0)
			game->line->y_dest = game->map->pos_y + len_vision;
		else
			game->line->y_dest = game->map->pos_y - len_vision;
		game->line->x_dest = 0;
	}
}
