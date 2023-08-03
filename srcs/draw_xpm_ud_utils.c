/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm_ud_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:52:20 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 14:44:01 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_xpm_if_blue(t_game *game, int i)
{
	if (i < game->fov->nbr_ray && i > game->fov->nbr_ray / 2 \
		&& game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
		&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i]
		&& game->fov->toggle_vision[i - 1] == game->fov->toggle_vision[i + 1])
		game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
	if (i == game->fov->nbr_ray)
		game->fov->toggle_vision[i] = game->fov->toggle_vision[i - 1];
}

void	draw_xpm_if_red(t_game *game, int i)
{
	if (i > 0 && i < game->fov->nbr_ray / 2 \
		&& game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
		&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i]
		&& game->fov->toggle_vision[i - 1] == game->fov->toggle_vision[i + 1])
		game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
}

void	adjust_line_3d(t_game *game)
{
	game->line_3d->corr_x = game->line_3d->corr_x + game->line_3d->xite;
	game->line_3d->corr_y = game->line_3d->corr_y + game->line_3d->yite;
}
