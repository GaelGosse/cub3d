/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_we_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:30:48 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 13:29:56 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_we_letter_color(t_game *game, int i_color, int i_tab_file)
{
	char	*tmp;

	tmp = ft_strdup_len(game->xpm->we_tab_file[i_tab_file], 4, \
	ft_strlen(game->xpm->we_tab_file[i_tab_file]));
	if (!tmp)
		return (FAIL);
	if (ft_strncmp(tmp, "white", ft_strlen(tmp)) == 0)
	{
		game->xpm->we_colors[i_color][1] = 255;
		game->xpm->we_colors[i_color][2] = 255;
		game->xpm->we_colors[i_color][3] = 255;
	}
	else if (ft_strncmp(tmp, "black", ft_strlen(tmp)) == 0)
	{
		game->xpm->we_colors[i_color][1] = 0;
		game->xpm->we_colors[i_color][2] = 0;
		game->xpm->we_colors[i_color][3] = 0;
	}
	else if (xpm_we_set_color(game, i_color, tmp) == FAIL)
		return (free(tmp), FAIL);
	return (free(tmp), SUCCESS);
}

int	xpm_we_set_color(t_game *game, int i_color, char *tmp)
{
	if (ft_strncmp(tmp, "red", ft_strlen(tmp)) == 0)
	{
		game->xpm->we_colors[i_color][1] = 255;
		game->xpm->we_colors[i_color][2] = 0;
		game->xpm->we_colors[i_color][3] = 0;
	}
	else if (ft_strncmp(tmp, "green", ft_strlen(tmp)) == 0)
	{
		game->xpm->we_colors[i_color][1] = 0;
		game->xpm->we_colors[i_color][2] = 255;
		game->xpm->we_colors[i_color][3] = 0;
	}
	else if (ft_strncmp(tmp, "blue", ft_strlen(tmp)) == 0)
	{
		game->xpm->we_colors[i_color][1] = 0;
		game->xpm->we_colors[i_color][2] = 0;
		game->xpm->we_colors[i_color][3] = 255;
	}
	else
		return (printf("color not handle\n"), FAIL);
	return (SUCCESS);
}

void	xpm_we_hex_to_dec(t_game *g, int i_color, int i_tab_file)
{
	g->xpm->we_colors[i_color][1] = \
	hex_to_dec(ft_strdup_len(g->xpm->we_tab_file[i_tab_file], 5, 7));
	g->xpm->we_colors[i_color][2] = \
	hex_to_dec(ft_strdup_len(g->xpm->we_tab_file[i_tab_file], 7, 9));
	g->xpm->we_colors[i_color][3] = \
	hex_to_dec(ft_strdup_len(g->xpm->we_tab_file[i_tab_file], 9, 11));
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
	if (xpm_we_init_color(g, line) == FAIL)
		return (FAIL);
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
