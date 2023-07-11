/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:34:58 by mael              #+#    #+#             */
/*   Updated: 2023/07/11 16:26:44 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	absolute_value(int nb)
{
	if (nb == 0)
		return (nb);
	else if (nb < 0)
		nb = nb * (-1);
	return (nb);
}

int	init_line(t_game *game)
{
	game->line = malloc(sizeof(t_line));
	if (!game->line)
		return (printf("Malloc failed\n"), FAIL);
	game->line->dx = 0;
	game->line->dy = 0;
	game->line->steps = 0;
	game->line->xite = 0;
	game->line->yite = 0;
	game->line->corr_x = 0;
	game->line->corr_y = 0;
	game->line->x_src = 0;
	game->line->y_src = 0;
	game->line->x_dest = 0;
	game->line->y_dest = 0;
	game->line->x_dest_prev = 0;
	game->line->y_dest_prev = 0;
	return (SUCCESS);
}
int	draw_pixel(t_game *game, int toggle, int x_check, int y_check, int color)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i <= game->line->steps)
	{
		if (toggle == FAIL && i == 0 && round(game->line->corr_x) > 0 && \
		round(game->line->corr_y) > 0)
		{
			//len++;
			img_pix_put(game, round(game->line->corr_x), \
			round(game->line->corr_y), color);
		}
		else if (toggle == FAIL && i > 0 && round(game->line->corr_x) > 0 && \
		round(game->line->corr_y) > 0 && \
		game->map->map_org[y_check][x_check] != '1')
		{
			//len++;
			img_pix_put(game, round(game->line->corr_x), \
			round(game->line->corr_y), color);
		}
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		y_check = (int)(game->line->corr_y / game->img_size);
		x_check = (int)(game->line->corr_x / game->img_size);
		if (y_check >= 0 && x_check >= 0 && x_check < game->map->width && \
		y_check < game->map->height && \
		game->map->map_org[y_check][x_check] == '1')
			toggle = SUCCESS;
		if ((game->fov->angle >= 180 && game->fov->angle < 270) && toggle == FAIL \
		&& game->map->map_org[y_check - 1][x_check] == '1'
		&& game->map->map_org[y_check][x_check + 1] == '1' \
		&& (game->map->map_org[y_check - 1][x_check + 1] == '0'))
			toggle = SUCCESS;
		if ((game->fov->angle >= 270 && game->fov->angle < 360) && toggle == FAIL \
		&& game->map->map_org[y_check + 1][x_check] == '1' \
		&& game->map->map_org[y_check][x_check + 1] == '1' \
		&& (game->map->map_org[y_check + 1][x_check + 1] == '0'))
			toggle = SUCCESS;
		if ((game->fov->angle >= 0 && game->fov->angle < 90) && toggle == FAIL \
		&& game->map->map_org[y_check + 1][x_check] == '1' \
		&& game->map->map_org[y_check][x_check - 1] == '1' \
		&& (game->map->map_org[y_check + 1][x_check - 1] == '0'))
			toggle = SUCCESS;
		if ((game->fov->angle >= 90 && game->fov->angle < 180) && toggle == FAIL \
		&& game->map->map_org[y_check - 1][x_check] == '1' \
		&& game->map->map_org[y_check][x_check - 1] == '1' \
		&& (game->map->map_org[y_check - 1][x_check - 1] == '0'))
			toggle = SUCCESS;
		if (toggle == SUCCESS)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
	(void)len;
	//return (len);
}


int	draw_line_vision(t_game *game, int color)
{
	double len;
	int	toggle;
	int y_check;
	int	x_check;

	toggle = FAIL;
	x_check = FAIL;
	y_check = FAIL;
	len = 0;
	game->line->dx = game->line->x_dest - game->line->x_src;
	game->line->dy = game->line->y_dest - game->line->y_src;
	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);
	game->line->xite = game->line->dx / (float)game->line->steps;
	game->line->yite = game->line->dy / (float)game->line->steps;
	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	draw_pixel(game, toggle, x_check, y_check, color);
	len = sqrt(pow(game->line->corr_x - game->line->x_src, 2) + pow(game->line->corr_y - game->line->y_src, 2));
	return (len);
}

