/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:35:04 by mael              #+#    #+#             */
/*   Updated: 2023/07/09 00:34:54 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_pos_character(t_game *game)
{
	int y;
	int	x;

	y = 0;
	while (game->map->map_org[y])
	{
		x = 0;
		while (game->map->map_org[y][x])
		{
			if (game->map->map_org[y][x] == 'W' || game->map->map_org[y][x] == 'E'
				|| game->map->map_org[y][x] == 'N' || game->map->map_org[y][x] == 'S')
			{
				game->map->pos_x = (x * game->img_size) + (game->img_size);
				game->map->pos_y = (y * game->img_size) + (game->img_size);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int y;
	int x;

	y = game->map->pos_y - 5;
	x = game->map->pos_x - 5;
	while (y < game->map->pos_y + 5)
	{
		x = game->map->pos_x - 5;
		while (x < game->map->pos_x + 5)
		{
			img_pix_put(game, x, y, get_color(0, 255, 0));
			x++;
		}
		y++;
	}
}
int	ft_event_listen(int key, t_game *game)
{
	printf("\033c\n");
	if (key == 65307)
		ft_destroy_and_free(game, NULL);
	if (key == XK_w)
	{
		if (game->map->map_org[game->map->pos_y / game->img_size][(game->map->pos_x + 15) / game->img_size] != '1' && game->fov->angle == 90)
			game->map->pos_x += 10;
		else if (game->map->map_org[(game->map->pos_y - 15) / game->img_size][(game->map->pos_x) / game->img_size] != '1' && game->fov->angle == 0)
			game->map->pos_y -= 10;
		else if (game->map->map_org[game->map->pos_y / game->img_size][(game->map->pos_x - 15) / game->img_size] != '1' &&  game->fov->angle == 270)
			game->map->pos_x -= 10;
		else if (game->map->map_org[(game->map->pos_y + 15) / game->img_size][(game->map->pos_x) / game->img_size] != '1' && game->fov->angle == 180)
			game->map->pos_y += 10;
		else
			move_w(game);
		reset_img(game);
		display_all(game, 'w');
	}
	else if (key == XK_s)
	{
		if (game->map->map_org[game->map->pos_y / game->img_size][(game->map->pos_x - 15) / game->img_size] != '1' && game->fov->angle == 90)
			game->map->pos_x -= 10;
		else if (game->map->map_org[(game->map->pos_y + 15) / game->img_size][(game->map->pos_x) / game->img_size] != '1' && game->fov->angle == 0)
			game->map->pos_y += 10;
		else if (game->map->map_org[game->map->pos_y / game->img_size][(game->map->pos_x + 15) / game->img_size] != '1' &&  game->fov->angle == 270)
			game->map->pos_x += 10;
		else if (game->map->map_org[(game->map->pos_y - 15) / game->img_size][(game->map->pos_x) / game->img_size] != '1' && game->fov->angle == 180)
			game->map->pos_y -= 10;
		else
			move_s(game);
		reset_img(game);
		display_all(game, 's');
	}
	else if (key == XK_a)
	{
		game->fov->angle -= 5;
		if (game->fov->angle < 0)
			game->fov->angle = game->fov->angle + 360;
		reset_img(game);
		display_all(game, 'a');
	}
	else if (key == XK_d)
	{
		game->fov->angle += 5;
		if (game->fov->angle >= 360)
			game->fov->angle = game->fov->angle % 360;
		reset_img(game);
		display_all(game, 'd');
	}
	return (0);
}

