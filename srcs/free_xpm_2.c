/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_xpm_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:08:28 by mael              #+#    #+#             */
/*   Updated: 2023/08/03 17:59:56 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab_colors_no(t_game *game, int i)
{
	while (++i < game->xpm->no_metadata[2])
	{
		free(game->xpm->no_colors[i]);
		game->xpm->no_colors[i] = NULL;
	}
	free(game->xpm->no_colors);
	game->xpm->no_colors = NULL;
}

void	free_tab_colors_so(t_game *game, int i)
{
	while (++i < game->xpm->so_metadata[2])
	{
		free(game->xpm->so_colors[i]);
		game->xpm->so_colors[i] = NULL;
	}
	free(game->xpm->so_colors);
	game->xpm->so_colors = NULL;
}

void	free_tab_colors_ea(t_game *game, int i)
{
	while (++i < game->xpm->ea_metadata[2])
	{
		free(game->xpm->ea_colors[i]);
		game->xpm->ea_colors[i] = NULL;
	}
	free(game->xpm->ea_colors);
	game->xpm->ea_colors = NULL;
}

void	free_tab_colors_we(t_game *game, int i)
{
	while (++i < game->xpm->we_metadata[2])
	{
		free(game->xpm->we_colors[i]);
		game->xpm->we_colors[i] = NULL;
	}
	free(game->xpm->we_colors);
	game->xpm->we_colors = NULL;
}
