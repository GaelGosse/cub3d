/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_xpm_no.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:57:52 by gael              #+#    #+#             */
/*   Updated: 2023/07/31 16:45:31 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_xpm(t_game *game)
{
	if (game->xpm)
	{
		free_xpm_no(game);
		free_xpm_we(game);
		free_xpm_ea(game);
		free_xpm_so(game);
		free(game->xpm);
		game->xpm = NULL;
	}
}

void	free_xpm_no(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->xpm->no_tab_start)
	{
		free(game->xpm->no_colors[i]);
		game->xpm->no_colors[i] = NULL;
		i++;
	}
	free(game->xpm->no_colors);
	game->xpm->no_colors = NULL;
	free_tab_str(game->xpm->no_tab_file);
	game->xpm->no_tab_file = NULL;
	free(game->xpm->no_file_content);
	game->xpm->no_file_content = NULL;
}

void	free_xpm_we(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->xpm->we_tab_start)
	{
		free(game->xpm->we_colors[i]);
		game->xpm->we_colors[i] = NULL;
		i++;
	}
	free(game->xpm->we_colors);
	game->xpm->we_colors = NULL;
	free_tab_str(game->xpm->we_tab_file);
	game->xpm->we_tab_file = NULL;
	free(game->xpm->we_file_content);
	game->xpm->we_file_content = NULL;
}

void	free_xpm_ea(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->xpm->ea_tab_start)
	{
		free(game->xpm->ea_colors[i]);
		game->xpm->ea_colors[i] = NULL;
		i++;
	}
	free(game->xpm->ea_colors);
	game->xpm->ea_colors = NULL;
	free_tab_str(game->xpm->ea_tab_file);
	game->xpm->ea_tab_file = NULL;
	free(game->xpm->ea_file_content);
	game->xpm->ea_file_content = NULL;
}

void	free_xpm_so(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->xpm->so_tab_start)
	{
		free(game->xpm->so_colors[i]);
		game->xpm->so_colors[i] = NULL;
		i++;
	}
	free(game->xpm->so_colors);
	game->xpm->so_colors = NULL;
	free_tab_str(game->xpm->so_tab_file);
	game->xpm->so_tab_file = NULL;
	free(game->xpm->so_file_content);
	game->xpm->so_file_content = NULL;
}
