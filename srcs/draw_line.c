/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:34:58 by mael              #+#    #+#             */
/*   Updated: 2023/07/28 20:48:52 by gael             ###   ########.fr       */
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

double	abs_flt(double nb)
{
	if (nb == 0)
		return (nb);
	else if (nb < 0)
		nb = nb * (-1);
	return (nb);
}

double	abs_dble(double nb)
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
		if (toggle == FAIL && i == 0 && roundf(game->line->corr_x) > 0 && \
		roundf(game->line->corr_y) > 0)
		{
			// if (game->line->corr_x > 383)
			// {
			// 	printf("game->line->corr_x: %f\n", game->line->corr_x);
			// 	// game->line->corr_x = 383;
			// }
			//len++;
			img_pix_put(game, roundf(game->line->corr_x), roundf(game->line->corr_y), color);
		}
		else if (toggle == FAIL && i > 0 && roundf(game->line->corr_x) > 0 && \
		roundf(game->line->corr_y) > 0 && \
		game->map->map_org[y_check][x_check] != '1')
		{
			// if (game->line->corr_x > 383)
			// {
			// 	printf("game->line->corr_x: %f\n", game->line->corr_x);
			// 	// game->line->corr_x = 383;
			// }
			//len++;
			img_pix_put(game, roundf(game->line->corr_x), roundf(game->line->corr_y), color);
		}
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		y_check = (int)(game->line->corr_y / game->img_size);
		x_check = (int)(game->line->corr_x / game->img_size);

		// printf("map_org[y_check + 1][x_check]: %c\n", game->map->map_org[y_check + 1][x_check]);
		// printf("map_org[y_check][x_check + 1]: %c\n", game->map->map_org[y_check][x_check + 1]);
		// printf("map_org[y_check + 1][x_check + 1]: %c\n", game->map->map_org[y_check + 1][x_check + 1]);
		// printf("\n");
		if (toggle == FAIL && y_check >= 0 && x_check >= 0 && x_check < game->map->width && \
		y_check < game->map->height && \
		game->map->map_org[y_check][x_check] == '1')
		{
			// if (y_check < 4)
			// {
			// 	printf(RED"game->line->corr_y / game->img_size: %f\n"RST, game->line->corr_y / game->img_size);
			// 	printf(BLUE"game->line->corr_x : %f\n"RST, game->line->corr_x);
			// 	printf(BACK_PURPLE"y_check: %i"RST"\n", y_check);
			// 	printf(BACK_PURPLE"x_check: %i"RST"\n", x_check);
			// 	printf("\n");
			// }
			game->line->corr_x = roundf(game->line->corr_x);
			game->line->corr_y = roundf(game->line->corr_y);
			toggle = SUCCESS;
		}
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
	game->line->xite = game->line->dx / (double)game->line->steps;
	game->line->yite = game->line->dy / (double)game->line->steps;
	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	draw_pixel(game, toggle, x_check, y_check, color);
	len = sqrt(pow(game->line->corr_x - (double)game->line->x_src, 2) + \
		pow(game->line->corr_y - (double)game->line->y_src, 2));
	// printf("\n");
	// printf(PURPLE"corr x: %f\ty:%f"RESET"\n", game->line->corr_x, game->line->corr_y);
	// printf(PURPLE"src x: %d\ty:%d"RESET"\n", game->line->x_src, game->line->y_src);
	// printf(BACK_YELLOW"len: %f"RESET"\n", len);
	len = roundf(len);
	// printf(BACK_YELLOW"len: %f"RESET"\n", len);
	return (len);
}

