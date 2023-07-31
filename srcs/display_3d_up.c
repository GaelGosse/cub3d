/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:17:16 by gael              #+#    #+#             */
/*   Updated: 2023/07/31 13:33:57 by gael             ###   ########.fr       */
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

int	display_3d_up(t_game *game)
{
	int	i_midline;
	int	i_draw;
	int	i_ratio;
	int	y;
	int	i_main;

	i_main = 0;
	i_draw = 0;
	i_ratio = 0;
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	i_midline = game->fov->nbr_ray;
	if (init_3d_line(game) == FAIL)
		return (FAIL);
	fill_ceil_floor(game);
	while (i_midline > game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		while (i_ratio < 2)
		{
			game->line_3d->x_dest = i_main;
			game->line_3d->x_src = i_main;

			game->line_3d->y_src = (game->win_height / 2) + (game->map->height * game->img_size);
			game->line_3d->y_dest = (game->win_height / 2) + (game->map->height * game->img_size);
			// game->line_3d->y_dest += (game->fov->lines_vision[i_midline] * (-1));
			if (game->fov->lines_vision[i_midline] == 0)
				game->fov->lines_vision[i_midline] = 1;
			game->line_3d->y_dest += ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]) * (-1);
			// printf(CYAN"((proj_plane * img_size) / lines_vision[%i]) * (-1): %i"RESET"\n", i_midline, ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]) * (-1));

			game->line_3d->dx = game->line_3d->x_dest - game->line_3d->x_src;
			game->line_3d->dy = game->line_3d->y_dest - game->line_3d->y_src;
			if (absolute_value(game->line_3d->dx) > absolute_value(game->line_3d->dy))
				game->line_3d->steps = absolute_value(game->line_3d->dx);
			else
				game->line_3d->steps = absolute_value(game->line_3d->dy);
			game->line_3d->xite = game->line_3d->dx / (double)game->line_3d->steps;
			game->line_3d->yite = game->line_3d->dy / (double)game->line_3d->steps;
			game->line_3d->corr_x = game->line_3d->x_src;
			game->line_3d->corr_y = game->line_3d->y_src;
			i_draw = 0;
			while (i_draw <= game->line_3d->steps)
			{
				if (draw_xpm_up_blue(game, i_midline) == FAIL)
					break ;
				i_draw++;
			}

			i_ratio++;
			i_main++;
		}
		// printf(PURPLE"game->fov->lines_vision[%i]: %i"RESET"\n", i_midline, game->fov->lines_vision[i_midline]);
		// printf(BACK_PURPLE"game->line_3d->corr_y: %f"RST"\n", game->line_3d->corr_y);
		// printf(BACK_PURPLE"game->line_3d->corr_x: %f"RST"\n", game->line_3d->corr_x);
		// printf("\n");
		i_midline--;
	}
	i_draw = 0;
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	i_midline = 0;
	while (i_midline < game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		while (i_ratio < 2)
		{
			game->line_3d->x_dest = i_main;
			game->line_3d->x_src = i_main;

			game->line_3d->y_src = (game->win_height / 2) + (game->map->height * game->img_size);
			game->line_3d->y_dest = (game->win_height / 2) + (game->map->height * game->img_size);
			// game->line_3d->y_dest += (game->fov->lines_vision[i_midline] * (-1) );
			if (game->fov->lines_vision[i_midline] == 0)
				game->fov->lines_vision[i_midline] = 1;
			game->line_3d->y_dest += ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]) * (-1);
			// printf(RED"((proj_plane * img_size) / %i [%i]) * (-1): %f"RESET"\n", game->fov->lines_vision[i_midline], i_midline, (((double)game->fov->proj_plane * (double)game->img_size) / (double)game->fov->lines_vision[i_midline]) );


			game->line_3d->dx = game->line_3d->x_dest - game->line_3d->x_src;
			game->line_3d->dy = game->line_3d->y_dest - game->line_3d->y_src;
			if (absolute_value(game->line_3d->dx) > absolute_value(game->line_3d->dy))
				game->line_3d->steps = absolute_value(game->line_3d->dx);
			else
				game->line_3d->steps = absolute_value(game->line_3d->dy);
			game->line_3d->xite = game->line_3d->dx / (double)game->line_3d->steps;
			game->line_3d->yite = game->line_3d->dy / (double)game->line_3d->steps;
			game->line_3d->corr_x = game->line_3d->x_src;
			game->line_3d->corr_y = game->line_3d->y_src;
			i_draw = 0;
			while (i_draw <= game->line_3d->steps)
			{
				if (draw_xpm_up_red(game, i_midline) == FAIL)
					break ;
				i_draw++;
			}

			i_ratio++;
			i_main++;
		}
		// printf(RED"game->fov->lines_vision[%i]: %i"RESET"\n", i_midline, game->fov->lines_vision[i_midline]);
		// printf(BACK_RED"game->line_3d->corr_y: %f"RST"\n", game->line_3d->corr_y);
		// printf(BACK_RED"game->line_3d->corr_x: %f"RST"\n", game->line->corr_x);
		// printf("\n");
		i_midline++;
	}
	return (SUCCESS);
	(void)game;
	(void)y;
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
			img_pix_put(game, x, y, get_color(10, 177, 255));
			x++;
		}
	}
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	while (++y < game->win_height + (game->map->height * game->img_size))
	{
		x = 0;
		while (x < game->win_width)
		{
			img_pix_put(game, x, y, get_color(35, 150, 90));
			x++;
		}
	}
}
