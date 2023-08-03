/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm_down_ea.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:57:47 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 13:31:54 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_xpm_down_ea(t_game *game, int i_midline)
{
	double	act_y;
	double	perc_x;
	double	perc_y;

	perc_x = (double)((int)roundf(game->fov->wall_witch[i_midline][1]) % \
		game->img_size) / (double)game->img_size;
	act_y = game->line_3d->corr_y - ((game->win_height / 2));
	perc_y = (game->line_3d->steps + act_y) / (game->line_3d->steps * 2);
	perc_x = (int)roundf(perc_x * game->xpm->ea_width_height);
	perc_y = (int)roundf(perc_y * game->xpm->ea_width_height);
	img_pix_put(game, roundf(game->line_3d->corr_x), \
	roundf(game->line_3d->corr_y), draw_xpm_ea_color(game, perc_x, perc_y));
}

int	draw_xpm_ea_color(t_game *game, int x, int y)
{
	int	i_find_c;
	int	color;

	color = 0;
	i_find_c = 0;
	while (i_find_c < game->xpm->ea_tab_start)
	{
		if (y <= game->xpm->ea_width_height && \
		game->xpm->ea_colors[i_find_c][0] \
		== game->xpm->ea_tab_file[y + game->xpm->ea_tab_start][x])
			color = get_color(game->xpm->ea_colors[i_find_c][1], \
				game->xpm->ea_colors[i_find_c][2], \
				game->xpm->ea_colors[i_find_c][3]);
		i_find_c++;
	}
	return (color);
}
