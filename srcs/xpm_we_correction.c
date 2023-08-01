/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_we_correction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:03:27 by gael              #+#    #+#             */
/*   Updated: 2023/08/01 15:44:41 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	xpm_we_correct(t_game *g)
{
	int		i;
	int		n_comm;

	n_comm = 0;
	i = 0;
	while (g->xpm->we_tab_file[i])
	{
		if (g->xpm->we_tab_file[i][0] == '/' \
		&& g->xpm->we_tab_file[i][1] == '*' \
		&& g->xpm->we_tab_file[i][ft_strlen(g->xpm->we_tab_file[i]) - 2] == '*' \
		&& g->xpm->we_tab_file[i][ft_strlen(g->xpm->we_tab_file[i]) - 1] == '/')
			n_comm++;
		i++;
	}
	xpm_we_wo_comm(g, n_comm);
}

void	xpm_we_wo_comm(t_game *g, int n_comm)
{
	char	**tab_tmp;
	int		len;
	int		i;
	int		j;

	tab_tmp = NULL;
	len = 0;
	len = tab_len(g->xpm->we_tab_file) - n_comm + 1;
	tab_tmp = malloc(sizeof(char *) * (len));
	i = 0;
	j = 0;
	while (g->xpm->we_tab_file[i])
	{
		if (g->xpm->we_tab_file[i][0] == '/' \
		&& g->xpm->we_tab_file[i][1] == '*' \
		&& g->xpm->we_tab_file[i][ft_strlen(g->xpm->we_tab_file[i]) - 2] == '*' \
		&& g->xpm->we_tab_file[i][ft_strlen(g->xpm->we_tab_file[i]) - 1] == '/')
			i++;
		else
		{
			tab_tmp[j] = ft_strdup(g->xpm->we_tab_file[i]);
			j++;
			i++;
		}
	}
	tab_tmp[j] = NULL;
	xpm_we_copy_tab(g, tab_tmp);
}

int	xpm_we_copy_tab(t_game *game, char **tmp)
{
	int	i;

	i = 0;
	free_tab_str(game->xpm->we_tab_file);
	game->xpm->we_tab_file = malloc(sizeof(char *) * (tab_len(tmp) + 1));
	if (!game->xpm->we_tab_file)
		return (printf("game->xpm_tab copy_tab failed\n"), FAIL);
	while (tmp[i])
	{
		game->xpm->we_tab_file[i] = xpm_we_keep_metadata(tmp, i);
		i++;
	}
	game->xpm->we_tab_file[i] = NULL;
	free_tab_str(tmp);
	return (SUCCESS);
}

int	xpm_we_read_1line(t_game *game)
{
	char	**line;
	int		i;
	int		j;

	i = 0;
	line = ft_split(game->xpm->we_tab_file[i], ' ');
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
	game->xpm->we_tab_start = ft_atoi(line[2]);
	game->xpm->we_width_height = ft_atoi(line[1]);
	xpm_we_set_len_n_color(game, line);
	return (free_tab_str(line), SUCCESS);
}

int	xpm_we_set_len_n_color(t_game *g, char **line)
{
	int	i_color;
	int	i_tab_file;

	i_tab_file = 1;
	i_color = -1;
	if (ft_atoi(line[2]) > 96)
		return (printf("Too much colors\n"), FAIL);
	g->xpm->we_colors = malloc(sizeof(int *) * (ft_atoi(line[2]) + 1));
	if (!g->xpm->we_colors)
		return (printf("xpm colors failed\n"), FAIL);
	while (++i_color < ft_atoi(line[2]))
	{
		if (g->xpm->we_tab_file[i_tab_file][1] != ' '
		&& g->xpm->we_tab_file[i_tab_file][2] != 'c'
		&& g->xpm->we_tab_file[i_tab_file][3] != ' ')
			return (FAIL);
		g->xpm->we_colors[i_color] = malloc(sizeof(int) * (4));
		if (!g->xpm->we_colors[i_color])
			return (FAIL);
		g->xpm->we_colors[i_color][0] = g->xpm->we_tab_file[i_tab_file][0];
		if (g->xpm->we_tab_file[i_tab_file][4] == '#')
			xpm_we_hex_to_dec(g, i_color, i_tab_file);
		else if (xpm_we_letter_color(g, i_color, i_tab_file) == FAIL)
			return (FAIL);
		i_tab_file++;
	}
	return (SUCCESS);
}
