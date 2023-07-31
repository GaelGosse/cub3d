/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm_up_we.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:57:47 by gael              #+#    #+#             */
/*   Updated: 2023/07/31 17:46:06 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_xpm_up_we(t_game *game, int i_midline)
{
	double	act_y;
	double	perc_x;
	double	perc_y;

	perc_x = (double)((int)roundf(game->fov->wall_witch[i_midline][1]) % \
	game->img_size) / (double)game->img_size;
	act_y = game->line_3d->corr_y - ((game->win_height / 2) + \
	(game->map->height * game->img_size));
	perc_y = (game->line_3d->steps + act_y) / (game->line_3d->steps * 2);
	perc_x = (int)roundf(perc_x * 32);
	perc_y = (int)roundf(perc_y * 32);
	img_pix_put(game, roundf(game->line_3d->corr_x),
	roundf(game->line_3d->corr_y), draw_xpm_up_we_color(game, perc_x, perc_y));
}

int		draw_xpm_up_we_color(t_game *game, int x, int y)
{
	int	i_find_c;
	int	color;

	color = 0;
	i_find_c = 0;
	while (i_find_c < game->xpm->we_tab_start)
	{

		if (x >= 32 || x < 0)
			printf(BOLD_PURPLE"y + game->xpm->we_tab_start: %i    x %i"RESET"\n", y + game->xpm->we_tab_start, x);
		if (y + game->xpm->we_tab_start >= 32 || y < 0)
			printf(BOLD_CYAN"y + game->xpm->we_tab_start: %i    x %i"RESET"\n", y + game->xpm->we_tab_start, x);
		if (game->xpm->we_colors[i_find_c][0] \
		== game->xpm->we_tab_file[y + game->xpm->we_tab_start][x])
			color = get_color(game->xpm->we_colors[i_find_c][1],
								game->xpm->we_colors[i_find_c][2],
								game->xpm->we_colors[i_find_c][3]);
		i_find_c++;
	}
	return (color);
}
