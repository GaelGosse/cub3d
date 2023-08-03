/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm_ud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:03:53 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 13:33:38 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	draw_xpm_down_blue(t_game *game, int i_midline)
{
	if (game->line_3d->corr_y < 0 || \
	game->line_3d->corr_y > game->win_height)
		return (FAIL);
	if (game->fov->toggle_vision[i_midline] == 'E')
	{
		draw_xpm_if_blue(game, i_midline);
		draw_xpm_down_ea(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'N')
	{
		draw_xpm_if_blue(game, i_midline);
		draw_xpm_down_no(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'S')
	{
		draw_xpm_if_blue(game, i_midline);
		draw_xpm_down_so(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'W')
	{
		draw_xpm_if_blue(game, i_midline);
		draw_xpm_down_we(game, i_midline);
	}
	return (adjust_line_3d(game), SUCCESS);
}

int	draw_xpm_down_red(t_game *game, int i_midline)
{
	if (game->line_3d->corr_y < 0 || \
	game->line_3d->corr_y > game->win_height)
		return (FAIL);
	if (game->fov->toggle_vision[i_midline] == 'E')
	{
		draw_xpm_if_red(game, i_midline);
		draw_xpm_down_ea(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'N')
	{
		draw_xpm_if_red(game, i_midline);
		draw_xpm_down_no(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'S')
	{
		draw_xpm_if_red(game, i_midline);
		draw_xpm_down_so(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'W')
	{
		draw_xpm_if_red(game, i_midline);
		draw_xpm_down_we(game, i_midline);
	}
	return (adjust_line_3d(game), SUCCESS);
}

int	draw_xpm_up_blue(t_game *game, int i_midline)
{
	if (game->line_3d->corr_y < 0 || \
	game->line_3d->corr_y > game->win_height)
		return (FAIL);
	if (game->fov->toggle_vision[i_midline] == 'E')
	{
		draw_xpm_if_blue(game, i_midline);
		draw_xpm_up_ea(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'N')
	{
		draw_xpm_if_blue(game, i_midline);
		draw_xpm_up_no(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'S')
	{
		draw_xpm_if_blue(game, i_midline);
		draw_xpm_up_so(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'W')
	{
		draw_xpm_if_blue(game, i_midline);
		draw_xpm_up_we(game, i_midline);
	}
	return (adjust_line_3d(game), SUCCESS);
}

int	draw_xpm_up_red(t_game *game, int i_midline)
{
	if (game->line_3d->corr_y < 0 || \
	game->line_3d->corr_y > game->win_height)
		return (FAIL);
	if (game->fov->toggle_vision[i_midline] == 'E')
	{
		draw_xpm_if_red(game, i_midline);
		draw_xpm_up_ea(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'N')
	{
		draw_xpm_if_red(game, i_midline);
		draw_xpm_up_no(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'S')
	{
		draw_xpm_if_red(game, i_midline);
		draw_xpm_up_so(game, i_midline);
	}
	else if (game->fov->toggle_vision[i_midline] == 'W')
	{
		draw_xpm_if_red(game, i_midline);
		draw_xpm_up_we(game, i_midline);
	}
	return (adjust_line_3d(game), SUCCESS);
}
