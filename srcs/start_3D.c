/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:52:12 by mael              #+#    #+#             */
/*   Updated: 2023/07/07 15:21:58 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	reset_img(t_game *game)
{
	mlx_destroy_image(game->mlibx, game->img->mlx_img);
	free(game->img);
}

int	first_time(t_game *game)
{
	init_line(game);
	set_pos_character(game);
	if (init_img(game) == FAIL)
		return (FAIL);
	if (create_image_and_get_adrr(game) == FAIL)
		return (FAIL);
	color_image(game);
	draw_player(game);
	game->line->x_src = game->map->pos_x;
	game->line->y_src = game->map->pos_y;
	init_fov(game);
	init_position(game);
	// draw_line_vision(game);
	// mlx_put_image_to_window(game->mlibx, game->window, game->img->mlx_img,
	// 	0, 0);
	return (SUCCESS);
}


int	start_3D(t_game *game)
{
	game->img_size = 48;
	game->mlibx = mlx_init();
	if (!game->mlibx)
		return (printf("mlx pointer issue\n"), FAIL);
	// game->map->width++;
	game->window = mlx_new_window(game->mlibx, (game->map->width) * game->img_size,
		game->map->height * game->img_size, "cub3D");
	if (!game->window)
		return (printf("Window failed\n"), FAIL);
	if (first_time(game) == FAIL)
		return (FAIL);
	if (display_all(game, '\0') == FAIL)
		return (FAIL);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &ft_destroy_and_free2, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &ft_event_listen, game);
	mlx_loop(game->mlibx);
	return (SUCCESS);
}

void	fill_wall(t_game *game, int i, int j)
{
	int x;
	int y;

	y = i * game->img_size;
	while (y < (i + 1) * game->img_size)
	{
		x = j * game->img_size;
		while (x < (j + 1) * game->img_size)
		{
			img_pix_put(game, x, y, get_color(255, 0, 230));
			x++;
		}
		y++;
	}
}

void	fill_void(t_game *game, int i, int j)
{
	int x;
	int y;

	y = i * game->img_size;
	while (y < (i + 1) * game->img_size)
	{
		x = j * game->img_size;
		while (x < (j + 1) * game->img_size)
		{
			img_pix_put(game, x, y, get_color(5, 15, 120));
			x++;
		}
		y++;
	}
}

void	do_quad(t_game *game, int i, int j)
{
	int y;
	int x;

	y = i * game->img_size;
	while (y < (i + 1) * game->img_size)
	{
		if (y % game->img_size ==  0)
		{
			x = j * game->img_size;
			while (++x < (j + 1) * game->img_size)
				img_pix_put(game, x, y, get_color(255, 255, 255));
		}
		else
		{
			x = j * game->img_size;
			while (x < (j + 1) * game->img_size)
			{
				if (x % game->img_size == 0)
					img_pix_put(game, x, y, get_color(255, 255, 255));
				x++;
			}
		}
		y++;
	}
}

void	color_image(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map->map_org[i])
	{
		j = 0;
		while (game->map->map_org[i][j])
		{
			if (game->map->map_org[i][j] == '1')
			{
				fill_wall(game, i, j);
				do_quad(game, i, j);
			}
			else
			{
				fill_void(game, i, j);
				do_quad(game, i, j);
			}
			j++;
		}
		i++;
	}
}
