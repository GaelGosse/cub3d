/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:52:47 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/26 07:57:16 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	floor_ceil_part(t_game *game, char *line)
{
	// if (wrong_letter_fc(line) == FAIL)
	// 	return (FAIL);

	if (line[0] && line[0] != 'F' && line[0] != 'C' && line[1] && line[1] == ' ')
		return (printf(RED"Err: %c (%i) wrong letter for floor or ceil \n"RST, line[0], line[0]), FAIL);
	if (check_ceil(game, line) == FAIL)
		return (printf("Err: problem with ceil\n"), FAIL);
	if (check_floor(game, line) == FAIL)
		return (printf("Err: problem with floor\n"), FAIL);
	return (SUCCESS);
}

int	check_floor(t_game *game, char *line)
{
	int		ite_color;
	char	*color;

	ite_color = 0;
	color = ft_strdup_len(line, 1, ft_strlen(line));
	if (!color)
		return (FAIL);
	printf("color: %s\n", color);
	if (line[0] == 'F' && line[1] && line[1] == ' ' && game->map->floor != NULL)
		return (printf(RED"Err: floor already set %s\n"RST, game->map->wall_no), FAIL);
	if (line[0] == 'F' && line[1] && line[1] == ' ' && game->map->floor == NULL)
		game->map->wall_no = ft_strdup_len(line, 1, ft_strlen(line));
	return (SUCCESS);
	(void)ite_color;
}

int	check_ceil(t_game *game, char *line)
{
	int		ite_color;
	char	*color;

	ite_color = 0;
	color = ft_strdup_len(line, 1, ft_strlen(line));
	if (!color)
		return (FAIL);
	printf("color: %s\n", color);
	if (line[0] == 'C' && line[1] && line[1] == ' ' && game->map->ceil != NULL)
		return (printf(RED"Err: ceil already set %s\n"RST, game->map->wall_ea), FAIL);
	if (line[0] == 'C' && line[1] && line[1] == ' ' && game->map->ceil == NULL)
		game->map->wall_ea = ft_strdup_len(line, 1, ft_strlen(line));
	return (SUCCESS);
	(void)ite_color;
}
