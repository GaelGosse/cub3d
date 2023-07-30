/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_so_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:30:48 by gael              #+#    #+#             */
/*   Updated: 2023/07/30 21:52:53 by gael             ###   ########.fr       */
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

char	*xpm_so_keep_metadata(char **tmp, int i_tmp)
{
	int	end;
	int	len_line;

	len_line = ft_strlen(tmp[i_tmp]) - 1;
	end = FAIL;
	if (tmp[i_tmp][len_line] == ',' && tmp[i_tmp][len_line - 1] == '"')
		end = len_line - 1;
	else if (tmp[i_tmp][len_line] == '"')
		end = len_line - 2;
	return (ft_strdup_len(tmp[i_tmp], 1, end));
}

void	xpm_so_hex_to_dec(t_game *g, int i_color, int i_tab_file)
{
	g->xpm->so_colors[i_color][1] = \
	hex_to_dec(ft_strdup_len(g->xpm->so_tab_file[i_tab_file], 5, 7));
	g->xpm->so_colors[i_color][2] = \
	hex_to_dec(ft_strdup_len(g->xpm->so_tab_file[i_tab_file], 7, 9));
	g->xpm->so_colors[i_color][3] = \
	hex_to_dec(ft_strdup_len(g->xpm->so_tab_file[i_tab_file], 9, 11));
}
