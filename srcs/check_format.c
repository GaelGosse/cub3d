/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:13:20 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 11:15:17 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_corner(t_game *game)
{
	int	i_big;
	int	i_lil;

	i_big = 1;
	i_lil = 0;
	while (game->map->map_tmp[i_big])
	{
		i_lil = 0;
		while (game->map->map_tmp[i_big][i_lil])
		{
			if (game->map->map_tmp[i_big][i_lil] == game->perso)
			{
				check_wall_in_map_1(game, i_big, i_lil);
				check_wall_in_map_2(game, i_big, i_lil);
			}
			i_lil++;
		}
		i_big++;
	}
}

void	check_wall_in_map_1(t_game *game, int i_big, int i_lil)
{
	if (game->map->map_tmp[i_big - 1][i_lil] == '1' \
	&& game->map->map_tmp[i_big][i_lil + 1] == '1' \
	&& (game->map->map_tmp[i_big - 1][i_lil + 1] == ' ' \
	|| game->map->map_tmp[i_big - 1][i_lil + 1] == '0'))
	{
		game->map->map_tmp[i_big - 1][i_lil + 1] = '1';
		game->map->map_org[i_big - 1][i_lil + 1] = '1';
	}
	if (game->map->map_tmp[i_big + 1][i_lil] == '1' \
	&& game->map->map_tmp[i_big][i_lil + 1] == '1' \
	&& (game->map->map_tmp[i_big + 1][i_lil + 1] == ' ' \
	|| game->map->map_tmp[i_big + 1][i_lil + 1] == '0'))
	{
		game->map->map_tmp[i_big + 1][i_lil + 1] = '1';
		game->map->map_org[i_big + 1][i_lil + 1] = '1';
	}
}

void	check_wall_in_map_2(t_game *game, int i_big, int i_lil)
{
	if (game->map->map_tmp[i_big + 1][i_lil] == '1' \
	&& game->map->map_tmp[i_big][i_lil - 1] == '1' \
	&& (game->map->map_tmp[i_big + 1][i_lil - 1] == ' ' \
	|| game->map->map_tmp[i_big + 1][i_lil - 1] == '0'))
	{
		game->map->map_tmp[i_big + 1][i_lil - 1] = '1';
		game->map->map_org[i_big + 1][i_lil - 1] = '1';
	}
	if (game->map->map_tmp[i_big - 1][i_lil] == '1' \
	&& game->map->map_tmp[i_big][i_lil - 1] == '1' \
	&& (game->map->map_tmp[i_big - 1][i_lil - 1] == ' ' \
	|| game->map->map_tmp[i_big - 1][i_lil - 1] == '0'))
	{
		game->map->map_tmp[i_big - 1][i_lil - 1] = '1';
		game->map->map_org[i_big - 1][i_lil - 1] = '1';
	}
}
