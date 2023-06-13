/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:10:43 by mael              #+#    #+#             */
/*   Updated: 2023/06/13 17:13:10 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	start_3d(t_game *game)
{
	if (init_tab_img(game) == FAIL)
		return (FAIL);
	if (create_img(game) == FAIL)
		return (FAIL);
}

int	init_tab_img(t_game *game)
{
	int i;
	int j;

	game->tab_img = malloc(sizeof(t_img **) * (game->map->height + 1));
	if (!game->tab_img)
		return (FAIL);
	i = 0;
	while (i < game->map->height)
	{
		game->tab_img[i] = malloc(sizeof(t_img *) * (game->map->width + 1));
		if (!game->tab_img[i])
			return (FAIL);
		j = 0;
		while (j < game->map->width)
		{
			game->tab_img[i][j] = malloc(sizeof(t_img));
			if (!game->map->width)
				return (FAIL);
			game->tab_img[i][j]->mlx_img = NULL;
			game->tab_img[i][j]->addr = NULL;
			game->tab_img[i][j]->bpp = 0;
			game->tab_img[i][j]->line_len = 0;
			game->tab_img[i][j]->endian = 0;
			j++;
		}
		game->tab[i][game->map->width] = NULL;
		i++;
	}
	game->tab_img[game->map->height] = NULL;
	return (SUCCESS);
}

int	create_img(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			game->tab_img[i][j]->mlx_img = mlx_new_image(game->mlibx, game->img_size, game->img_size);
			if (!game->tab_img[i][j]->mlx_img)
				return (printf("fail image\n"), FAIL);
			j++;
		}
		i++;
	}
}
