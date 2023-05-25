/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:52:47 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/25 18:24:46 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	floor_ceil_part(t_game *game, char *line)
{
	// if (wrong_letter_fc(line) == FAIL)
	// 	return (FAIL);

	if (line[0] != 'F' && line[0] != 'C')
		return (printf(RED"Err: %c (%i) wrong letter for floor or ceil \n"RST, line[0], line[0]), FAIL);
	check_ceil(game, line);
	check_floor(game, line);
	return (SUCCESS);
}

int	check_floor(t_game *game, char *line)
{
	if (line[0] == 'F' && line[0 + 1] == ' ' && game->map->floor != NULL)
		return (printf(RED"Err: floor already set %s\n"RST, game->map->wall_no), FAIL);
	if (line[0] == 'F' && line[0 + 1] == ' ' && game->map->floor == NULL)
		game->map->wall_no = ft_strdup_len(line, 1, ft_strlen(line));
	return (SUCCESS);
}

int	check_ceil(t_game *game, char *line)
{
	if (line[0] == 'C' && line[0 + 1] == ' ' && game->map->ceil != NULL)
		return (printf(RED"Err: ceil already set %s\n"RST, game->map->wall_ea), FAIL);
	if (line[0] == 'C' && line[0 + 1] == ' ' && game->map->ceil == NULL)
		game->map->wall_ea = ft_strdup_len(line, 1, ft_strlen(line));
	return (SUCCESS);
}
