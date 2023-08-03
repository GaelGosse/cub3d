/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_we_dual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:08:55 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 11:08:04 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_we_dual_letters(t_game *g, int i_chr, int i_tab_file, int i_color)
{
	if (xpm_we_init_color(g) == FAIL)
		return (FAIL);
	while (++i_color < g->xpm->we_metadata[2])
	{
		i_chr = 1;
		if (xpm_we_check_dual_color(g, &i_chr, ++i_tab_file, i_color) == FAIL)
			return (FAIL);
		if (xpm_we_hex_to_dec(g, i_color, i_tab_file, i_chr) == FAIL)
			return (FAIL);
		printf(PURPLE"g->xpm->we_colors[i_color][0]: %i"RESET"\n", g->xpm->we_colors[i_color][0]);
		printf(PURPLE"g->xpm->we_colors[i_color][1]: %i"RESET"\n", g->xpm->we_colors[i_color][1]);
		printf(PURPLE"g->xpm->we_colors[i_color][2]: %i"RESET"\n", g->xpm->we_colors[i_color][2]);
		printf(PURPLE"g->xpm->we_colors[i_color][3]: %i"RESET"\n", g->xpm->we_colors[i_color][3]);
		printf(PURPLE"g->xpm->we_colors[i_color][4]: %i"RESET"\n", g->xpm->we_colors[i_color][4]);
		printf("\n");
	}
	return (SUCCESS);
}

int	xpm_we_check_dual_color(t_game *g, int *i_chr, int i_tab_file, int i_color)
{
	if (is_space(g->xpm->we_tab_file[i_tab_file][(*i_chr)]) == FAIL)
		return (printf("something wrong xpm files\n"), FAIL);
	while (is_space(g->xpm->we_tab_file[i_tab_file][(*i_chr)]) == SUCCESS)
		(*i_chr)++;
	if (g->xpm->we_tab_file[i_tab_file][(*i_chr)] != 'c')
		return (printf("something wrong xpm files\n"), FAIL);
	(*i_chr)++;
	if (is_space(g->xpm->we_tab_file[i_tab_file][(*i_chr)]) == FAIL)
		return (printf("something wrong xpm files\n"), FAIL);
	while (is_space(g->xpm->we_tab_file[i_tab_file][(*i_chr)]) == SUCCESS)
		(*i_chr)++;
	g->xpm->we_colors[i_color] = malloc(sizeof(int) * (5));
	if (!g->xpm->we_colors[i_color])
		return (FAIL);
	g->xpm->we_colors[i_color][0] = g->xpm->we_tab_file[i_tab_file][0];
	g->xpm->we_colors[i_color][1] = g->xpm->we_tab_file[i_tab_file][1];
	return (SUCCESS);
}
