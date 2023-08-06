/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d_down_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:24:12 by mael              #+#    #+#             */
/*   Updated: 2023/08/03 13:27:46 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line_3d_down(t_game *game, int i_main, int i_midline)
{
	game->line_3d->x_dest = i_main;
	game->line_3d->x_src = i_main;
	game->line_3d->y_src = (game->win_height / 2);
	game->line_3d->y_dest = (game->win_height / 2);
	if (game->fov->lines_vision[i_midline] == 0)
		game->fov->lines_vision[i_midline] = 1;
	game->line_3d->y_dest += ((game->fov->proj_plane * game->img_size) / \
		game->fov->lines_vision[i_midline]);
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
}

void	i_draw_blue(t_game *game, int i_midline)
{
	int	i_draw;

	i_draw = 0;
	while (i_draw <= game->line_3d->steps)
	{
		if (draw_xpm_down_blue(game, i_midline) == FAIL)
			break ;
		i_draw++;
	}
}

void	i_draw_red(t_game *game, int i_midline)
{
	int	i_draw;

	i_draw = 0;
	while (i_draw <= game->line_3d->steps)
	{
		if (draw_xpm_down_red(game, i_midline) == FAIL)
			break ;
		i_draw++;
	}
}
