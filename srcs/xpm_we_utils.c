/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_we_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:13:18 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 11:17:46 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_we_init_color(t_game *game, char **line)
{
	int	i_color;

	i_color = 0;
	game->xpm->we_colors = malloc(sizeof(int *) * (ft_atoi(line[2]) + 1));
	if (!game->xpm->we_colors)
		return (printf("xpm colors failed\n"), FAIL);
	while (i_color < ft_atoi(line[2]))
	{
		game->xpm->we_colors[i_color] = NULL;
		i_color++;
	}
	return (SUCCESS);
}