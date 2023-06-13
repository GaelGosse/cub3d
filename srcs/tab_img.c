/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:10:43 by mael              #+#    #+#             */
/*   Updated: 2023/06/13 17:48:22 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	start_3d(t_game *game)
{
	if (init_tab_img(game) == FAIL)
		return (FAIL);
	if (create_img(game) == FAIL)
		return (FAIL);
	color_image(game);
	tab_img_to_window(game);
	return (SUCCESS);
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
		game->tab_img[i][game->map->width] = NULL;
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
			game->tab_img[i][j]->addr = mlx_get_data_addr(game->tab_img[i][j]->mlx_img, 
			&game->tab_img[i][j]->bpp, &game->tab_img[i][j]->line_len, &game->tab_img[i][j]->endian);
			if (!game->tab_img[i][j]->addr)
				return (printf("fail during getting adress\n"), FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

void	img_pix_put(t_game *game, int x, int y, int color, int i, int j)
{
	char	*pixel;

	pixel = game->tab_img[i][j]->addr + (y * game->tab_img[i][j]->line_len + x * 
		(game->tab_img[i][j]->bpp / 8));
	*(int *)pixel = color;
}

int	get_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	fill_square(t_game *game, int color, int i, int j)
{
	int x;
	int y;

	y = 0;
	while (y < game->img_size)
	{
		x = 0;
		while (x < game->img_size)
		{
			img_pix_put(game, x, y, color, i, j);
			x++;
		}
		y++;
	}
}

void	color_image(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while (game->tab_img[i])
	{
		j = 0;
		while (game->tab_img[i][j])
		{
			if (game->map->map_org[i][j] == '1')
				fill_square(game, get_color(255, 0, 230), i, j);
			else
				fill_square(game, get_color(10, 30, 240), i, j);
			j++;
		}
		i++;
	}
}
int	tab_img_to_window(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->tab_img[y])
	{
		x = 0;
		while (game->tab_img[y][x])
		{
			mlx_put_image_to_window((game->mlibx), (game->window), 
				game->tab_img[y][x]->mlx_img, x * game->img_size, y * game->img_size);
			x++;
		}
		y++;
	}
	return (printf("image to window succeded \n"), SUCCESS);
}