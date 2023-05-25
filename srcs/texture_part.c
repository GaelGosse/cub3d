/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:52:47 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/25 18:29:26 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	texture_part(t_game *game, char *line)
{
	if (wrong_letter_tx(line) == FAIL)
		return (FAIL);
	if (check_no(game, line) == FAIL)
		return (FAIL);
	if (check_ea(game, line) == FAIL)
		return (FAIL);
	if (check_so(game, line) == FAIL)
		return (FAIL);
	if (check_we(game, line) == FAIL)
		return (FAIL);
	if (check_tx(game, line) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	check_no(t_game *game, char *line)
{
	if (line[0] == 'N' && line[0 + 1] == 'O' \
	&& line[0 + 2] == ' ' && game->map->wall_no != NULL)
		return (printf(RED"Err: NO already set %s\n"RST, game->map->wall_no), \
		FAIL);
	if (line[0] == 'N' && line[0 + 1] == 'O' \
	&& line[0 + 2] == ' ' && game->map->wall_no == NULL)
		game->map->wall_no = ft_strdup_len(line, 2, ft_strlen(line));
	return (SUCCESS);
}

int	check_ea(t_game *game, char *line)
{
	if (line[0] == 'E' && line[0 + 1] == 'A' \
	&& line[0 + 2] == ' ' && game->map->wall_ea != NULL)
		return (printf(RED"Err: EA already set %s\n"RST, game->map->wall_ea), \
		FAIL);
	if (line[0] == 'E' && line[0 + 1] == 'A' \
	&& line[0 + 2] == ' ' && game->map->wall_ea == NULL)
		game->map->wall_ea = ft_strdup_len(line, 2, ft_strlen(line));
	return (SUCCESS);
}

int	check_so(t_game *game, char *line)
{
	if (line[0] == 'S' && line[0 + 1] == 'O' \
	&& line[0 + 2] == ' ' && game->map->wall_so != NULL)
		return (printf(RED"Err: SO already set %s\n"RST, game->map->wall_so), \
		FAIL);
	if (line[0] == 'S' && line[0 + 1] == 'O' \
	&& line[0 + 2] == ' ' && game->map->wall_so == NULL)
		game->map->wall_so = ft_strdup_len(line, 2, ft_strlen(line));
	return (SUCCESS);
}

int	check_we(t_game *game, char *line)
{
	if (line[0] == 'W' && line[0 + 1] == 'E' \
	&& line[0 + 2] == ' ' && game->map->wall_we != NULL)
		return (printf(RED"Err: WE already set %s\n"RST, game->map->wall_we), \
		FAIL);
	if (line[0] == 'W' && line[0 + 1] == 'E' \
	&& line[0 + 2] == ' ' && game->map->wall_we == NULL)
		game->map->wall_we = ft_strdup_len(line, 2, ft_strlen(line));
	return (SUCCESS);
}

