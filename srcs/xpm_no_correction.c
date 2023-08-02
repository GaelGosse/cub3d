/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_no_correction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:03:27 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 11:21:50 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_no_correct(t_game *g)
{
	int		i;
	int		n_comm;

	n_comm = 0;
	i = 0;
	while (g->xpm->no_tab_file[i])
	{
		if (g->xpm->no_tab_file[i][0] == '/' \
		&& g->xpm->no_tab_file[i][1] == '*' \
		&& g->xpm->no_tab_file[i][ft_strlen(g->xpm->no_tab_file[i]) - 2] == '*' \
		&& g->xpm->no_tab_file[i][ft_strlen(g->xpm->no_tab_file[i]) - 1] == '/')
		{
			n_comm++;
		}
		i++;
	}
	return (xpm_no_wo_comm(g, n_comm));
}

int	xpm_no_wo_comm(t_game *g, int n_comm)
{
	char	**tab_tmp;
	int		len;
	int		i;
	int		j;

	tab_tmp = NULL;
	len = 0;
	len = tab_len(g->xpm->no_tab_file) - n_comm + 1;
	tab_tmp = malloc(sizeof(char *) * (len));
	i = 0;
	j = 0;
	while (g->xpm->no_tab_file[i])
	{
		if (g->xpm->no_tab_file[i][0] == '/' \
		&& g->xpm->no_tab_file[i][1] == '*' \
		&& g->xpm->no_tab_file[i][ft_strlen(g->xpm->no_tab_file[i]) - 2] == '*' \
		&& g->xpm->no_tab_file[i][ft_strlen(g->xpm->no_tab_file[i]) - 1] == '/')
			i++;
		else
		{
			tab_tmp[j] = ft_strdup(g->xpm->no_tab_file[i]);
			j++;
			i++;
		}
	}
	tab_tmp[j] = NULL;
	return (xpm_no_copy_tab(g, tab_tmp));
}

int	xpm_no_copy_tab(t_game *game, char **tmp)
{
	int	i;

	i = 0;
	free_tab_str(game->xpm->no_tab_file);
	game->xpm->no_tab_file = malloc(sizeof(char *) * (tab_len(tmp) + 1));
	if (!game->xpm->no_tab_file)
		return (printf("game->xpm_tab copy_tab failed\n"), FAIL);
	while (tmp[i])
	{
		game->xpm->no_tab_file[i] = xpm_no_keep_metadata(tmp, i);
		i++;
	}
	game->xpm->no_tab_file[i] = NULL;
	free_tab_str(tmp);
	return (SUCCESS);
}

int	xpm_no_read_1line(t_game *game)
{
	char	**line;
	int		i;
	int		j;

	i = 0;
	line = ft_split(game->xpm->no_tab_file[i], ' ');
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
	game->xpm->no_tab_start = ft_atoi(line[2]);
	xpm_no_set_len_n_color(game, line);
	game->xpm->no_width_height = ft_atoi(line[1]);
	return (free_tab_str(line), SUCCESS);
}

int	xpm_no_set_len_n_color(t_game *g, char **line)
{
	int	i_color;
	int	i_tab_file;

	i_tab_file = 1;
	i_color = 0;
	if (ft_atoi(line[2]) > 96)
		return (printf("Too much colors\n"), FAIL);
	if (xpm_no_init_color(g, line) == FAIL)
		return (FAIL);
	while (i_color < ft_atoi(line[2]))
	{
		if (g->xpm->no_tab_file[i_tab_file][1] != ' '
		&& g->xpm->no_tab_file[i_tab_file][2] != 'c'
		&& g->xpm->no_tab_file[i_tab_file][3] != ' ')
			return (FAIL);
		g->xpm->no_colors[i_color] = malloc(sizeof(int) * (4));
		if (!g->xpm->no_colors[i_color])
			return (FAIL);
		printf(BOLD_GREEN"%i: "BACK_GREEN"%c"RESET"\n", i_color,  g->xpm->no_tab_file[i_tab_file][0]);
		g->xpm->no_colors[i_color][0] = g->xpm->no_tab_file[i_tab_file][0];
		if (g->xpm->no_tab_file[i_tab_file][4] == '#')
			xpm_no_hex_to_dec(g, i_color, i_tab_file);
		else if (xpm_no_letter_color(g, i_color, i_tab_file) == FAIL)
			return (FAIL);
		i_tab_file++;
		i_color++;
	}
	return (SUCCESS);
}
