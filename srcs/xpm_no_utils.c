/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_no_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:13:18 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 13:29:31 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_no_init_color(t_game *game, char **line)
{
	int	i_color;

	i_color = 0;
	game->xpm->no_colors = malloc(sizeof(int *) * (ft_atoi(line[2]) + 1));
	if (!game->xpm->no_colors)
		return (printf("xpm colors failed\n"), FAIL);
	while (i_color < ft_atoi(line[2]))
	{
		game->xpm->no_colors[i_color] = NULL;
		i_color++;
	}
	return (SUCCESS);
}

char	*xpm_no_keep_metadata(char **tmp, int i_tmp)
{
	int	end;
	int	len_line;

	len_line = ft_strlen(tmp[i_tmp]) - 1;
	end = FAIL;
	if (tmp[i_tmp][len_line] == ',' && tmp[i_tmp][len_line - 1] == '"')
		end = len_line - 1;
	else
		end = len_line;
	return (ft_strdup_len(tmp[i_tmp], 1, end));
}
