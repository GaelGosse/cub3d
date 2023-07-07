/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:35:01 by gael              #+#    #+#             */
/*   Updated: 2023/07/07 15:02:36 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	tab_len(char **arr)
{
	int	i_tablen;

	i_tablen = 0;
	while (arr[i_tablen])
		i_tablen++;
	return (i_tablen);
}

int	is_empty_line(char *line)
{
	int	i_empty;

	i_empty = 0;
	while (line[i_empty])
	{
		if (line[i_empty] != 32 && line[i_empty] != 9 && line[i_empty] != 10)
			return (FAIL);
		i_empty++;
	}
	return (SUCCESS);
}

void	set_width(t_game *game)
{
	int	i_big;
	int	max;
	int	len;

	len = 0;
	i_big = 0;
	max = 0;
	while (game->map->map_org[i_big])
	{
		len = ft_strlen(game->map->map_org[i_big]);
		if (len > max)
			max = len;
		i_big++;
	}
	game->map->width = max;
}

int	check_nbr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}
