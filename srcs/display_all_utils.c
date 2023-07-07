/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:54:00 by gael              #+#    #+#             */
/*   Updated: 2023/07/07 12:01:19 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_display_all(t_game *game, int key, int *len_side)
{
	if (init_img(game) == FAIL)
		return (FAIL);
	if (create_image_and_get_adrr(game) == FAIL)
		return (FAIL);
	color_image(game);
	draw_player(game);
	game->line->x_src = game->map->pos_x;
	game->line->y_src = game->map->pos_y;
	if (key == 'd')
		change_toggle_d(game);
	else if (key == 'a')
		change_toggle_a(game);
	*len_side = calcul_opposite_side(game, game->fov->angle);
	game->line->x_dest_prev = game->line->x_dest;
	game->line->y_dest_prev = game->line->y_dest;
	if (display_all_reverse_d(game, key, *len_side) == FAIL)
		return (FAIL);
	if (display_all_reverse_a(game, key, *len_side) == FAIL)
		return (FAIL);
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
