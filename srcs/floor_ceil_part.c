/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:52:47 by ggosse            #+#    #+#             */
/*   Updated: 2023/08/02 20:36:54 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	floor_ceil_part(t_game *game, char *line)
{
	char	*color;

	color = NULL;
	if (game->map->wall_no == NULL || game->map->wall_ea == NULL || \
	game->map->wall_so == NULL || game->map->wall_we == NULL)
		return (printf("a wall is missing in .cub\n"), FAIL);
	if (line[0] && line[0] != 'F' && \
	line[0] != 'C' && line[1] && line[1] == ' ')
		return (printf(RED"Err: %c (%i) wrong letter for floor or ceil \n"RST, \
		line[0], line[0]), FAIL);
	if (game->map->ceil == NULL && check_ceil(game, line, color) == FAIL)
		return (FAIL);
	else if (game->map->floor == NULL && check_floor(game, line, color) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	check_floor(t_game *game, char *line, char *color)
{
	color = ft_strdup_len(line, 1, ft_strlen(line));
	if (!color)
		return (printf("empty or wrong color\n"), FAIL);
	if (line[0] == 'F' && line[1] && line[1] == ' ')
	{
		if (check_floor_content(game, &color) == FAIL)
		{
			if (color != NULL)
			{
				free(color);
				color = NULL;
			}
			return (FAIL);
		}
	}
	if (color != NULL)
	{
		free(color);
		color = NULL;
	}
	return (SUCCESS);
}

int	check_floor_content(t_game *g, char **color)
{
	char	*str_tmp;
	char	**tab_tmp;
	int		rgb;

	rgb = -1;
	str_tmp = ft_strtrim((*color), " \n");
	tab_tmp = ft_split(str_tmp, ',');
	if (g->map->floor != NULL)
		return (printf("Err: floor already set %s\n", g->map->wall_no), FAIL);
	free(str_tmp);
	g->map->floor = malloc(sizeof(int) * (3));
	if (!g->map->floor)
		return (printf("malloc floor failed\n"), FAIL);
	if (tab_len(tab_tmp) != 3)
		return (printf("rgb must have 3 int\n"), FAIL);
	while (tab_tmp[++rgb])
	{
		if (check_nbr(tab_tmp[rgb]) == FAIL)
			return (printf("Something wrong with floor\n"), FAIL);
		g->map->floor[rgb] = ft_atoi(tab_tmp[rgb]);
		free(tab_tmp[rgb]);
		if (g->map->floor[rgb] < 0 || g->map->floor[rgb] > 255)
			return (printf("Err: 0 < color < 255\n"), free(tab_tmp), FAIL);
	}
	return (free(tab_tmp), SUCCESS);
}

int	check_ceil(t_game *game, char *line, char *color)
{
	color = ft_strdup_len(line, 1, ft_strlen(line));
	if (!color)
		return (printf("empty or wrong color\n"), FAIL);
	if (line[0] == 'C' && line[1] && line[1] == ' ')
	{
		if (check_ceil_content(game, &color) == FAIL)
		{
			if (color != NULL)
			{
				free(color);
				color = NULL;
			}
			return (FAIL);
		}
	}
	if (color != NULL)
	{
		printf(BOLD_GREEN"%p: "BACK_GREEN"%s"RESET"\n", color, color);
		free(color);
		printf(RED" x "RESET"\n");
		color = NULL;
	}
	return (SUCCESS);
}

int	check_ceil_content(t_game *game, char **color)
{
	char	**tab_tmp;
	char	*str_tmp;
	int		rgb;

	rgb = -1;
	str_tmp = ft_strtrim((*color), " \n");
	tab_tmp = ft_split(str_tmp, ',');
	if (game->map->ceil != NULL)
		return (printf("Err: ceil already set %s\n", game->map->wall_ea), FAIL);
	free(str_tmp);
	game->map->ceil = malloc(sizeof(int) * (3));
	if (!game->map->ceil)
		return (printf("malloc ceil failed\n"), FAIL);
	if (tab_len(tab_tmp) != 3)
		return (printf("rgb must have 3 int\n"), FAIL);
	while (tab_tmp[++rgb])
	{
		if (check_nbr(tab_tmp[rgb]) == FAIL)
			return (printf("Something wrong with ceil\n"), FAIL);
		game->map->ceil[rgb] = ft_atoi(tab_tmp[rgb]);
		free(tab_tmp[rgb]);
		if (game->map->ceil[rgb] < 0 || game->map->ceil[rgb] > 255)
			return (printf("Err: 0 < color < 255\n"), free(tab_tmp), FAIL);
	}
	return (free(tab_tmp), SUCCESS);
}
