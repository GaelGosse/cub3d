/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:17:16 by gael              #+#    #+#             */
/*   Updated: 2023/07/12 16:12:42 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_3d(t_game *game)
{
	int	i_midline;

	i_midline = -1;
	while (++i_midline <= game->fov->nbr_ray)
	{
		if (i_midline < 30)
			printf(BACK_RED"game->fov->lines_vision[%i]: %i"RST"\n", i_midline, game->fov->lines_vision[i_midline]);
		else
			printf(BACK_BLUE"game->fov->lines_vision[%i]: %i"RST"\n", i_midline, game->fov->lines_vision[i_midline]);
	}
	return (SUCCESS);
	(void)game;
}
