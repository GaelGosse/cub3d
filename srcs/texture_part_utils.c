/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_part_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:21:53 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/25 22:53:02 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_tx(t_game *game)
{
	if (access(game->map->wall_no, F_OK) != 0)
		return (printf("No such file or directory: %s\n", \
		game->map->wall_no), FAIL);
	if (access(game->map->wall_ea, F_OK) != 0)
		return (printf("No such file or directory: %s\n", \
		game->map->wall_ea), FAIL);
	if (access(game->map->wall_so, F_OK) != 0)
		return (printf("No such file or directory: %s\n", \
		game->map->wall_so), FAIL);
	if (access(game->map->wall_we, F_OK) != 0)
		return (printf("No such file or directory: %s\n", \
		game->map->wall_we), FAIL);
	return (SUCCESS);
}
