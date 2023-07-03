/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:19:32 by gael              #+#    #+#             */
/*   Updated: 2023/07/03 14:00:17 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	flooding(t_game *game)
{
	int	i_row;
	int	i_col;
	int	count;

	count = 0;
	i_row = -1;
	i_col = -1;
	while (game->map->map_tmp[++i_row])
	{
		i_col = -1;
		while (game->map->map_tmp[i_row][++i_col])
		{
			if (game->map->map_tmp[i_row][i_col] == game->perso)
			{
				count = 0;
				if (propagation(game, i_row, i_col, count) == SUCCESS)
				{
					printf("\033c\n");
					print_map(game->map->map_tmp);
					usleep(10000);
				}
			}
		}
	}
	return (SUCCESS);
}

int	is_propa_finished(t_game *game)
{
	int	i_row;
	int	i_col;

	i_row = -1;
	i_col = -1;
	while (game->map->map_tmp[++i_row])
	{
		i_col = -1;
		while (game->map->map_tmp[i_row][++i_col])
		{
			if (game->map->map_tmp[i_row][i_col] == game->perso && \
			i_row + 1 < game->map->height && \
			i_col + 1 <= game->map->width && \
			i_row - 1 >= 0 && \
			i_col - 1 >= 0 && \
			(game->map->map_tmp[i_row + 1][i_col] == '0' || \
			game->map->map_tmp[i_row - 1][i_col] == '0' || \
			game->map->map_tmp[i_row][i_col + 1] == '0' || \
			game->map->map_tmp[i_row][i_col - 1] == '0'))
				return (FAIL);
		}
	}
	return (SUCCESS);
}

int	propagation(t_game *game, int row, int col, int count)
{
	if (row + 1 < game->map->height && game->map->map_tmp[row + 1][col] == '0')
	{
		game->map->map_tmp[row + 1][col] = game->perso;
		count++;
	}
	if (row - 1 >= 0 && game->map->map_tmp[row - 1][col] == '0')
	{
		game->map->map_tmp[row - 1][col] = game->perso;
		count++;
	}
	if (col + 1 <= game->map->width && game->map->map_tmp[row][col + 1] == '0')
	{
		game->map->map_tmp[row][col + 1] = game->perso;
		count++;
	}
	if (col - 1 >= 0 && game->map->map_tmp[row][col - 1] == '0')
	{
		game->map->map_tmp[row][col - 1] = game->perso;
		count++;
	}
	if (count > 0)
		return (SUCCESS);
	return (FAIL);
}

int	end_propa(t_game *game, int i_row, int i_col)
{
	if (i_row + 1 < game->map->height && \
	game->map->map_tmp[i_row + 1][i_col] != '1' && \
	game->map->map_tmp[i_row + 1][i_col] != '0' && \
	game->map->map_tmp[i_row + 1][i_col] != game->perso)
		return (FAIL);
	if (i_row - 1 >= 0 && \
	game->map->map_tmp[i_row - 1][i_col] != '1' && \
	game->map->map_tmp[i_row - 1][i_col] != '0' && \
	game->map->map_tmp[i_row - 1][i_col] != game->perso)
		return (FAIL);
	if (i_col + 1 <= game->map->width && \
	game->map->map_tmp[i_row][i_col + 1] != '1' && \
	game->map->map_tmp[i_row][i_col + 1] != '0' && \
	game->map->map_tmp[i_row][i_col + 1] != game->perso)
		return (FAIL);
	if (i_col - 1 >= 0 && \
	game->map->map_tmp[i_row][i_col - 1] != '1' && \
	game->map->map_tmp[i_row][i_col - 1] != '0' && \
	game->map->map_tmp[i_row][i_col - 1] != game->perso)
		return (FAIL);
	return (SUCCESS);
}
