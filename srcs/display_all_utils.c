/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:54:00 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 13:22:52 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_display_all(t_game *game, int key, int *len_side)
{
	if (!game->img)
	{
		if (init_img(game) == FAIL)
			return (printf(BACK_RED"init img"RST"\n"), FAIL);
		if (create_image_and_get_adrr(game) == FAIL)
			return (printf(BACK_RED"crt img"RST"\n"), FAIL);
	}
	game->line->x_src = game->map->pos_x;
	game->line->y_src = game->map->pos_y;
	(void)len_side;
	(void)key;
	return (SUCCESS);
}

void	move_straight(t_game *game)
{
	if (game->fov->angle == 0)
	{
		game->line->x_dest = game->map->pos_x;
		game->line->y_dest = 0;
	}
	if (game->fov->angle == 90)
	{
		game->line->x_dest = game->map->width * game->img_size;
		game->line->y_dest = game->map->pos_y;
	}
	if (game->fov->angle == 180)
	{
		game->line->x_dest = game->map->pos_x;
		game->line->y_dest = game->map->width * game->img_size;
	}
	if (game->fov->angle == 270)
	{
		game->line->x_dest = 0;
		game->line->y_dest = game->map->pos_y;
	}
}

void	rotate_new(t_game *game)
{
	double	angle_2;
	int		len_vision;

	angle_2 = 0;
	len_vision = 0;
	angle_1(game, angle_2, len_vision);
	angle_3(game, angle_2, len_vision);
	angle_4(game, angle_2, len_vision);
}
