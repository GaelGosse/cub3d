/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:34:58 by mael              #+#    #+#             */
/*   Updated: 2023/08/02 21:28:02 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	init_line(t_game *game)
{
	game->line = malloc(sizeof(t_line));
	if (!game->line)
		return (printf("Malloc line failed\n"), FAIL);
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
	game->line->check_x = 0;
	game->line->check_y = 0;
	game->line->new_x = 0;
	game->line->new_y = 0;
	return (SUCCESS);
}
int	draw_pixel(t_game *game, int toggle, int color)
{
	int i;
	int	x_check;
	int	y_check;
	
	i = 0;
	x_check = FAIL;
	y_check = FAIL;
	while (i <= game->line->steps)
	{
		color_line(game, color, toggle, x_check, y_check, i);
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		y_check = (int)(game->line->corr_y / game->img_size);
		x_check = (int)(game->line->corr_x / game->img_size);
		if (check_lines_hit_wall(game, x_check, y_check, toggle) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

void	color_line(t_game *game, int color, int toggle, int x_check, int y_check, int i)
{
	if (toggle == FAIL && i == 0 && roundf(game->line->corr_x) > 0 && \
	roundf(game->line->corr_y) > 0)
		img_pix_put(game, roundf(game->line->corr_x), \
		roundf(game->line->corr_y), color);
	else if (toggle == FAIL && i > 0 && roundf(game->line->corr_x) > 0 && \
	roundf(game->line->corr_y) > 0 && \
	game->map->map_org[y_check][x_check] != '1')
		img_pix_put(game, roundf(game->line->corr_x), \
		roundf(game->line->corr_y), color);
}

int	check_lines_hit_wall(t_game *game, int x_check, int y_check, int toggle)
{
	if (toggle == FAIL && y_check >= 0 && x_check >= 0 \
	&& x_check < game->map->width && y_check < game->map->height && \
	game->map->map_org[y_check][x_check] == '1')
	{
		game->line->corr_x = roundf(game->line->corr_x);
		game->line->corr_y = roundf(game->line->corr_y);
		toggle = SUCCESS;
	}
	if (toggle == SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int	draw_line_vision(t_game *game, int color)
{
	double	len;
	int		toggle;

	toggle = FAIL;
	len = 0;
	game->line->dx = game->line->x_dest - game->line->x_src;
	game->line->dy = game->line->y_dest - game->line->y_src;
	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);
	game->line->xite = game->line->dx / (double)game->line->steps;
	game->line->yite = game->line->dy / (double)game->line->steps;
	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	draw_pixel(game, toggle, color);
	len = sqrt(pow(game->line->corr_x - (double)game->line->x_src, 2) + \
		pow(game->line->corr_y - (double)game->line->y_src, 2));
	len = roundf(len);
	return (len);
}

