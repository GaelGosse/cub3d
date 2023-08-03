/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_we_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:13:18 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 12:05:03 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_we_init_color(t_game *g)
{
	int	i_color;

	i_color = 0;
	g->xpm->we_colors = malloc(sizeof(int *) * (g->xpm->we_metadata[2] + 1));
	if (!g->xpm->we_colors)
		return (printf("xpm colors failed\n"), FAIL);
	while (i_color < g->xpm->we_metadata[2])
	{
		g->xpm->we_colors[i_color] = NULL;
		i_color++;
	}
	return (SUCCESS);
}

char	*xpm_we_keep_metadata(char **tmp, int i_tmp)
{
	int	end;
	int	len_line;

	len_line = ft_strlen(tmp[i_tmp]) - 1;
	end = FAIL;

	if (tmp[i_tmp][len_line] == ',' && tmp[i_tmp][len_line - 1] == '"')
		end = len_line - 1;
	else if (tmp[i_tmp][len_line] == ';' && tmp[i_tmp][len_line - 1] == '}')
		end = len_line - 2;
	else
		end = len_line;
	return (ft_strdup_len(tmp[i_tmp], 1, end));
}

void	xpm_we_fill_metadata(t_game *game, char **line)
{
	game->xpm->we_metadata = malloc(sizeof(int) * 4);
	game->xpm->we_metadata[0] = ft_atoi(line[0]);
	game->xpm->we_metadata[1] = ft_atoi(line[1]);
	game->xpm->we_metadata[2] = ft_atoi(line[2]);
	game->xpm->we_metadata[3] = ft_atoi(line[3]);
}

int	xpm_we_check_wh(t_game *game)
{
	int	i_big;
	int	i_lil;

	i_lil = 0;
	i_big = game->xpm->we_metadata[2] + 1;
	while (game->xpm->we_tab_file[i_big])
	{
		i_lil = 0;
		while (game->xpm->we_tab_file[i_big][i_lil])
			i_lil++;
		if (i_lil != game->xpm->we_metadata[0])
			return (printf("wrong xpm file l format\n"),
			printf(BACK_GREEN"%s"RESET"\n", game->xpm->we_tab_file[i_big])
			, FAIL);
		i_big++;
	}
	i_big--;
	if ((i_big - game->xpm->we_metadata[2]) != game->xpm->we_metadata[1])
		return (printf("wrong xpm file b format\n"), FAIL);
	return (SUCCESS);
}
