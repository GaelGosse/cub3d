/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:47:24 by mael              #+#    #+#             */
/*   Updated: 2023/07/05 20:12:27 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	init_fov(t_game *game)
{
	int i;

	i = 0;
	game->fov = malloc(sizeof(t_fov));
	if (!game->fov)
		return (printf("Init fov failed \n"), FAIL);
	game->fov->lines_vision = malloc(sizeof(int) * 31);
	if (!game->fov->lines_vision)
		return (printf("lines_visions failed\n"), FAIL);
	while (i < 31)
	{
		game->fov->lines_vision[i] = 0;
		i++;
	}
	game->fov->len_first_line = 0;
	game->fov->toggle = game->perso;
	return (SUCCESS);
}

void	init_position(t_game *game)
{
	if (game->perso == 'S')
	{
		game->line->x_dest = game->map->pos_x;
		game->line->y_dest = game->map->height * game->img_size;
		game->fov->angle = 180;
	}
	else if (game->perso == 'W')
	{
		game->line->x_dest = 0;
		game->line->y_dest = game->map->pos_y;
		game->fov->angle = 270;
	}
	if (game->perso == 'N')
	{
		game->line->x_dest = game->map->pos_x;
		game->line->y_dest = 0;
		game->fov->angle = 0;
	}
	else if (game->perso == 'E')
	{
		game->line->x_dest = game->map->width * game->img_size;
		game->line->y_dest = game->map->pos_y;
		game->fov->angle = 90;
	}
}

void	calcul_len_first_line(t_game *game)
{
	if (game->perso == 'N' || game->perso == 'S')
		game->fov->len_first_line = absolute_value((int)(game->line->corr_y - \
			game->map->pos_y));
	else if (game->perso == 'E' || game->perso == 'W')
		game->fov->len_first_line = absolute_value((int)(game->line->corr_x - \
			game->map->pos_x));
}

// int	fill_tab_lines_vision(t_game *game)
// {

// }

int	calcul_opposite_side(t_game *game, int i, double angle)
{
	int	op_side;
	// double angle;

	// angle =
	//	printf("res line len = %d\n", game->fov->len_first_line);
	// if (i == 6 || i == 0)
	// 	op_side = atan(angle) * game->fov->len_first_line;
	// else
	// if (angle > 180)
	// 	angle = absolute_value(360 - angle);

	// op_side = atan(deg_to_radian(angle)) * game->fov->len_first_line;

	if (game->fov->toggle == 'N' && game->line->y_dest == 0) // N
	{
		game->line->y_dest = 0;
		if (angle < 360 && angle > 180)
		{
			op_side = tan(deg_to_radian(360 - angle)) * game->map->pos_y;
			printf("< 360 op_side: %i\n", op_side);
		}
		else
		{
			op_side = tan(deg_to_radian(angle)) * game->map->pos_y;
			printf("> 0 op_side: %i\n", op_side);
		}
	}
	if (game->fov->toggle == 'E' && game->line->x_dest >= game->map->width * game->img_size) // E
	{
		game->line->x_dest = game->map->width * game->img_size;
		op_side = tan(deg_to_radian(absolute_value(90 - angle))) * (game->map->width * game->img_size - game->map->pos_x);
	}
	if (game->fov->toggle == 'S' && game->line->y_dest >= game->map->height * game->img_size) // S
	{
		game->line->y_dest = game->map->height * game->img_size;
		op_side = tan(deg_to_radian(absolute_value(180 - angle))) * (game->map->height * game->img_size - game->map->pos_y);
	}
	if (game->fov->toggle == 'W' && game->line->x_dest <= 0) // W
	{
		game->line->x_dest = 0;
		op_side = tan(deg_to_radian(absolute_value(270 - angle))) * (game->map->pos_x);
	}
	// if (game->line->x_dest >= game->map->width * game->img_size)
	// {
	// 	game->line->x_dest = game->map->width * game->img_size;
	// 	op_side = tan(deg_to_radian(absolute_value(90 - angle))) * (game->map->width * game->img_size - game->map->pos_x);
	// }

	// int ite = 0;
	// while (ite++ < game->map->pos_y)
	// {
	// 	if (ite >= game->map->height * game->img_size)
	// 		break ;
	// 	img_pix_put(game, game->map->pos_x, ite, get_color(255, 0, 0));
	// }
	(void)i;
	//	printf("op_side: %i\n", op_side);
	// printf(" %f\n", sqrt(pow(op_side, 2) + pow(game->fov->len_first_line, 2)));
	return (op_side);
}

// void	move_w(t_game *game)
// {
// 	if (game->fov->angle > 0 && game->fov->angle <= 45)
// 	{
// 		printf(BACK_RED"NNE"RST"\n");
// 		game->map->pos_x += absolute_value(sin(deg_to_radian(game->fov->angle)) * 5);
// 		game->map->pos_y -= absolute_value(cos(deg_to_radian(game->fov->angle)) * 5);
// 	}
// 	if (game->fov->angle > 45 && game->fov->angle < 90)
// 	{
// 		printf(BACK_RED"NEE"RST"\n");
// 		game->map->pos_x += absolute_value(sin(deg_to_radian(game->fov->angle)) * 5);
// 		game->map->pos_y -= absolute_value(cos(deg_to_radian(game->fov->angle)) * 5);
// 	}
// 	if (game->fov->angle > 90 && game->fov->angle <= 135)
// 	{
// 		printf(BACK_YELLOW"EES"RST"\n");
// 		game->map->pos_x += absolute_value(sin(deg_to_radian(game->fov->angle)) * 5);
// 		game->map->pos_y += absolute_value(cos(deg_to_radian(game->fov->angle)) * 5);
// 	}
// 	if (game->fov->angle > 135 && game->fov->angle < 180)
// 	{
// 		printf(BACK_YELLOW"SSE"RST"\n");
// 		game->map->pos_x += absolute_value(sin(deg_to_radian(game->fov->angle)) * 5);
// 		game->map->pos_y += absolute_value(cos(deg_to_radian(game->fov->angle)) * 5);
// 	}
// 	if (game->fov->angle > 180 && game->fov->angle <= 225)
// 	{
// 		printf(BACK_YELLOW"SSW"RST"\n");
// 		game->map->pos_x -= absolute_value(sin(deg_to_radian(game->fov->angle)) * 5);
// 		game->map->pos_y += absolute_value(cos(deg_to_radian(game->fov->angle)) * 5);
// 	}
// 	if (game->fov->angle > 225 && game->fov->angle < 270)
// 	{
// 		printf(BACK_RED"SWW"RST"\n");
// 		game->map->pos_x -= absolute_value(sin(deg_to_radian(game->fov->angle)) * 5);
// 		game->map->pos_y += absolute_value(cos(deg_to_radian(game->fov->angle)) * 5);
// 	}
// 	if (game->fov->angle > 270 && game->fov->angle <= 315)
// 	{
// 		printf(BACK_RED"WWN"RST"\n");
// 		game->map->pos_x -= absolute_value(sin(deg_to_radian(game->fov->angle)) * 5);
// 		game->map->pos_y -= absolute_value(cos(deg_to_radian(game->fov->angle)) * 5);
// 	}
// 	if (game->fov->angle > 315 && game->fov->angle < 360)
// 	{
// 		printf(BACK_RED"NNW"RST"\n");
// 		game->map->pos_x -= absolute_value(sin(deg_to_radian(game->fov->angle)) * 5);
// 		game->map->pos_y -= absolute_value(cos(deg_to_radian(game->fov->angle)) * 5);
// 	}
// }

void	move_w(t_game *game)
{
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

	printf("game->line->steps = : %i\n", game->line->steps);
	int i = 0;

	while (i <= game->line->steps)
	{
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		if (game->map->map_org[(int)(round(game->line->corr_y) / game->img_size)][(int)(round(game->line->corr_x) / game->img_size)] == '1')
			return ;
		if (i == 10)
			break ;
		i++;
	}
	// int y = (round(game->line->corr_y));
	// int x = (round(game->line->corr_x));

	// printf("(y / game->img_size) - 5: %i\n", (y / game->img_size) + 5);
	// printf("(x / game->img_size) - 5: %i\n", (x / game->img_size) + 5);
	
	// if (game->map->map_org[(y / game->img_size) + 5][(x / game->img_size) + 5] != '1')
	// {
		game->map->pos_x = round(game->line->corr_x);
		game->map->pos_y = round(game->line->corr_y);
	//}
}

// void	move_s(t_game *game)
// {
// 	// if (game->fov->angle > 315 && game->fov->angle <= 45)
// 	// {
// 	// 	game->map->pos_x += sin(deg_to_radian(game->fov->angle)) * 5;
// 	// 	game->map->pos_y += cos(deg_to_radian(game->fov->angle)) * 5;
// 	// }
// 	// else if (game->fov->angle > 45 && game->fov->angle <= 135)
// 	// {
// 	// 	game->map->pos_ = sin(deg_to_radian(game->fov->angle)) * 5;
// 	// 	game->map->pos_ = cos(deg_to_radian(game->fov->angle)) * 5;
// 	// }
// 	// else if (game->fov->angle > 135 && game->fov->angle <= 225)
// 	// {
// 	// 	game->map->pos_ = sin(deg_to_radian(game->fov->angle)) * 5;
// 	// 	game->map->pos_ = cos(deg_to_radian(game->fov->angle)) * 5;
// 	// }
// 	// else if (game->fov->angle > 225 && game->fov->angle <= 315)
// 	// {
// 	// 	game->map->pos_ = sin(deg_to_radian(game->fov->angle)) * 5;
// 	// 	game->map->pos_ = cos(deg_to_radian(game->fov->angle)) * 5;
// 	// }
// 	(void)game;
// }

void	move_s(t_game *game)
{
	int angle = 0;
	int dest_y = 0;
	int dest_x = 0;

	
	// if (game->fov->angle < 180 || game->fov->angle == 0)
	// 	angle = game->fov->angle + 180;
	// else if (game->fov->angle > 180 || game->fov->angle == 360)
	// 	angle = game->fov->angle - 180;
	(void)angle;
	if (game->fov->toggle == 'S')
	{
		dest_x = (2 * game->map->pos_x - game->line->x_dest); 
		dest_y = (2 * game->map->pos_y - game->line->y_dest);
		game->line->dx = dest_x - game->line->x_src;
		game->line->dy = dest_y - game->line->y_src;
	}
	if (game->fov->toggle == 'N')
	{
		dest_x = (2 * game->map->pos_x - game->line->x_dest); 
		dest_y = (2 * game->map->pos_y - game->line->y_dest);
		game->line->dx = dest_x - game->line->x_src;
		game->line->dy = dest_y - game->line->y_src;
	}
	if (game->fov->toggle == 'E')
	{
		dest_x = (2 * game->map->pos_x - game->line->x_dest); 
		dest_y = (2 * game->map->pos_y - game->line->y_dest);
		game->line->dx = dest_x - game->line->x_src;
		game->line->dy = dest_y - game->line->y_src;
	}
	if (game->fov->toggle == 'W')
	{
		dest_x = (2 * game->map->pos_x - game->line->x_dest); 
		dest_y = (2 * game->map->pos_y - game->line->y_dest);
		game->line->dx = dest_x - game->line->x_src;
		game->line->dy = dest_y - game->line->y_src;
	}

	
	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);

	game->line->xite = game->line->dx / (float)game->line->steps;
	game->line->yite = game->line->dy / (float)game->line->steps;

	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;

	printf("game->line->steps = : %i\n", game->line->steps);
	int i = 0;

	while (i <= game->line->steps)
	{
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		if (game->map->map_org[(int)(round(game->line->corr_y) / game->img_size)][(int)(round(game->line->corr_x) / game->img_size)] == '1')
			return ;
		if (i == 10)
			break ;
		i++;
	}
	// int y = (round(game->line->corr_y));
	// int x = (round(game->line->corr_x));

	// printf("(y / game->img_size) - 5: %i\n", (y / game->img_size) + 5);
	// printf("(x / game->img_size) - 5: %i\n", (x / game->img_size) + 5);
	
	// if (game->map->map_org[(y / game->img_size) + 5][(x / game->img_size) + 5] != '1')
	// {
	game->map->pos_x = round(game->line->corr_x);
	game->map->pos_y = round(game->line->corr_y);
	printf("game->fov->angle: %i\n", game->fov->angle);
	printf("game->map->pos_x: %i\n", game->map->pos_x);
	printf("game->map->pos_y: %i\n", game->map->pos_y);
	//}
}
