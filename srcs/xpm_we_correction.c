/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_we_correction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:03:27 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 13:28:53 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_we_correct(t_game *g)
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
	return (xpm_we_wo_comm(g, n_comm));
}

int	xpm_we_wo_comm(t_game *g, int n_comm)
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
	return (xpm_we_copy_tab(g, tab_tmp));
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
