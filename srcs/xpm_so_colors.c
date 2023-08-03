/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_so_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:30:48 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 12:37:54 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_so_letter_color(t_game *game, int i_color, int i_tab_file)
{
	char	*tmp;

	tmp = ft_strdup_len(game->xpm->so_tab_file[i_tab_file], 4, \
	ft_strlen(game->xpm->so_tab_file[i_tab_file]));
	if (!tmp)
		return (FAIL);
	if (ft_strncmp(tmp, "white", ft_strlen(tmp)) == 0)
	{
		game->xpm->so_colors[i_color][1] = 255;
		game->xpm->so_colors[i_color][2] = 255;
		game->xpm->so_colors[i_color][3] = 255;
	}
	else if (ft_strncmp(tmp, "black", ft_strlen(tmp)) == 0)
	{
		game->xpm->so_colors[i_color][1] = 0;
		game->xpm->so_colors[i_color][2] = 0;
		game->xpm->so_colors[i_color][3] = 0;
	}
	else if (xpm_so_set_color(game, i_color, tmp) == FAIL)
		return (free(tmp), FAIL);
	return (free(tmp), SUCCESS);
}

int	xpm_so_set_color(t_game *game, int i_color, char *tmp)
{
	if (ft_strncmp(tmp, "red", ft_strlen(tmp)) == 0)
	{
		game->xpm->so_colors[i_color][1] = 255;
		game->xpm->so_colors[i_color][2] = 0;
		game->xpm->so_colors[i_color][3] = 0;
	}
	else if (ft_strncmp(tmp, "green", ft_strlen(tmp)) == 0)
	{
		game->xpm->so_colors[i_color][1] = 0;
		game->xpm->so_colors[i_color][2] = 255;
		game->xpm->so_colors[i_color][3] = 0;
	}
	else if (ft_strncmp(tmp, "blue", ft_strlen(tmp)) == 0)
	{
		game->xpm->so_colors[i_color][1] = 0;
		game->xpm->so_colors[i_color][2] = 0;
		game->xpm->so_colors[i_color][3] = 255;
	}
	else
		return (printf("color not handle\n"), FAIL);
	return (SUCCESS);
}

int	xpm_so_hex_to_dec(t_game *g, int i_color, int i_tab_file, int i_chr)
{
	if (g->xpm->so_tab_file[i_tab_file][i_chr] == '#')
	{
		g->xpm->so_colors[i_color][1] = \
		hex_to_dec(ft_strdup_len(g->xpm->so_tab_file[i_tab_file], \
		i_chr + 1, i_chr + 3));
		g->xpm->so_colors[i_color][2] = \
		hex_to_dec(ft_strdup_len(g->xpm->so_tab_file[i_tab_file], \
		i_chr + 3, i_chr + 5));
		g->xpm->so_colors[i_color][3] = \
		hex_to_dec(ft_strdup_len(g->xpm->so_tab_file[i_tab_file], \
		i_chr + 5, i_chr + 7));
	}
	else if (xpm_so_letter_color(g, i_color, i_tab_file) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	xpm_so_set_len_n_color(t_game *g, char **line)
{
	int	i_color;
	int	i_tab;
	int	i_chr;

	i_chr = 1;
	i_tab = 0;
	i_color = -1;
	xpm_so_fill_metadata(g, line);
	if (ft_atoi(line[2]) <= 92)
	{
		if (xpm_so_init_color(g, line) == FAIL)
			return (FAIL);
		while (++i_color < ft_atoi(line[2]))
		{
			i_chr = 1;
			if (xpm_so_check_line_color(g, &i_chr, ++i_tab, i_color) == FAIL)
				return (FAIL);
			if (xpm_so_hex_to_dec(g, i_color, i_tab, i_chr) == FAIL)
				return (FAIL);
		}
	}
	else
		return (printf("Must have under 92 colors in xpm\n"), FAIL);
	return (SUCCESS);
}

int	xpm_so_check_line_color(t_game *g, int *i_chr, int i_tab_file, int i_color)
{
	if (is_space(g->xpm->so_tab_file[i_tab_file][(*i_chr)]) == FAIL)
		return (printf("something wrong xpm files\n"), FAIL);
	while (is_space(g->xpm->so_tab_file[i_tab_file][(*i_chr)]) == SUCCESS)
		(*i_chr)++;
	if (g->xpm->so_tab_file[i_tab_file][(*i_chr)] != 'c')
		return (printf("something wrong xpm files\n"), FAIL);
	(*i_chr)++;
	if (is_space(g->xpm->so_tab_file[i_tab_file][(*i_chr)]) == FAIL)
		return (printf("something wrong xpm files\n"), FAIL);
	while (is_space(g->xpm->so_tab_file[i_tab_file][(*i_chr)]) == SUCCESS)
		(*i_chr)++;
	g->xpm->so_colors[i_color] = malloc(sizeof(int) * (4));
	if (!g->xpm->so_colors[i_color])
		return (FAIL);
	g->xpm->so_colors[i_color][0] = g->xpm->so_tab_file[i_tab_file][0];
	return (SUCCESS);
}
