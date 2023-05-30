/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:01:41 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/26 07:30:27 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_propagation(t_game *game)
{
	int	ite_propa1;
	int	ite_propa2;
	int	counter_p;
	int	fail;

	fail = 0;
	counter_p = 0;
	ite_propa1 = -1;
	while (game->map->map_chck[++ite_propa1])
	{
		ite_propa2 = -1;
		while (game->map->map_chck[ite_propa1][++ite_propa2])
		{
			if (game->map->map_chck[ite_propa1][ite_propa2] == 'P')
			{
				if (ft_replace_around(game, ite_propa1, ite_propa2) == FAIL)
					fail++;
				ft_replace_around(game, ite_propa1, ite_propa2);
				counter_p++;
			}
		}
	}
	if (counter_p != fail)
		return (FAIL);
	return (SUCCESS);
}

int	ft_replace_around(t_game *game, int ite_big, int ite_lil)
{
	if (game->map->map_chck[ite_big][ite_lil + 1] == '0')
	{
		game->map->map_chck[ite_big][ite_lil + 1] = 'P';
		return (SUCCESS);
	}
	else if (game->map->map_chck[ite_big][ite_lil - 1] == '0')
	{
		game->map->map_chck[ite_big][ite_lil - 1] = 'P';
		return (SUCCESS);
	}
	else if (game->map->map_chck[ite_big + 1][ite_lil] == '0')
	{
		game->map->map_chck[ite_big + 1][ite_lil] = 'P';
		return (SUCCESS);
	}
	else if (game->map->map_chck[ite_big - 1][ite_lil] == '0')
	{
		game->map->map_chck[ite_big - 1][ite_lil] = 'P';
		return (SUCCESS);
	}
	return (FAIL);
}

int	ft_valid_wall(t_game *game)
{
	int	ite_reach_row;
	int	ite_reach_col;

	while (ft_propagation(game) == FAIL)
	{
		ft_propagation(game);
	}
	// ite_reach_row = 0;
	// while (game->map->map_chck[ite_reach_row])
	// {
	// 	ite_reach_col = 0;
	// 	while (game->map->map_chck[ite_reach_row][ite_reach_col])
	// 	{
	// 		if (game->map->map_chck[ite_reach_row][ite_reach_col] == 'E')
	// 			if (ft_exit_reachable(game, ite_reach_row,
	// 				ite_reach_col) == FAIL)
	// 				return (ft_free_parsing(game,
	// 				"Invalid path leading to C and E\n"), FAIL);
	// 		ite_reach_col++;
	// 	}
	// 	ite_reach_row++;
	// }
	(void)ite_reach_col;
	(void)ite_reach_row;
	return (SUCCESS);
}
