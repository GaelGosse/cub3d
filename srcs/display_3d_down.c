/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:15:57 by gael              #+#    #+#             */
/*   Updated: 2023/07/13 15:53:45 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	display_3d_down(t_game *game)
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
	while (i_midline > game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		while (i_ratio < 20)
		{
			game->line_3d->x_dest = i_main;
			game->line_3d->x_src = i_main;

			game->line_3d->y_src = (game->win_height / 2) + (game->map->height * game->img_size);
			game->line_3d->y_dest = (game->win_height / 2) + (game->map->height * game->img_size);
			// game->line_3d->y_dest += (game->fov->lines_vision[i_midline] * (-1));
			game->line_3d->y_dest += ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]);// - i_ratio;

			game->line_3d->dx = game->line_3d->x_dest - game->line_3d->x_src;
			game->line_3d->dy = game->line_3d->y_dest - game->line_3d->y_src;
			if (absolute_value(game->line_3d->dx) > absolute_value(game->line_3d->dy))
				game->line_3d->steps = absolute_value(game->line_3d->dx);
			else
				game->line_3d->steps = absolute_value(game->line_3d->dy);
			game->line_3d->xite = game->line_3d->dx / (float)game->line_3d->steps;
			game->line_3d->yite = game->line_3d->dy / (float)game->line_3d->steps;
			game->line_3d->corr_x = game->line_3d->x_src;
			game->line_3d->corr_y = game->line_3d->y_src;
			i_draw = 0;
			while (i_draw <= game->line_3d->steps)
			{
				if (game->line_3d->corr_y < game->map->height * game->img_size || game->line_3d->corr_y > game->win_height + game->map->height * game->img_size)
					break ;
				img_pix_put(game, round(game->line_3d->corr_x),
				round(game->line_3d->corr_y), get_color(0, 0, 255));
				game->line_3d->corr_x = game->line_3d->corr_x + game->line_3d->xite;
				game->line_3d->corr_y = game->line_3d->corr_y + game->line_3d->yite;
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
		while (i_ratio < 20)
		{
			game->line_3d->x_dest = i_main;
			game->line_3d->x_src = i_main;

			game->line_3d->y_src = (game->win_height / 2) + (game->map->height * game->img_size);
			game->line_3d->y_dest = (game->win_height / 2) + (game->map->height * game->img_size);
			// game->line_3d->y_dest += (game->fov->lines_vision[i_midline] * (-1) );
			game->line_3d->y_dest += ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]);// + i_ratio;


			game->line_3d->dx = game->line_3d->x_dest - game->line_3d->x_src;
			game->line_3d->dy = game->line_3d->y_dest - game->line_3d->y_src;
			if (absolute_value(game->line_3d->dx) > absolute_value(game->line_3d->dy))
				game->line_3d->steps = absolute_value(game->line_3d->dx);
			else
				game->line_3d->steps = absolute_value(game->line_3d->dy);
			game->line_3d->xite = game->line_3d->dx / (float)game->line_3d->steps;
			game->line_3d->yite = game->line_3d->dy / (float)game->line_3d->steps;
			game->line_3d->corr_x = game->line_3d->x_src;
			game->line_3d->corr_y = game->line_3d->y_src;
			i_draw = 0;
			while (i_draw <= game->line_3d->steps)
			{
				if (game->line_3d->corr_y < game->map->height * game->img_size || game->line_3d->corr_y > game->win_height + game->map->height * game->img_size)
					break ;
				img_pix_put(game, round(game->line_3d->corr_x),
				round(game->line_3d->corr_y), get_color(255, 0, 0));
				game->line_3d->corr_x = game->line_3d->corr_x + game->line_3d->xite;
				game->line_3d->corr_y = game->line_3d->corr_y + game->line_3d->yite;
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

