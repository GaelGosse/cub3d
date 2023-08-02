/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_ea_correction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:03:27 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 13:27:41 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_ea_correct(t_game *g)
{
	int		i;
	int		n_comm;

	n_comm = 0;
	i = 0;
	while (g->xpm->ea_tab_file[i])
	{
		if (g->xpm->ea_tab_file[i][0] == '/' \
		&& g->xpm->ea_tab_file[i][1] == '*' \
		&& g->xpm->ea_tab_file[i][ft_strlen(g->xpm->ea_tab_file[i]) - 2] == '*' \
		&& g->xpm->ea_tab_file[i][ft_strlen(g->xpm->ea_tab_file[i]) - 1] == '/')
			n_comm++;
		i++;
	}
	if (xpm_ea_wo_comm(g, n_comm) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	xpm_ea_wo_comm(t_game *g, int n_comm)
{
	char	**tab_tmp;
	int		len;
	int		i;
	int		j;

	tab_tmp = NULL;
	len = 0;
	len = tab_len(g->xpm->ea_tab_file) - n_comm + 1;
	tab_tmp = malloc(sizeof(char *) * (len));
	if (!tab_tmp)
		return (FAIL);
	i = 0;
	j = 0;
	while (g->xpm->ea_tab_file[i])
	{
		if (g->xpm->ea_tab_file[i][0] == '/' \
		&& g->xpm->ea_tab_file[i][1] == '*' \
		&& g->xpm->ea_tab_file[i][ft_strlen(g->xpm->ea_tab_file[i]) - 2] == '*' \
		&& g->xpm->ea_tab_file[i][ft_strlen(g->xpm->ea_tab_file[i]) - 1] == '/')
			i++;
		else
		{
			tab_tmp[j] = ft_strdup(g->xpm->ea_tab_file[i]);
			j++;
			i++;
		}
	}
	tab_tmp[j] = NULL;
	return (xpm_ea_copy_tab(g, tab_tmp));
}

int	xpm_ea_copy_tab(t_game *game, char **tmp)
{
	int	i;

	i = 0;
	free_tab_str(game->xpm->ea_tab_file);
	game->xpm->ea_tab_file = malloc(sizeof(char *) * (tab_len(tmp) + 1));
	if (!game->xpm->ea_tab_file)
		return (printf("game->xpm_tab copy_tab failed\n"), FAIL);
	while (tmp[i])
	{
		game->xpm->ea_tab_file[i] = xpm_ea_keep_metadata(tmp, i);
		i++;
	}
	game->xpm->ea_tab_file[i] = NULL;
	free_tab_str(tmp);
	return (SUCCESS);
}

int	xpm_ea_read_1line(t_game *game)
{
	char	**line;
	int		i;
	int		j;

	i = 0;
	line = ft_split(game->xpm->ea_tab_file[i], ' ');
	if (!line)
		return (printf("split line failed\n"), FAIL);
	if (tab_len(line) != 4)
		return (free_tab_str(line), printf("expect 4 metadata in xpm\n"), FAIL);
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (ft_isdigit(line[i][j]) == 0)
				return (free_tab_str(line), printf("Not a digit in xpm"), FAIL);
			j++;
		}
		i++;
	}
	game->xpm->ea_tab_start = ft_atoi(line[2]);
	if (xpm_ea_set_len_n_color(game, line) == FAIL)
		return (free_tab_str(line), FAIL);
	game->xpm->ea_width_height = ft_atoi(line[1]);
	return (free_tab_str(line), SUCCESS);
}
