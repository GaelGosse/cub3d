/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:44:36 by mael              #+#    #+#             */
/*   Updated: 2023/08/03 12:43:12 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	angle_1(t_game *game, double angle_2, int len_vision)
{
	if (game->fov->angle >= 0 && game->fov->angle < 60)
	{
		angle_2 = (game->fov->angle);
		len_vision = tan(deg_to_radian(abs_dble(angle_2))) * game->map->pos_y;
		if (angle_2 > 0)
			game->line->x_dest = game->map->pos_x + len_vision;
		game->line->y_dest = 0;
	}
	if (game->fov->angle >= 330 && game->fov->angle < 360)
	{
		angle_2 = 360 - (game->fov->angle);
		len_vision = tan(deg_to_radian(abs_dble(angle_2))) * game->map->pos_y;
		if (angle_2 > 0)
			game->line->x_dest = game->map->pos_x - len_vision;
		else
			game->line->x_dest = game->map->pos_x + len_vision;
		game->line->y_dest = 0;
	}
}

void	angle_3(t_game *game, double angle_2, int len_vision)
{
	if (game->fov->angle < 330 && game->fov->angle >= 270)
	{
		angle_2 = 270 - (game->fov->angle);
		len_vision = tan(deg_to_radian(abs_dble(angle_2))) * game->map->pos_x;
		if (angle_2 > 0)
			game->line->y_dest = game->map->pos_y + len_vision;
		else
			game->line->y_dest = game->map->pos_y - len_vision;
		game->line->x_dest = 0;
	}
	if (game->fov->angle >= 60 && game->fov->angle < 150)
	{
		angle_2 = 90 - (game->fov->angle);
		len_vision = tan(deg_to_radian(abs_dble(angle_2))) * \
		(game->map->width * game->img_size - game->map->pos_x);
		if ((angle_2) > 0)
			game->line->y_dest = game->map->pos_y - len_vision;
		else
			game->line->y_dest = game->map->pos_y + len_vision;
		game->line->x_dest = game->map->width * game->img_size;
	}
}

void	angle_4(t_game *game, double angle_2, int len_vision)
{
	if (game->fov->angle >= 150 && game->fov->angle < 240)
	{
		angle_2 = 180 - (game->fov->angle);
		len_vision = tan(deg_to_radian(abs_dble(angle_2))) * \
		(game->map->height * game->img_size - game->map->pos_y);
		if (angle_2 > 0)
			game->line->x_dest = game->map->pos_x + len_vision;
		else
			game->line->x_dest = game->map->pos_x - len_vision;
		game->line->y_dest = game->map->height * game->img_size;
	}
	if (game->fov->angle >= 240 && game->fov->angle < 270)
	{
		angle_2 = 270 - (game->fov->angle);
		len_vision = tan(deg_to_radian(abs_dble(angle_2))) * game->map->pos_x;
		if (angle_2 > 0)
			game->line->y_dest = game->map->pos_y + len_vision;
		else
			game->line->y_dest = game->map->pos_y - len_vision;
		game->line->x_dest = 0;
	}
}
