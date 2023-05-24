/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:52:47 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/24 23:08:52 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_empty_line(char *line)
{
	int	ite_empty;

	ite_empty = 0;
	while (line[ite_empty])
	{
		if ((int)line[ite_empty] != 32 && (int)line[ite_empty] != 9)
			return (FAIL);
		ite_empty++;
	}
	return (SUCCESS);
}

int	texture_part(char *line)
{
	int	ite_check;

	ite_check = -1;
	while (line[++ite_check])
	{
		printf("ft_strdup_len(line, 2, ft_strlen(line) - 1): %s\n", ft_strdup_len(line, 2, ft_strlen(line) - 1));
		if (line[ite_check] == 'N' && line[ite_check + 1] == 'O' \
		&& line[ite_check] == ' ' && game->map->wall_no == NULL)
			game->map->wall_no = ft_strdup_len(line, 2, ft_strlen(line) - 1);
		if (line[ite_check] == 'E' && line[ite_check + 1] == 'A' \
		&& line[ite_check] == ' ' && game->map->wall_ea == NULL)
			game->map->wall_ea = ft_strdup_len(line, 2, ft_strlen(line) - 1);
		if (line[ite_check] == 'S' && line[ite_check + 1] == 'O' \
		&& line[ite_check] == ' ' && game->map->wall_so == NULL)
			game->map->wall_so = ft_strdup_len(line, 2, ft_strlen(line) - 1);
		if (line[ite_check] == 'W' && line[ite_check + 1] == 'E' \
		&& line[ite_check] == ' ' && game->map->wall_we == NULL)
			game->map->wall_we = ft_strdup_len(line, 2, ft_strlen(line) - 1);
	}
	return (SUCCESS);
}
