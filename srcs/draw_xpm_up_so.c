/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm_up_so.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:57:47 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 13:34:37 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_xpm_up_so(t_game *g, int i_midline)
{
	double	act_y;
	double	perc_x;
	double	perc_y;

	perc_x = (double)((int)roundf(g->fov->wall_witch[i_midline][0]) % \
	g->img_size) / (double)g->img_size;
	act_y = g->line_3d->corr_y - ((g->win_height / 2));
	perc_y = (g->line_3d->steps + act_y) / (g->line_3d->steps * 2);
	perc_x = (int)roundf(perc_x * g->xpm->so_width_height);
	perc_y = (int)roundf(perc_y * g->xpm->so_width_height);
	if (perc_y != 0 && perc_y < g->xpm->so_width_height)
		img_pix_put(g, roundf(g->line_3d->corr_x), \
		roundf(g->line_3d->corr_y), draw_xpm_up_so_color(g, perc_x, perc_y));
}

int	draw_xpm_up_so_color(t_game *game, int x, int y)
{
	int	i_find_c;
	int	color;

	color = 0;
	i_find_c = 0;
	while (i_find_c < game->xpm->so_tab_start)
	{
		if (y + game->xpm->so_tab_start < game->xpm->so_width_height \
		&& game->xpm->so_colors[i_find_c][0] == game->xpm->so_tab_file[y + \
		game->xpm->so_tab_start][x])
		{
			color = get_color(game->xpm->so_colors[i_find_c][1], \
			game->xpm->so_colors[i_find_c][2], \
			game->xpm->so_colors[i_find_c][3]);
		}
		i_find_c++;
	}
	return (color);
}
