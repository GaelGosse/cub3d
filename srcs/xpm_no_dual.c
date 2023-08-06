/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_no_dual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:18:15 by gael              #+#    #+#             */
/*   Updated: 2023/08/06 00:23:14 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_no_dual(t_game *game)
{
	int	i_color;
	int	i_tab;
	int	i_chr;

	i_chr = 2;
	i_tab = 0;
	i_color = -1;
	if (xpm_no_init_color(game) == FAIL)
		return (FAIL);
	while (++i_color < game->xpm->no_metadata[2])
	{
		i_chr = 2;
		if (xpm_no_check_dual_colors(game, &i_chr, ++i_tab, i_color) == FAIL)
			return (FAIL);
		if (xpm_no_hex_to_dec_dual(game, i_color, i_tab, i_chr) == FAIL)
			return (FAIL);
	}
	(void)game;
	return (SUCCESS);
}

int	xpm_no_check_dual_colors(t_game *g, int *i_chr, int i_tab_file, int i_color)
{
	if (is_space(g->xpm->no_tab_file[i_tab_file][(*i_chr)]) == FAIL)
		return (printf("1 dual no something wrong xpm files\n"), FAIL);
	while (is_space(g->xpm->no_tab_file[i_tab_file][(*i_chr)]) == SUCCESS)
		(*i_chr)++;
	if (g->xpm->no_tab_file[i_tab_file][(*i_chr)] != 'c')
		return (printf(" 2 dual no something wrong xpm files\n"), FAIL);
	(*i_chr)++;
	if (is_space(g->xpm->no_tab_file[i_tab_file][(*i_chr)]) == FAIL)
		return (printf(" 3 dual no something wrong xpm files\n"), FAIL);
	while (is_space(g->xpm->no_tab_file[i_tab_file][(*i_chr)]) == SUCCESS)
		(*i_chr)++;
	g->xpm->no_colors[i_color] = malloc(sizeof(int) * (5));
	if (!g->xpm->no_colors[i_color])
		return (FAIL);
	g->xpm->no_colors[i_color][0] = g->xpm->no_tab_file[i_tab_file][0];
	g->xpm->no_colors[i_color][1] = g->xpm->no_tab_file[i_tab_file][1];
	return (SUCCESS);
}

int	xpm_no_hex_to_dec_dual(t_game *g, int i_color, int i_tab_file, int i_chr)
{
	if (g->xpm->no_tab_file[i_tab_file][i_chr] == '#')
	{
		g->xpm->no_colors[i_color][2] = \
		hex_to_dec(ft_strdup_len(g->xpm->no_tab_file[i_tab_file], \
		i_chr + 1, i_chr + 3));
		g->xpm->no_colors[i_color][3] = \
		hex_to_dec(ft_strdup_len(g->xpm->no_tab_file[i_tab_file], \
		i_chr + 3, i_chr + 5));
		g->xpm->no_colors[i_color][4] = \
		hex_to_dec(ft_strdup_len(g->xpm->no_tab_file[i_tab_file], \
		i_chr + 5, i_chr + 7));
	}
	else if (xpm_no_dual_letter(g, i_color, i_tab_file, i_chr) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	xpm_no_dual_letter(t_game *game, int i_color, int i_tab_file, int i_chr)
{
	char	*tmp;

	tmp = ft_strdup_len(game->xpm->no_tab_file[i_tab_file], i_chr, \
	ft_strlen(game->xpm->no_tab_file[i_tab_file]));
	if (!tmp)
		return (FAIL);
	tmp = ft_str_to_lowf(tmp);
	if (!tmp)
		return (FAIL);
	if (ft_strncmp(tmp, "white", ft_strlen(tmp)) == 0)
	{
		game->xpm->no_colors[i_color][2] = 255;
		game->xpm->no_colors[i_color][3] = 255;
		game->xpm->no_colors[i_color][4] = 255;
	}
	else if ((ft_strncmp(tmp, "black", ft_strlen(tmp)) == 0) \
	|| (ft_strncmp(tmp, "none", ft_strlen(tmp)) == 0))
	{
		game->xpm->no_colors[i_color][2] = 0;
		game->xpm->no_colors[i_color][3] = 0;
		game->xpm->no_colors[i_color][4] = 0;
	}
	else if (xpm_no_set_dual_color(game, i_color, tmp) == FAIL)
		return (free(tmp), FAIL);
	return (free(tmp), SUCCESS);
}

int	xpm_no_set_dual_color(t_game *game, int i_color, char *tmp)
{
	if (ft_strncmp(tmp, "red", ft_strlen(tmp)) == 0)
	{
		game->xpm->no_colors[i_color][2] = 255;
		game->xpm->no_colors[i_color][3] = 0;
		game->xpm->no_colors[i_color][4] = 0;
	}
	else if (ft_strncmp(tmp, "green", ft_strlen(tmp)) == 0)
	{
		game->xpm->no_colors[i_color][2] = 0;
		game->xpm->no_colors[i_color][3] = 255;
		game->xpm->no_colors[i_color][4] = 0;
	}
	else if (ft_strncmp(tmp, "blue", ft_strlen(tmp)) == 0)
	{
		game->xpm->no_colors[i_color][2] = 0;
		game->xpm->no_colors[i_color][3] = 0;
		game->xpm->no_colors[i_color][4] = 255;
	}
	else
		return (printf("no color dual not handle\n"), FAIL);
	return (SUCCESS);
}
