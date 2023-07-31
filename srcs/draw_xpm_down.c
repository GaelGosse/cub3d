/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:03:53 by gael              #+#    #+#             */
/*   Updated: 2023/07/31 12:55:22 by gael             ###   ########.fr       */
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
		draw_xpm_ea(game, i_midline);
	else if (game->fov->toggle_vision[i_midline] == 'N')
		draw_xpm_no(game, i_midline);
	else if (game->fov->toggle_vision[i_midline] == 'S')
		draw_xpm_so(game, i_midline);
	else if (game->fov->toggle_vision[i_midline] == 'W')
		draw_xpm_we(game, i_midline);
	game->line_3d->corr_x = game->line_3d->corr_x + game->line_3d->xite;
	game->line_3d->corr_y = game->line_3d->corr_y + game->line_3d->yite;
	return (SUCCESS);
}

int	draw_xpm_down_red(t_game *game, int i_midline)
{
	if (game->line_3d->corr_y < game->map->height * game->img_size || \
	game->line_3d->corr_y > game->win_height + \
	game->map->height * game->img_size)
		return (FAIL);
	if (game->fov->toggle_vision[i_midline] == 'E')
		draw_xpm_ea(game, i_midline);
	else if (game->fov->toggle_vision[i_midline] == 'N')
		draw_xpm_no(game, i_midline);
	else if (game->fov->toggle_vision[i_midline] == 'S')
		draw_xpm_so(game, i_midline);
	else if (game->fov->toggle_vision[i_midline] == 'W')
		draw_xpm_we(game, i_midline);
	game->line_3d->corr_x = game->line_3d->corr_x + game->line_3d->xite;
	game->line_3d->corr_y = game->line_3d->corr_y + game->line_3d->yite;
	return (SUCCESS);
}
