/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:52:47 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/13 18:36:08 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	floor_ceil_part(t_game *game, char *line)
{
	// if (wrong_letter_fc(line) == FAIL)
	// 	return (FAIL);

	if (line[0] && line[0] != 'F' && line[0] != 'C' && line[1] && line[1] == ' ')
		return (printf(RED"Err: %c (%i) wrong letter for floor or ceil \n"RST, line[0], line[0]), FAIL);
	if (game->map->ceil == NULL && check_ceil(game, line) == FAIL)
		return (printf("Err: problem with ceil\n"), FAIL);
	if (game->map->floor == NULL && check_floor(game, line) == FAIL)
		return (printf("Err: problem with floor\n"), FAIL);
	return (SUCCESS);
}

int	check_floor(t_game *game, char *line)
{
	char	*color;
	char	*str_tmp;
	char	**tab_tmp;
	int		i_rgb;

	i_rgb = -1;
	color = ft_strdup_len(line, 1, ft_strlen(line));
	if (!color)
		return (FAIL);
	if (line[0] == 'F' && line[1] && line[1] == ' ')
	{
		if (game->map->floor != NULL)
			return (printf(RED"Err: floor already set %s\n"RST, game->map->wall_no), FAIL);
		str_tmp = ft_strdup_len(line, 1, ft_strlen(line));
		tab_tmp = ft_split(str_tmp, ',');
		free(str_tmp);
		game->map->floor = malloc(sizeof(int) * (3));
		while (tab_tmp[++i_rgb])
		{
			game->map->floor[i_rgb] = ft_atoi(tab_tmp[i_rgb]);
			free(tab_tmp[i_rgb]);
			if (game->map->floor[i_rgb] < 0 || game->map->floor[i_rgb] > 255)
				return (free(tab_tmp), FAIL);
		}
	}
	free(tab_tmp);
	return (SUCCESS);
}

int	check_ceil(t_game *game, char *line)
{
	char	*color;
	char	*str_tmp;
	char	**tab_tmp;
	int		i_rgb;

	i_rgb = -1;
	color = ft_strdup_len(line, 1, ft_strlen(line));
	if (!color)
		return (FAIL);
	if (line[0] == 'C' && line[1] && line[1] == ' ')
	{
		if (game->map->ceil != NULL)
			return (printf(RED"Err: ceil already set %s\n"RST, game->map->wall_ea), FAIL);
		str_tmp = ft_strdup_len(line, 1, ft_strlen(line));
		tab_tmp = ft_split(str_tmp, ',');
		free(str_tmp);
		game->map->ceil = malloc(sizeof(int) * (3));
		while (tab_tmp[++i_rgb])
		{
			game->map->ceil[i_rgb] = ft_atoi(tab_tmp[i_rgb]);
			free(tab_tmp[i_rgb]);
			if (game->map->ceil[i_rgb] < 0 || game->map->ceil[i_rgb] > 255)
				return (free(tab_tmp), FAIL);
		}
	}
	return (SUCCESS);
}
