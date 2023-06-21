/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_and_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:19:47 by mael              #+#    #+#             */
/*   Updated: 2023/06/19 12:20:54 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	img_pix_put_2(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = game->img->addr + (y * game->img->line_len + x * 
		(game->img->bpp / 8));
	*(int *)pixel = color;
}

void	img_pix_put(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = game->img->addr + (y * game->img->line_len + x * 
		(game->img->bpp / 8));
	*(int *)pixel = color;
}

int	get_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}