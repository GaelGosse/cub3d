/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_part_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:52:47 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/25 18:44:22 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_tx()
{
	if (access(game->map->wall_no, F_OK) != 0)
		return (FAIL);
	if (access(game->map->wall_ea, F_OK) != 0)
		return (FAIL);
	if (access(game->map->wall_so, F_OK) != 0)
		return (FAIL);
	if (access(game->map->wall_we, F_OK) != 0)
		return (FAIL);
	return (SUCCESS);
}
