/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:01:41 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/16 11:02:01 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

// int	ft_propagation(t_game *game)
// {
// 	int	ite_propa1;
// 	int	ite_propa2;
// 	int	counter_p;
// 	int	fail;

// 	fail = 0;
// 	counter_p = 0;
// 	ite_propa1 = -1;
// 	while (game->map->map_tmp[++ite_propa1])
// 	{
// 		ite_propa2 = -1;
// 		while (game->map->map_tmp[ite_propa1][++ite_propa2])
// 		{
// 			if (game->map->map_tmp[ite_propa1][ite_propa2] == 'P')
// 			{
// 				if (ft_replace_around(game, ite_propa1, ite_propa2) == FAIL)
// 					fail++;
// 				ft_replace_around(game, ite_propa1, ite_propa2);
// 				counter_p++;
// 			}
// 		}
// 	}
// 	if (counter_p != fail)
// 		return (FAIL);
// 	return (SUCCESS);
// }

// int	ft_replace_around(t_game *game, int ite_big, int ite_lil)
// {
// 	if (game->map->map_tmp[ite_big][ite_lil + 1] == '0')
// 	{
// 		game->map->map_tmp[ite_big][ite_lil + 1] = 'P';
// 		return (SUCCESS);
// 	}
// 	else if (game->map->map_tmp[ite_big][ite_lil - 1] == '0')
// 	{
// 		game->map->map_tmp[ite_big][ite_lil - 1] = 'P';
// 		return (SUCCESS);
// 	}
// 	else if (game->map->map_tmp[ite_big + 1][ite_lil] == '0')
// 	{
// 		game->map->map_tmp[ite_big + 1][ite_lil] = 'P';
// 		return (SUCCESS);
// 	}
// 	else if (game->map->map_tmp[ite_big - 1][ite_lil] == '0')
// 	{
// 		game->map->map_tmp[ite_big - 1][ite_lil] = 'P';
// 		return (SUCCESS);
// 	}
// 	return (FAIL);
// }

// int	ft_valid_wall(t_game *game)
// {
// 	int	ite_reach_row;
// 	int	ite_reach_col;

// 	while (ft_propagation(game) == FAIL)
// 	{
// 		ft_propagation(game);
// 	}
// 	// ite_reach_row = 0;
// 	// while (game->map->map_tmp[ite_reach_row])
// 	// {
// 	// 	ite_reach_col = 0;
// 	// 	while (game->map->map_tmp[ite_reach_row][ite_reach_col])
// 	// 	{
// 	// 		if (game->map->map_tmp[ite_reach_row][ite_reach_col] == 'E')
// 	// 			if (ft_exit_reachable(game, ite_reach_row,
// 	// 				ite_reach_col) == FAIL)
// 	// 				return (ft_free_parsing(game,
// 	// 				"Invalid path leading to C and E\n"), FAIL);
// 	// 		ite_reach_col++;
// 	// 	}
// 	// 	ite_reach_row++;
// 	// }
// 	(void)ite_reach_col;
// 	(void)ite_reach_row;
// 	return (SUCCESS);
// }

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
				return (printf("wrong letters in map\n"), FAIL);
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
	return (SUCCESS);
}

int	hole_in_wall(t_game *game)
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
			if (game->map->map_org[i_big][i_lil] == game->perso)
				printf(YELLOW"%c"RESET, game->map->map_org[i_big][i_lil]);
		}
	}
	return (SUCCESS);
}
