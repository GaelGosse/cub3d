/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm_so.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:57:47 by gael              #+#    #+#             */
/*   Updated: 2023/07/31 01:02:32 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_xpm_so(t_game *game, int i_midline)
{
	double	act_x;
	double	act_y;
	double	perc_x;
	double	perc_y;

	(void)act_x;

	perc_x = (double)((int)roundf(game->fov->wall_witch[i_midline][0]) % game->xpm->so_width_height) / (double)game->xpm->so_width_height;

	act_y = game->line_3d->corr_y - ((game->win_height / 2) + (game->map->height * game->img_size));
	perc_y = (game->line_3d->steps + act_y) / (game->line_3d->steps * 2);

	// printf(PURPLE"game->line_3d->steps: %i"RESET"\n", game->line_3d->steps);
	// printf(BOLD_PURPLE"act_y: %i"RESET"\n", (int)act_y);
	// printf(PURPLE"game->fov->wall_witch[i_midline][0]: %f"RESET"\n", game->fov->wall_witch[i_midline][0]);
	perc_x = (int)roundf(perc_x * 32);
	// printf(PURPLE"perc_x: %i"RESET"\n", (int)roundf(perc_x * 32));
	perc_y = (int)roundf(perc_y * 32);
	// printf(PURPLE"perc_y: %i"RESET"\n", (int)roundf(perc_y * 32));
	// printf(PURPLE"game->xpm->so_width_height * perc_y: %i"RESET"\n", (int)roundf((double)game->xpm->so_width_height * (double)perc_y));
	// printf("\n");

	draw_xpm_so_color(game, perc_x, perc_y);
	// perc_x = game->line_3d->corr_x;
	// perc_y = game->line_3d->corr_y;
	img_pix_put(game, roundf(game->line_3d->corr_x),
	roundf(game->line_3d->corr_y), get_color(0, 0, 255));
	(void)i_midline;
	(void)perc_x;
	(void)perc_y;
}

void	draw_xpm_so_color(t_game *game, int x, int y)
{
	// printf("%i, %i\t ", x, y - 1);
	// printf(BACK_YELLOW"%i"RESET, game->xpm->so_tab_file[x][y - 1]);
	// printf("\t");
	// printf(PURPLE"game->xpm->so_colors[0][0]: %c"RESET"\n", game->xpm->so_colors[0][0]);
	// printf(PURPLE"game->xpm->so_colors[0][1]: %c"RESET"\n", game->xpm->so_colors[1][0]);
	// printf(PURPLE"game->xpm->so_colors[0][2]: %c"RESET"\n", game->xpm->so_colors[2][0]);
	// printf(PURPLE"game->xpm->so_colors[0][3]: %c"RESET"\n", game->xpm->so_colors[3][0]);
	// printf(PURPLE"game->xpm->so_colors[0][4]: %c"RESET"\n", game->xpm->so_colors[4][0]);
	// printf(PURPLE"game->xpm->so_colors[0][5]: %c"RESET"\n", game->xpm->so_colors[5][0]);



// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------



	// a faire :
	// loop over colors and compare actual char
	// \-> get color with this rgb
	//  return this color



// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------




	printf("\n");
	// printf(BACK_YELLOW"%c"RESET, game->xpm->so_tab_file[x][y - 1]);
	(void)game;
	(void)x;
	(void)y;
}
