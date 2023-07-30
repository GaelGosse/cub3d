/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_common.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:22:47 by gael              #+#    #+#             */
/*   Updated: 2023/07/30 21:33:04 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_xpm(t_game *game)
{
	game->xpm = malloc(sizeof(t_xpm));
	if (!game->xpm)
		return (printf("Init fov failed \n"), FAIL);
	game->xpm->no_file_content = NULL;
	game->xpm->no_file_map = NULL;
	game->xpm->no_tab_file = NULL;
	game->xpm->no_colors = NULL;
	game->xpm->no_tab_start = FAIL;
	game->xpm->ea_file_content = NULL;
	game->xpm->ea_file_map = NULL;
	game->xpm->ea_tab_file = NULL;
	game->xpm->ea_colors = NULL;
	game->xpm->ea_tab_start = FAIL;
	game->xpm->we_file_content = NULL;
	game->xpm->we_file_map = NULL;
	game->xpm->we_tab_file = NULL;
	game->xpm->we_colors = NULL;
	game->xpm->we_tab_start = FAIL;
	game->xpm->so_file_content = NULL;
	game->xpm->so_file_map = NULL;
	game->xpm->so_tab_file = NULL;
	game->xpm->so_colors = NULL;
	game->xpm->so_tab_start = FAIL;
	return (SUCCESS);
}

int	xpm_parse(t_game *game)
{
	if (init_xpm(game) == FAIL)
		return (FAIL);
	if (xpm_no_parse(game) == FAIL)
		return (FAIL);
	if (xpm_we_parse(game) == FAIL)
		return (FAIL);
	if (xpm_ea_parse(game) == FAIL)
		return (FAIL);
	if (xpm_so_parse(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
