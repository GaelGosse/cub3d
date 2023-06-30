/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:35:04 by mael              #+#    #+#             */
/*   Updated: 2023/06/30 15:45:05 by mael             ###   ########.fr       */
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
				game->map->pos_x = (x * game->img_size) + (game->img_size / 2);
				game->map->pos_y = (y * game->img_size) + (game->img_size / 2);
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
	int	i_check;
	int	j_check;

	i_check = 0;
	j_check = 0;
	// if (key == 65307)
	// 	ft_destroy_and_free(game, NULL);
	printf("start angle: %i\n", game->fov->angle);
	if (key == XK_w)
	{
		//clear_img(game);
		i_check = (game->map->pos_y - 10) / game->img_size;
		if (i_check < 0 || i_check >= game->map->height)// * game->img_size)
			return (printf("i_check %i\n", i_check), FAIL);
		if (game->map->map_org[i_check][game->map->pos_x / game->img_size] != '1')
		{
			game->map->pos_y = game->map->pos_y - 5;
			reset_img(game);
			display_all(game, 'w');
		}
	}
	else if (key == XK_s)
	{
		i_check = (game->map->pos_y + 10) / game->img_size;
		if (i_check < 0 || i_check >= game->map->height)// * game->img_size)
			return (printf("i_check %i\n", i_check), FAIL);
		if (game->map->map_org[i_check][game->map->pos_x / game->img_size] != '1')
		{
			game->map->pos_y = game->map->pos_y + 5;
			reset_img(game);
			display_all(game, 's');
		}
	}
	else if (key == XK_a)
	{
		j_check = (game->map->pos_x - 10) / game->img_size;
		if (j_check < 0 || j_check >= game->map->width)// * game->img_size)
			return (printf("j_check %i\n", j_check), FAIL);
		if (game->map->map_org[game->map->pos_y  / game->img_size][j_check] != '1')
		{
			// game->map->pos_x = game->map->pos_x - 5;
			game->fov->angle -= 5;
			if (game->fov->angle < 0)
				game->fov->angle = game->fov->angle + 360;
			// if (game->fov->angle < 0)
			// 	game->fov->angle *= -1;
			printf("end angle: %i\n", game->fov->angle);
			reset_img(game);
			display_all(game, 'a');
		}
	}
	else if (key == XK_d)
	{
		j_check = (game->map->pos_x + 10) / game->img_size;
		if (j_check < 0 || j_check >= game->map->width)// * game->img_size)
			return (printf("j_check %i\n", j_check), FAIL);
		if (game->map->map_org[game->map->pos_y / game->img_size][j_check] != '1')
		{
			// game->map->pos_x = game->map->pos_x + 5;
			game->fov->angle += 5;
			if (game->fov->angle >= 360)
				game->fov->angle = game->fov->angle % 360;
			printf("end angle: %i\n", game->fov->angle);
			reset_img(game);
			display_all(game, 'd');
		}
	}
	return (0);
}

