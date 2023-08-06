/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:52:47 by ggosse            #+#    #+#             */
/*   Updated: 2023/08/03 18:01:12 by mael             ###   ########.fr       */
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
		return (printf(RED"%c (%i) wrong letter for floor or ceil \n"RST, \
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
		return (printf("floor already set %s\n", g->map->wall_no), \
		free_tab_str(tab_tmp), FAIL);
	free(str_tmp);
	g->map->floor = malloc(sizeof(int) * (3));
	if (!g->map->floor)
		return (printf("malloc floor failed\n"), free_tab_str(tab_tmp), FAIL);
	if (tab_len(tab_tmp) != 3)
		return (printf("rgb must have 3 int\n"), free_tab_str(tab_tmp), FAIL);
	while (tab_tmp[++rgb])
	{
		if (check_nbr(tab_tmp[rgb]) == FAIL)
			return (printf("wrong floor\n"), free_tab_str(tab_tmp), FAIL);
		g->map->floor[rgb] = ft_atoi(tab_tmp[rgb]);
		if (g->map->floor[rgb] < 0 || g->map->floor[rgb] > 255)
			return (printf("Err with colors\n"), free_tab_str(tab_tmp), FAIL);
	}
	return (free_tab_str(tab_tmp), SUCCESS);
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
		free(color);
		color = NULL;
	}
	return (SUCCESS);
}

int	check_ceil_content(t_game *g, char **color)
{
	char	**tab_tmp;
	char	*str_tmp;
	int		rgb;

	rgb = -1;
	str_tmp = ft_strtrim((*color), " \n");
	tab_tmp = ft_split(str_tmp, ',');
	if (g->map->ceil != NULL)
		return (printf("ceil already set %s\n", g->map->wall_ea), \
		free_tab_str(tab_tmp), FAIL);
	free(str_tmp);
	g->map->ceil = malloc(sizeof(int) * (3));
	if (!g->map->ceil)
		return (printf("malloc ceil failed\n"), free_tab_str(tab_tmp), FAIL);
	if (tab_len(tab_tmp) != 3)
		return (printf("rgb must have 3 int\n"), free_tab_str(tab_tmp), FAIL);
	while (tab_tmp[++rgb])
	{
		if (check_nbr(tab_tmp[rgb]) == FAIL)
			return (printf("wrong ceil\n"), free_tab_str(tab_tmp), FAIL);
		g->map->ceil[rgb] = ft_atoi(tab_tmp[rgb]);
		if (g->map->ceil[rgb] < 0 || g->map->ceil[rgb] > 255)
			return (printf("Err with colors\n"), free_tab_str(tab_tmp), FAIL);
	}
	return (free_tab_str(tab_tmp), SUCCESS);
}
