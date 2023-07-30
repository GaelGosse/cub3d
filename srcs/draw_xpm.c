/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:03:53 by gael              #+#    #+#             */
/*   Updated: 2023/07/31 00:01:45 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	draw_xpm_down_blue(t_game *game, int i_midline)
{
	if (game->line_3d->corr_y < game->map->height * game->img_size || \
	game->line_3d->corr_y > game->win_height + \
	game->map->height * game->img_size)
		return (FAIL);
	if (game->fov->toggle_vision[i_midline] == 'E')
		img_pix_put(game, roundf(game->line_3d->corr_x),
		roundf(game->line_3d->corr_y), get_color(255, 0, 0));
	else if (game->fov->toggle_vision[i_midline] == 'N')
		img_pix_put(game, roundf(game->line_3d->corr_x),
		roundf(game->line_3d->corr_y), get_color(255, 255, 0));
	else if (game->fov->toggle_vision[i_midline] == 'S')
		draw_xpm_so(game, i_midline);
	else if (game->fov->toggle_vision[i_midline] == 'W')
		img_pix_put(game, roundf(game->line_3d->corr_x),
		roundf(game->line_3d->corr_y), get_color(0, 255, 0));
	game->line_3d->corr_x = game->line_3d->corr_x + game->line_3d->xite;
	game->line_3d->corr_y = game->line_3d->corr_y + game->line_3d->yite;
	return (SUCCESS);
}
