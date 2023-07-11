/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:13:20 by gael              #+#    #+#             */
/*   Updated: 2023/07/11 11:46:30 by gael             ###   ########.fr       */
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
				if (game->map->map_tmp[i_big - 1][i_lil] == '1' \
				&& game->map->map_tmp[i_big][i_lil + 1] == '1' \
				&& (game->map->map_tmp[i_big - 1][i_lil + 1] == ' ' \
				|| game->map->map_tmp[i_big - 1][i_lil + 1] == '0'))
				{
					game->map->map_tmp[i_big - 1][i_lil + 1] = '1';
					game->map->map_org[i_big - 1][i_lil + 1] = '1';
					// print_map(game->map->map_org);
					// usleep(1500000);
					// printf("\033c\n");
				}
				if (game->map->map_tmp[i_big + 1][i_lil] == '1' \
				&& game->map->map_tmp[i_big][i_lil + 1] == '1' \
				&& (game->map->map_tmp[i_big + 1][i_lil + 1] == ' ' \
				|| game->map->map_tmp[i_big + 1][i_lil + 1] == '0'))
				{
					game->map->map_tmp[i_big + 1][i_lil + 1] = '1';
					game->map->map_org[i_big + 1][i_lil + 1] = '1';
					// print_map(game->map->map_org);
					// usleep(1500000);
					// printf("\033c\n");
				}
				if (game->map->map_tmp[i_big + 1][i_lil] == '1' \
				&& game->map->map_tmp[i_big][i_lil - 1] == '1' \
				&& (game->map->map_tmp[i_big + 1][i_lil - 1] == ' ' \
				|| game->map->map_tmp[i_big + 1][i_lil - 1] == '0'))
				{
					game->map->map_tmp[i_big + 1][i_lil - 1] = '1';
					game->map->map_org[i_big + 1][i_lil - 1] = '1';
					// print_map(game->map->map_org);
					// usleep(1500000);
					// printf("\033c\n");
				}
				if (game->map->map_tmp[i_big - 1][i_lil] == '1' \
				&& game->map->map_tmp[i_big][i_lil - 1] == '1' \
				&& (game->map->map_tmp[i_big - 1][i_lil - 1] == ' ' \
				|| game->map->map_tmp[i_big - 1][i_lil - 1] == '0'))
				{
					game->map->map_tmp[i_big - 1][i_lil - 1] = '1';
					game->map->map_org[i_big - 1][i_lil - 1] = '1';
					// print_map(game->map->map_org);
					// usleep(1500000);
					// printf("\033c\n");
				}
			}
			i_lil++;
		}
		i_big++;
	}
}
