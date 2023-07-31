/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:05:22 by mael              #+#    #+#             */
/*   Updated: 2023/07/31 16:45:55 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	free_ceil_floor(t_game *game)
{
	// int i;

	// i = 0;
	// while (i < 3)
	// {
	// 	printf("game->map->ceil[i]: %i\n", game->map->ceil[i]);
	// 	i++;
	// }
	free(game->map->ceil);
	free(game->map->floor);
	return (SUCCESS);
}

void	free_fov(t_game *game)
{
	int i;

	i = 0;
	while (i < game->fov->nbr_ray)
	{
		free(game->fov->wall[i]);
		free(game->fov->wall_witch[i]);
		i++;
	}
	if (game->fov->wall)
		free(game->fov->wall);
	if (game->fov->wall_witch)
		free(game->fov->wall_witch);
	free(game->fov->lines_vision);
	free(game->fov->toggle_vision);
	free(game->fov);
	(void)i;
}

int	free_all(t_game *game)
{
	//printf(BOLD_BLUE"Je rentre dans free all avec echap"RST"\n");
	free_ceil_floor(game);
	free_xpm(game);
	// free_fov(game);
	// free(game->img);
	free_parsing(game, NULL);
	return (SUCCESS);
}