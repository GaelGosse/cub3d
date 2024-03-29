/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:05:22 by mael              #+#    #+#             */
/*   Updated: 2023/08/03 16:48:57 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	free_ceil_floor(t_game *game)
{
	if (game->map->ceil)
	{
		free(game->map->ceil);
		game->map->ceil = NULL;
	}
	if (game->map->floor)
	{
		free(game->map->floor);
		game->map->floor = NULL;
	}
	return (SUCCESS);
}

void	free_fov(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->fov->nbr_ray)
	{
		free(game->fov->wall[i]);
		game->fov->wall[i] = NULL;
		free(game->fov->wall_witch[i]);
		game->fov->wall_witch[i] = NULL;
		i++;
	}
	if (game->fov->wall)
		free(game->fov->wall);
	if (game->fov->wall_witch)
		free(game->fov->wall_witch);
	free(game->fov->lines_vision);
	free(game->fov->toggle_vision);
	free(game->fov);
	free(game->line_3d);
	game->line_3d = NULL;
	free(game->line);
	game->line = NULL;
}

int	free_all(t_game *game)
{
	if (game->map)
		free_ceil_floor(game);
	if (game->xpm)
		free_xpm(game);
	if (game->fov)
		free_fov(game);
	free(game->img);
	free_parsing(game, NULL);
	return (SUCCESS);
}
