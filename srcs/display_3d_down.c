/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:15:57 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 13:27:41 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	display_3d_down(t_game *game)
{
	int	i_midline;
	int	i_ratio;
	int	i_main;

	i_main = 0;
	i_ratio = 0;
	i_midline = game->fov->nbr_ray;
	while (i_midline > game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		while (i_ratio < 2)
		{
			draw_line_3d_down(game, i_main, i_midline);
			i_draw_blue(game, i_midline);
			i_ratio++;
			i_main++;
		}
		i_midline--;
	}
	display_3d_down_red(game, i_main);
}

void	display_3d_down_red(t_game *game, int i_main)
{
	int i_ratio;
	int i_midline;
	
	i_ratio = 0;
	i_midline = 0;
	while (i_midline < game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		while (i_ratio < 2)
		{
			draw_line_3d_down(game, i_main, i_midline);
			i_draw_red(game, i_midline);
			i_ratio++;
			i_main++;
		}
		i_midline++;
	}
}
void	display_3d(t_game *game)
{
	display_3d_down(game);
	display_3d_up(game);
}

