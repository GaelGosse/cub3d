/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:57:52 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 13:03:04 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_xpm(t_game *game)
{
	int	i;

	i = -1;
	if (game->xpm)
	{
		free_xpm_no(game, i);
		free_xpm_we(game, i);
		free_xpm_ea(game, i);
		free_xpm_so(game, i);
		free(game->xpm);
		game->xpm = NULL;
	}
}

void	free_xpm_no(t_game *game, int i)
{
	while (++i < game->xpm->no_tab_start)
	{
		if (game->xpm->no_colors[i])
		{
			free(game->xpm->no_colors[i]);
			game->xpm->no_colors[i] = NULL;
		}
	}
	if (game->xpm->no_colors)
	{
		free(game->xpm->no_colors);
		game->xpm->no_colors = NULL;
	}
	if (game->xpm->no_tab_file)
	{
		free_tab_str(game->xpm->no_tab_file);
		game->xpm->no_tab_file = NULL;
	}
	if (game->xpm->no_file_content)
	{
		free(game->xpm->no_file_content);
		game->xpm->no_file_content = NULL;
	}
}

void	free_xpm_we(t_game *game, int i)
{
	while (++i < game->xpm->we_tab_start)
	{
		if (game->xpm->we_colors[i])
		{
			free(game->xpm->we_colors[i]);
			game->xpm->we_colors[i] = NULL;
		}
		i++;
	}
	if (game->xpm->we_colors)
	{
		free(game->xpm->we_colors);
		game->xpm->we_colors = NULL;
	}
	if (game->xpm->we_tab_file)
	{
		free_tab_str(game->xpm->we_tab_file);
		game->xpm->we_tab_file = NULL;
	}
	if (game->xpm->we_file_content)
	{
		free(game->xpm->we_file_content);
		game->xpm->we_file_content = NULL;
	}
}

void	free_xpm_ea(t_game *game, int i)
{
	while (++i < game->xpm->ea_tab_start)
	{
		if (game->xpm->ea_colors[i])
		{
			free(game->xpm->ea_colors[i]);
			game->xpm->ea_colors[i] = NULL;
		}
		i++;
	}
	if (game->xpm->ea_colors)
	{
		free(game->xpm->ea_colors);
		game->xpm->ea_colors = NULL;
	}
	if (game->xpm->ea_tab_file)
	{
		free_tab_str(game->xpm->ea_tab_file);
		game->xpm->ea_tab_file = NULL;
	}
	if (game->xpm->ea_file_content)
	{
		free(game->xpm->ea_file_content);
		game->xpm->ea_file_content = NULL;
	}
}

void	free_xpm_so(t_game *game, int i)
{
	while (++i < game->xpm->so_tab_start)
	{
		if (game->xpm->so_colors[i])
		{
			free(game->xpm->so_colors[i]);
			game->xpm->so_colors[i] = NULL;
		}
	}
	if (game->xpm->so_colors)
	{
		free(game->xpm->so_colors);
		game->xpm->so_colors = NULL;
	}
	if (game->xpm->so_tab_file)
	{
		free_tab_str(game->xpm->so_tab_file);
		game->xpm->so_tab_file = NULL;
	}
	if (game->xpm->so_file_content)
	{
		free(game->xpm->so_file_content);
		game->xpm->so_file_content = NULL;
	}
}
