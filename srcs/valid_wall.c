/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:01:41 by ggosse            #+#    #+#             */
/*   Updated: 2023/07/31 17:03:52 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_letters_map(t_game *game)
{
	int	i_big;
	int	i_lil;

	i_lil = -1;
	i_big = -1;
	while (game->map->map_org[++i_big])
	{
		i_lil = -1;
		while (game->map->map_org[i_big][++i_lil])
		{
			if (game->map->map_org[i_big][i_lil] != 'N' && \
			game->map->map_org[i_big][i_lil] != 'E' && \
			game->map->map_org[i_big][i_lil] != 'S' && \
			game->map->map_org[i_big][i_lil] != 'W' && \
			game->map->map_org[i_big][i_lil] != '1' && \
			game->map->map_org[i_big][i_lil] != '0' && \
			game->map->map_org[i_big][i_lil] != ' ')
				return (printf(RED"Err: %c (%i) wrong letter in map \n"RST, \
				game->map->map_org[i_big][i_lil], \
				game->map->map_org[i_big][i_lil]), FAIL);
		}
	}
	return (SUCCESS);
}

int	check_perso(t_game *game)
{
	int	i_big;
	int	i_lil;

	i_lil = -1;
	i_big = -1;
	while (game->map->map_org[++i_big])
	{
		i_lil = -1;
		while (game->map->map_org[i_big][++i_lil])
		{
			if (game->map->map_org[i_big][i_lil] == 'N' || \
			game->map->map_org[i_big][i_lil] == 'E' || \
			game->map->map_org[i_big][i_lil] == 'S' || \
			game->map->map_org[i_big][i_lil] == 'W')
			{
				if (game->perso != '\0')
					return (printf("one player only\n"), FAIL);
				game->perso = game->map->map_org[i_big][i_lil];
			}
		}
	}
	if (game->perso == '\0')
		return (printf("need one player\n"), FAIL);
	return (SUCCESS);
}

int	is_fault(t_game *game, int row, int col)
{
	if (row + 1 < game->map->height && game->map->map_tmp[row + 1][col] == ' ')
		return (FAIL);
	if (row - 1 >= 0 && game->map->map_tmp[row - 1][col] == ' ')
		return (FAIL);
	if (col + 1 <= game->map->width && game->map->map_tmp[row][col + 1] == ' ')
		return (FAIL);
	if (col - 1 >= 0 && game->map->map_tmp[row][col - 1] == ' ')
		return (FAIL);
	return (SUCCESS);
}

int	hole_in_wall(t_game *game)
{
	int	row;
	int	col;

	col = -1;
	row = -1;
	while (game->map->map_tmp[++row])
	{
		col = -1;
		while (game->map->map_tmp[row][++col])
		{
			if (game->map->map_tmp[row][col] == game->perso)
			{
				if (row == 0 || row + 1 > game->map->height \
				|| col == 0 || col + 1 >= game->map->width)
					return (printf(BOLD_RED"leaks in map... \n"RST), FAIL);
				if (is_fault(game, row, col) == FAIL)
					return (printf(BOLD_RED"leaks in map... \n"RST), FAIL);
			}
		}
	}
	return (SUCCESS);
}
