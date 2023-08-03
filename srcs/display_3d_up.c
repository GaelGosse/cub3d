/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:17:16 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 12:17:06 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_3d_line(t_game *game)
{
	game->line_3d = malloc(sizeof(t_line_3d));
	if (!game->line_3d)
		return (printf("malloc line 3d failed\n"), FAIL);
	game->line_3d->dx = 0;
	game->line_3d->dy = 0;
	game->line_3d->steps = 0;
	game->line_3d->xite = 0;
	game->line_3d->yite = 0;
	game->line_3d->corr_x = 0;
	game->line_3d->corr_y = 0;
	game->line_3d->x_src = 0;
	game->line_3d->y_src = 0;
	game->line_3d->x_dest = 0;
	game->line_3d->y_dest = 0;
	game->line_3d->x_dest_prev = 0;
	game->line_3d->y_dest_prev = 0;
	return (SUCCESS);
}

void	display_3d_up(t_game *game)
{
	int	i_midline;
	int	i_ratio;
	int	i_main;

	i_main = 0;
	i_ratio = 0;
	i_midline = game->fov->nbr_ray;
	while (i_midline > game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		while (i_ratio < 2)
		{
			draw_line_3d_up(game, i_main, i_midline);
			i_draw_up_blue(game, i_midline);
			i_ratio++;
			i_main++;
		}
		i_midline--;
	}
	display_3d_up_red(game, i_main);
}

void	display_3d_up_red(t_game *game, int i_main)
{
	int i_midline;
	int	i_ratio;

	i_ratio = 0;
	i_midline = 0;
	while (i_midline < game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		while (i_ratio < 2)
		{
			draw_line_3d_up(game, i_main, i_midline);
			i_draw_up_red(game, i_midline);
			i_ratio++;
			i_main++;
		}
		i_midline++;
	}
}

void	fill_ceil_floor(t_game *game)
{
	int	y;
	int	x;

	y = (game->map->height * game->img_size) + 4;
	x = 0;
	while (++y < (game->win_height / 2) + (game->map->height * game->img_size))
	{
		x = 0;
		while (x < game->win_width)
		{
			img_pix_put(game, x, y, get_color(
				game->map->ceil[0],
				game->map->ceil[1],
				game->map->ceil[2]));
			x++;
		}
	}
	fill_ceil_floor_2(game);
}

void	fill_ceil_floor_2(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	while (++y < game->win_height + (game->map->height * game->img_size))
	{
		x = 0;
		while (x < game->win_width)
		{
			img_pix_put(game, x, y, get_color(
				game->map->floor[0],
				game->map->floor[1],
				game->map->floor[2]));
			x++;
		}
	}
}