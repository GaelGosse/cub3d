/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:00:02 by mael              #+#    #+#             */
/*   Updated: 2023/08/03 11:25:44 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_rotate_left(t_game *game, int key)
{
	game->fov->angle -= 5;
	if (game->fov->angle < 0)
		game->fov->angle = game->fov->angle + 360;
	reset_img(game);
	display_all(game, key);
}

void	key_rotate_right(t_game *game, int key)
{
	game->fov->angle += 5;
	if (game->fov->angle >= 360)
		game->fov->angle = game->fov->angle % 360;
	reset_img(game);
	display_all(game, key);
}
