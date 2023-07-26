/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:03:27 by gael              #+#    #+#             */
/*   Updated: 2023/07/25 16:06:40 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	xpm_correct(t_game *g)
{
	int		i;
	int		n_comm;

	n_comm = 0;
	i = 0;
	while (g->xpm->tab_file[i])
	{
		if (g->xpm->tab_file[i][0] == '/' \
		&& g->xpm->tab_file[i][1] == '*' \
		&& g->xpm->tab_file[i][ft_strlen(g->xpm->tab_file[i]) - 2] == '*' \
		&& g->xpm->tab_file[i][ft_strlen(g->xpm->tab_file[i]) - 1] == '/')
			n_comm++;
		i++;
	}
	xpm_wo_comm(g, n_comm);
}

void	xpm_wo_comm(t_game *g, int n_comm)
{
	char	**tab_tmp;
	int		len;
	int		i;
	int		j;

	tab_tmp = NULL;
	len = 0;
	len = tab_len(g->xpm->tab_file) - n_comm + 1;
	tab_tmp = malloc(sizeof(char *) * (len));
	i = 0;
	j = 0;
	while (i < len)
	{
		if (g->xpm->tab_file[i][0] != '/' \
		&& g->xpm->tab_file[i][1] != '*' \
		&& g->xpm->tab_file[i][ft_strlen(g->xpm->tab_file[i]) - 2] != '*' \
		&& g->xpm->tab_file[i][ft_strlen(g->xpm->tab_file[i]) - 1] != '/')
		{
			tab_tmp[j] = ft_strdup(g->xpm->tab_file[i]);
			j++;
		}
		i++;
	}
	tab_tmp[j] = NULL;
	copy_tab_xpm(g, tab_tmp);
}

int	copy_tab_xpm(t_game *game, char **tmp)
{
	int	i;

	i = 0;
	free_tab_str(game->xpm->tab_file);
	game->xpm->tab_file = malloc(sizeof(char *) * (tab_len(tmp) + 1));
	if (!game->xpm->tab_file)
		return (printf("game->xpm_tab copy_tab failed\n"), FAIL);
	while (tmp[i])
	{
		game->xpm->tab_file[i] = keep_metadata_xpm(tmp, i);
		i++;
	}
	game->xpm->tab_file[i] = NULL;
	free_tab_str(tmp);
	return (SUCCESS);
}

int	read_first_line_xpm(t_game *game)
{
	char	**line;
	int		i;
	int		j;

	i = 0;
	line = ft_split(game->xpm->tab_file[i], ' ');
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
	game->xpm->tab_start = ft_atoi(line[2]);
	set_lenth_n_color(game, line);
	return (free_tab_str(line), SUCCESS);
}

int	set_lenth_n_color(t_game *game, char **line)
{
	int i_color;
	int	i_tab_file;

	i_tab_file = 1;
	i_color = 0;
	if (ft_atoi(line[2]) > 96)
		return (printf("Too much colors\n"), FAIL);
	game->xpm->colors = malloc(sizeof(int *) * (ft_atoi(line[2]) + 1));
	if (!game->xpm->colors)
		return (printf("xpm colors failed\n"), FAIL);
	while (i_color < ft_atoi(line[2]))
	{
		if (game->xpm->tab_file[i_tab_file][1] != ' '
		&& game->xpm->tab_file[i_tab_file][2] != 'c'
		&& game->xpm->tab_file[i_tab_file][3] != ' ')
			return (FAIL);
		game->xpm->colors[i_color] = malloc(sizeof(int) * (4));
		if (!game->xpm->colors[i_color])
			return (FAIL);
		game->xpm->colors[i_color][0] = game->xpm->tab_file[i_tab_file][0];
		if (game->xpm->tab_file[i_tab_file][4] == '#')
		{
			game->xpm->colors[i_color][1] = hex_to_dec(ft_strdup_len(game->xpm->tab_file[i_tab_file], 5, 7));
			game->xpm->colors[i_color][2] = hex_to_dec(ft_strdup_len(game->xpm->tab_file[i_tab_file], 7, 9));
			game->xpm->colors[i_color][3] = hex_to_dec(ft_strdup_len(game->xpm->tab_file[i_tab_file], 9, 11));
		}
		else if (set_color_when_no_digit(game, i_color, i_tab_file) == FAIL)
			return (FAIL); // free
		i_tab_file++;
		i_color++;
	}
	return (SUCCESS);
}

int	set_color_when_no_digit(t_game *game, int i_color, int i_tab_file)
{
	char *tmp;

	tmp = ft_strdup_len(game->xpm->tab_file[i_tab_file], 4, ft_strlen(game->xpm->tab_file[i_tab_file]));
	if (!tmp)
		return (FAIL);
	printf(BACK_GREEN"%s"RESET"\n", tmp);
	if (ft_strncmp(tmp, "white", ft_strlen(tmp)) == 0)
	{
		game->xpm->colors[i_color][1] = 255;
		game->xpm->colors[i_color][2] = 255;
		game->xpm->colors[i_color][3] = 255;
	}
	else if (ft_strncmp(tmp, "black", ft_strlen(tmp)) == 0)
	{
		game->xpm->colors[i_color][1] = 0;
		game->xpm->colors[i_color][2] = 0;
		game->xpm->colors[i_color][3] = 0;
	}
	else if (set_color(game, i_color, tmp) == FAIL)
		return (free(tmp), FAIL);
	return (free(tmp), SUCCESS);
}

int	set_color(t_game *game, int i_color, char *tmp)
{
	if (ft_strncmp(tmp, "red", ft_strlen(tmp)) == 0)
	{
		game->xpm->colors[i_color][1] = 255;
		game->xpm->colors[i_color][2] = 0;
		game->xpm->colors[i_color][3] = 0;
	}
	else if (ft_strncmp(tmp, "green", ft_strlen(tmp)) == 0)
	{
		game->xpm->colors[i_color][1] = 0;
		game->xpm->colors[i_color][2] = 255;
		game->xpm->colors[i_color][3] = 0;
	}
	else if (ft_strncmp(tmp, "blue", ft_strlen(tmp)) == 0)
	{
		game->xpm->colors[i_color][1] = 0;
		game->xpm->colors[i_color][2] = 0;
		game->xpm->colors[i_color][3] = 255;
	}
	else
		return (printf("color not handle\n"), FAIL);
	return (SUCCESS);
}
