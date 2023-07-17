/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:15:57 by gael              #+#    #+#             */
/*   Updated: 2023/07/17 16:59:07 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	display_3d_down(t_game *game)
{
	int	i_midline;
	int	i_draw;
	int	i_ratio;
	int	y;
	int	i_main;
	int flag_1;
	int flag_2;
	int flag_3;
	int flag_4;
	int flag_5 = FAIL;
	int flag_6 = FAIL;
	
	i_main = 0;
	i_draw = 0;
	i_ratio = 0;
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	i_midline = game->fov->nbr_ray;
	if (init_temp(game) == FAIL)
		return (FAIL);
	while (i_midline > game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		// printf(BACK_PURPLE"game->fov->lines_vision[%i]: %i"RST"\n", i_midline, game->fov->lines_vision[i_midline]);
		while (i_ratio < 2)
		{
			game->line_3d->x_dest = i_main;
			game->line_3d->x_src = i_main;

			game->line_3d->y_src = (game->win_height / 2) + (game->map->height * game->img_size);
			game->line_3d->y_dest = (game->win_height / 2) + (game->map->height * game->img_size);
			// game->line_3d->y_dest += (game->fov->lines_vision[i_midline] * (-1));
			// if (((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]) - i_ratio > ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline - 1]) - i_ratio)
			// {
			// 	game->line_3d->y_dest += ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]) - i_ratio / 2;
			// }
			// else
			if (game->fov->lines_vision[i_midline] == 0)
				game->fov->lines_vision[i_midline] = 1;
			game->line_3d->y_dest += ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]);
			// printf(BACK_PURPLE"( game->fov->lines_vision[%i]) - i_ratio: %i"RST"\n", i_midline, ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]) - i_ratio);
			// printf(BACK_PURPLE"( game->fov->lines_vision[%i]) - i_ratio: %i"RST"\n", i_midline - 1, ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline - 1]) - i_ratio);
			// printf("\n");
			// if (i_ratio == 19 && i_midline == 31)
			// {
			// 	flag_1 = game->line_3d->y_dest;
			// 	flag_3 = game->line_3d->x_dest;
			// 	draw_line_temp(game, flag_1, flag_2, flag_3, flag_4);
			// 	printf(PURPLE"flag_1: %i"RESET"\n", flag_1);
			// }
			// if (i_ratio == 0 && i_midline == 60)
			// {
			// 	flag_2 = game->line_3d->y_dest;
			// 	flag_4 = game->line_3d->x_src;
			// }
			// int i = 60;
			// int flag_5;
			// while (game->fov->toggle_vision[i] > 30)
			// {
			// 	if (i == 60)
			// 	{
			// 		flag_2 = game->line_3d->y_dest;
			// 		flag_4 = game->line_3d->x_src;
			// 	}
			// 	if (flag_5 == SUCCESS)
			// 	{
			// 		flag_2
			// 	}
			// 	if (game->fov->toggle_vision[i] != game->fov->toggle_vision[i - 1])
			
			// 	i--;
			// }
			// printf("tv[%i]: %i\tflag_5: %i\n", i_midline, game->fov->toggle_vision[i_midline], flag_5);
			// printf("tv[%i]: %i\tflag_5: %i\n", i_midline - 1, game->fov->toggle_vision[i_midline - 1], flag_5);
			// printf("\n");
			// if (flag_6 == SUCCESS && game->fov->toggle_vision[i_midline] != game->fov->toggle_vision[i_midline + 1] && i_ratio == 0)
			// {
			// 	flag_1 = game->line_3d->y_dest;
			// 	flag_3 = game->line_3d->x_dest;
			// 	//draw_line_temp(game, flag_1, flag_2, flag_3, flag_4);
			// 	flag_5 = SUCCESS;
			// 	flag_2 = game->line_3d->y_dest;
			// 	flag_4 = game->line_3d->x_src;
			// }
			// if (flag_5 == FAIL && game->fov->toggle_vision[i_midline] != game->fov->toggle_vision[i_midline - 1])
			// {
			// 	flag_6 = SUCCESS;
			// }
			game->line_3d->dx = game->line_3d->x_dest - game->line_3d->x_src;
			game->line_3d->dy = game->line_3d->y_dest - game->line_3d->y_src;
			if (absolute_value(game->line_3d->dx) > absolute_value(game->line_3d->dy))
				game->line_3d->steps = absolute_value(game->line_3d->dx);
			else
				game->line_3d->steps = absolute_value(game->line_3d->dy);
			game->line_3d->xite = game->line_3d->dx / (float)game->line_3d->steps;
			game->line_3d->yite = game->line_3d->dy / (float)game->line_3d->steps;
			game->line_3d->corr_x = game->line_3d->x_src;
			game->line_3d->corr_y = game->line_3d->y_src;
			i_draw = 0;
			while (i_draw <= game->line_3d->steps)
			{
				if (game->line_3d->corr_y < game->map->height * game->img_size || game->line_3d->corr_y > game->win_height + game->map->height * game->img_size)
					break ;
				//img_pix_put(game, round(game->line_3d->corr_x), round(game->line_3d->corr_y), get_color(0, 0, 255));
				if (game->fov->toggle_vision[i_midline] == 'E')
				{
					img_pix_put(game, round(game->line_3d->corr_x),
					round(game->line_3d->corr_y), get_color(255, 0, 0));
				}
				else if (game->fov->toggle_vision[i_midline] == 'N')
				{
					img_pix_put(game, round(game->line_3d->corr_x),
					round(game->line_3d->corr_y), get_color(255, 255, 0));
				}
				else if (game->fov->toggle_vision[i_midline] == 'S')
				{
					img_pix_put(game, round(game->line_3d->corr_x),
					round(game->line_3d->corr_y), get_color(0, 0, 255));
				}
				else if (game->fov->toggle_vision[i_midline] == 'W')
				{
					img_pix_put(game, round(game->line_3d->corr_x),
					round(game->line_3d->corr_y), get_color(0, 255, 0));
				}
				game->line_3d->corr_x = game->line_3d->corr_x + game->line_3d->xite;
				game->line_3d->corr_y = game->line_3d->corr_y + game->line_3d->yite;
				i_draw++;
			}
			i_ratio++;
			i_main++;
		}
		// printf(PURPLE"game->fov->lines_vision[%i]: %i"RESET"\n", i_midline, game->fov->lines_vision[i_midline]);
		// printf(BACK_PURPLE"game->line_3d->corr_y: %f"RST"\n", game->line_3d->corr_y);
		// printf(BACK_PURPLE"game->line_3d->corr_x: %f"RST"\n", game->line_3d->corr_x);
		// printf("\n");
		// printf("\n.....................................\n\n");
		i_midline--;
	}
	i_draw = 0;
	y = (game->win_height / 2) + (game->map->height * game->img_size);
	i_midline = 0;
	while (i_midline < game->fov->nbr_ray / 2)
	{
		i_ratio = 0;
		while (i_ratio < 2)
		{
			game->line_3d->x_dest = i_main;
			game->line_3d->x_src = i_main;

			game->line_3d->y_src = (game->win_height / 2) + (game->map->height * game->img_size);
			game->line_3d->y_dest = (game->win_height / 2) + (game->map->height * game->img_size);
			// game->line_3d->y_dest += (game->fov->lines_vision[i_midline] * (-1) );
			if (game->fov->lines_vision[i_midline] == 0)
				game->fov->lines_vision[i_midline] = 1;
			game->line_3d->y_dest += ((game->fov->proj_plane * game->img_size) / game->fov->lines_vision[i_midline]);// + i_ratio;


			game->line_3d->dx = game->line_3d->x_dest - game->line_3d->x_src;
			game->line_3d->dy = game->line_3d->y_dest - game->line_3d->y_src;
			if (absolute_value(game->line_3d->dx) > absolute_value(game->line_3d->dy))
				game->line_3d->steps = absolute_value(game->line_3d->dx);
			else
				game->line_3d->steps = absolute_value(game->line_3d->dy);
			game->line_3d->xite = game->line_3d->dx / (float)game->line_3d->steps;
			game->line_3d->yite = game->line_3d->dy / (float)game->line_3d->steps;
			game->line_3d->corr_x = game->line_3d->x_src;
			game->line_3d->corr_y = game->line_3d->y_src;
			i_draw = 0;
			while (i_draw <= game->line_3d->steps)
			{
				if (game->line_3d->corr_y < game->map->height * game->img_size || game->line_3d->corr_y > game->win_height + game->map->height * game->img_size)
					break ;
				// img_pix_put(game, round(game->line_3d->corr_x),
				// round(game->line_3d->corr_y), get_color(255, 0, 0));
				if (game->fov->toggle_vision[i_midline] == 'E')
				{
					img_pix_put(game, round(game->line_3d->corr_x),
					round(game->line_3d->corr_y), get_color(255, 0, 0));
				}
				else if (game->fov->toggle_vision[i_midline] == 'N')
				{
					img_pix_put(game, round(game->line_3d->corr_x),
					round(game->line_3d->corr_y), get_color(255, 255, 0));
				}
				else if (game->fov->toggle_vision[i_midline] == 'S')
				{
					img_pix_put(game, round(game->line_3d->corr_x),
					round(game->line_3d->corr_y), get_color(0, 0, 255));
				}
				else if (game->fov->toggle_vision[i_midline] == 'W')
				{
			
					img_pix_put(game, round(game->line_3d->corr_x),
					round(game->line_3d->corr_y), get_color(0, 255, 0));
				}
				game->line_3d->corr_x = game->line_3d->corr_x + game->line_3d->xite;
				game->line_3d->corr_y = game->line_3d->corr_y + game->line_3d->yite;
				i_draw++;
			}

			i_ratio++;
			i_main++;
		}
		// printf(RED"game->fov->lines_vision[%i]: %i"RESET"\n", i_midline, game->fov->lines_vision[i_midline]);
		// printf(BACK_RED"game->line_3d->corr_y: %f"RST"\n", game->line_3d->corr_y);
		// printf(BACK_RED"game->line_3d->corr_x: %f"RST"\n", game->line->corr_x);
		// printf("\n");
		i_midline++;
	}
	return (SUCCESS);
	(void)game;
	(void)y;
	(void)flag_1;
	(void)flag_2;
	(void)flag_3;
	(void)flag_4;
	(void)flag_5;
	(void)flag_6;
}


int	init_temp(t_game *game)
{
	game->temp = malloc(sizeof(t_temp));
	if (!game->temp)
		return (printf("Malloc temp failed\n"), FAIL);
	game->temp->dx = 0;
	game->temp->dy = 0;
	game->temp->steps = 0;
	game->temp->xite = 0;
	game->temp->yite = 0;
	game->temp->corr_x = 0;
	game->temp->corr_y = 0;
	game->temp->x_src = 0;
	game->temp->y_src = 0;
	game->temp->x_dest = 0;
	game->temp->y_dest = 0;
	game->temp->x_dest_prev = 0;
	game->temp->y_dest_prev = 0;
	return (SUCCESS);
}



void	draw_line_temp(t_game *game, int flag_1, int flag_2, int flag_3, int flag_4)
{
	game->temp->x_dest = flag_3;
	game->temp->x_src = flag_4;

	game->temp->y_src = flag_2;
	game->temp->y_dest = flag_1;


	game->temp->dx = game->temp->x_dest - game->temp->x_src;
	game->temp->dy = game->temp->y_dest - game->temp->y_src;
	if (absolute_value(game->temp->dx) > absolute_value(game->temp->dy))
		game->temp->steps = absolute_value(game->temp->dx);
	else
		game->temp->steps = absolute_value(game->temp->dy);
	game->temp->xite = game->temp->dx / (float)game->temp->steps;
	game->temp->yite = game->temp->dy / (float)game->temp->steps;
	game->temp->corr_x = game->temp->x_src;
	game->temp->corr_y = game->temp->y_src;
	int i_draw = 0;
	while (i_draw <= game->temp->steps)
	{
		// if (game->temp->corr_y < game->map->height * game->img_size || game->temp->corr_y > game->win_height + game->map->height * game->img_size)
		// 	break ;
		int	temp_y;

		temp_y = game->temp->corr_y;
		while (temp_y >= game->line_3d->y_dest)
		{
			img_pix_put(game, round(game->temp->corr_x),
			round(temp_y), get_color(0, 0, 255));
			temp_y--;
		}
		// img_pix_put(game, round(game->temp->corr_x),
		// round(game->temp->corr_y), get_color(255, 255, 255));
		game->temp->corr_x = game->temp->corr_x + game->temp->xite;
		game->temp->corr_y = game->temp->corr_y + game->temp->yite;
		i_draw++;
	}
}
