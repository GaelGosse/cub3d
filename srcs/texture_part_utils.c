/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_part_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:21:53 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/19 08:31:46 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_word(char *new_w)
{
	int	x;

	x = 0;
	while (new_w[x])
	{
		printf(BACK_CYAN"%c"RST"", new_w[x]);
		x++;
	}
	printf(BACK_RED"%i"RST"\n", new_w[x]);
}

int	check_tx(t_game *game)
{
	if (access(game->map->wall_no, F_OK) != 0)
		return (printf("no: No such file or directory: "BACK_RED"%s"RST"\n", \
		game->map->wall_no), FAIL);
	if (access(game->map->wall_ea, F_OK) != 0)
		return (printf("ea: No such file or directory: "BACK_RED"%s"RST"\n", \
		game->map->wall_ea), FAIL);
	if (access(game->map->wall_so, F_OK) != 0)
		return (printf("so: No such file or directory: "BACK_RED"%s"RST"\n", \
		game->map->wall_so), FAIL);
	if (access(game->map->wall_we, F_OK) != 0)
		return (printf("we: No such file or directory: "BACK_RED"%s"RST"\n", \
		game->map->wall_we), FAIL);
	return (SUCCESS);
}
