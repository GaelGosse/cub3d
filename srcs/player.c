/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:35:04 by mael              #+#    #+#             */
/*   Updated: 2023/08/03 13:23:08 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_pos_character(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map_org[y])
	{
		x = 0;
		while (game->map->map_org[y][x])
		{
			if (game->map->map_org[y][x] == 'W' || \
			game->map->map_org[y][x] == 'E' || game->map->map_org[y][x] == 'N' \
			|| game->map->map_org[y][x] == 'S')
			{
				game->map->pos_x = (x * game->img_size) + (game->img_size / 2);
				game->map->pos_y = (y * game->img_size) + (game->img_size / 2);
			}
			x++;
		}
		y++;
	}
}

int	ft_event_listen(int key, t_game *game)
{
	if (key == 65307)
		destroy_and_free(game, NULL);
	if (key == XK_w)
		key_is_w(game, (int) 'w');
	else if (key == XK_s)
		key_is_s(game, (int) 's');
	else if (key == 65361)
		key_rotate_left(game, key);
	else if (key == 65363)
		key_rotate_right(game, key);
	else if (key == XK_a)
	{
		if (key_is_a(game, (int) 'a') == FAIL)
			return (FAIL);
	}
	else if (key == XK_d)
	{
		if (key_is_d(game, (int) 'd') == FAIL)
			return (FAIL);
	}
	return (0);
}
