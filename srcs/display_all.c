/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:04:13 by gael              #+#    #+#             */
/*   Updated: 2023/07/11 16:09:21 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_all(t_game *game, char key)
{
	int len_side;
	int i_rotate;
	int save;
	int save_2;

	i_rotate = 0;
	if (init_display_all(game, key, &len_side) == FAIL)
		return (FAIL);
	if (game->fov->toggle == 'E' && game->line->x_dest >= game->map->width * game->img_size)
		set_dest_e(game, key, len_side);
	else if (game->fov->toggle == 'S' && game->line->y_dest >= game->map->height * game->img_size)
		set_dest_s(game, key, len_side);
	else if (game->fov->toggle == 'W' && game->line->x_dest <= 0)
		set_dest_w(game, key, len_side);
	else if (game->fov->toggle == 'N' && game->line->y_dest <= 0)
		set_dest_n(game, key, len_side);
	move_straight(game);
	game->fov->lines_vision[15] = draw_line_vision(game, get_color(0, 255, 0));
	//printf(PURPLE"game->fov->lines_vision[15]: %i"RESET"\n", game->fov->lines_vision[15]);
	int	len_vision;
	int	angle;
	int	save_x;
	int	save_y;

	save_x = game->line->x_dest;
	save_y = game->line->y_dest;
	angle = game->fov->angle;
	len_vision = 0;
	i_rotate = 0;
	// if (angle > 270)
	// 	angle = abs(angle - 360);
	printf(GREEN"game->fov->angle: %i"RESET"\n", game->fov->angle);
	while (i_rotate < game->fov->nbr_ray / 2)
	{
		if (game->fov->angle >= 0 && game->fov->angle < 60)
		{
			// printf(GREEN"0 - 90"RESET"\n");
			len_vision = tan(deg_to_radian(abs(angle + (int)(game->fov->deg * i_rotate)))) * game->map->pos_y;
			if (angle + (int)(game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle >= 330 && game->fov->angle < 360)
		{
			// printf(GREEN"330 - 360"RESET"\n");
			len_vision = tan(deg_to_radian(abs(360 - angle - (int)(game->fov->deg * i_rotate)))) * game->map->pos_y;
			if (360 - angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x - len_vision;
			else
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle < 330 && game->fov->angle >= 270)
		{
			// printf(GREEN"270 - 330"RESET"\n");
			len_vision = tan(deg_to_radian(abs(270 - angle - (int)(game->fov->deg * i_rotate)))) * game->map->pos_x;
			if (270 - angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = 0;
		}
		if (game->fov->angle >= 60 && game->fov->angle < 150)
		{
			// printf(GREEN"60 - 180"RESET"\n");
			len_vision = tan( deg_to_radian(abs(90 - angle - (int)(game->fov->deg * i_rotate))) ) * (game->map->width * game->img_size - game->map->pos_x);
			if ((90 - angle - (int)(game->fov->deg * i_rotate)) > 0)
				game->line->y_dest = game->map->pos_y - len_vision;
			else
				game->line->y_dest = game->map->pos_y + len_vision;
			game->line->x_dest = game->map->width * game->img_size;
		}
		if (game->fov->angle >= 150 && game->fov->angle < 240)
		{
			// printf(GREEN"150 - 240"RESET"\n");
			len_vision = tan(deg_to_radian(abs(180 - angle - (int)(game->fov->deg * i_rotate)))) * (game->map->height * game->img_size - game->map->pos_y);
			if (180 - angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			else
				game->line->x_dest = game->map->pos_x - len_vision;
			game->line->y_dest = game->map->height * game->img_size;
		}
		if (game->fov->angle >= 240 && game->fov->angle < 270)
		{
			// printf(GREEN"240 - 330"RESET"\n");
			len_vision = tan(deg_to_radian(abs(270 - angle - (int)(game->fov->deg * i_rotate)))) * game->map->pos_x;
			if (270 - angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = 0;
		}
		// printf(RED"%i - %i: %i"RESET"\t", angle,(int) game->fov->deg * i_rotate, 270 - angle - (int)(game->fov->deg * i_rotate));
		// printf(BOLD_RED"game->line->x_dest: %i"RESET"\t\t", game->line->x_dest);
		// printf(BOLD_RED"game->line->y_dest: %i"RESET"\t\t", game->line->y_dest);
		// printf(RED"len_vision: %i"RESET"\n", len_vision);

		game->fov->lines_vision[i_rotate] = draw_line_vision(game, get_color(255, 255 / (game->fov->nbr_ray / 2) * ((game->fov->nbr_ray / 2) - i_rotate), 0));
		i_rotate++;
	}
	// printf(PURPLE"middle - lines_vision[%i]: %i"RESET"\n", i_rotate, game->fov->lines_vision[i_rotate]);


	i_rotate = 1;
	if (angle > 180)
		angle = abs(angle - 360);
	printf(GREEN"angle: %i"RESET"\n", angle);
	while (i_rotate <= game->fov->nbr_ray / 2)
	{
		if (game->fov->angle >= 0 && game->fov->angle < 90)
		{
			// printf(GREEN"0 - 90"RESET"\n");
			len_vision = tan(deg_to_radian(abs(angle - (int)(game->fov->deg * i_rotate)))) * game->map->pos_y;
			if (angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			else
				game->line->x_dest = game->map->pos_x - len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle >= 90 && game->fov->angle < 180)
		{
			// printf(GREEN"90 - 180"RESET"\n");
			len_vision = tan( deg_to_radian(abs(angle - (int)(game->fov->deg * i_rotate) - 90)) ) * (game->map->width * game->img_size - game->map->pos_x);
			if ((angle - (int)(game->fov->deg * i_rotate)) > 90)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = game->map->width * game->img_size;
		}
		if (game->fov->angle >= 180 && game->fov->angle < 270)
		{
			// printf(GREEN"180 - 270"RESET"\n");
			len_vision = tan( deg_to_radian(abs(180 - angle - (int)(game->fov->deg * i_rotate))) ) * (game->map->height * game->img_size - game->map->pos_y);
			if (180 - angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x - len_vision;
			else
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = game->map->height * game->img_size;
		}
		if (game->fov->angle >= 270 && game->fov->angle < 360)
		{
			// printf(GREEN"270 - 360"RESET"\n");
			len_vision = tan( deg_to_radian(abs(90 - angle - (int)(game->fov->deg * i_rotate))) ) * (game->map->pos_x);
			if (90 - angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->y_dest = game->map->pos_y - len_vision;
			else
				game->line->y_dest = game->map->pos_y + len_vision;
			game->line->x_dest = 0;
		}
		// printf(PURPLE"90 - (%i - %i)= %i"RESET"\t", angle,(int) game->fov->deg * i_rotate, (90 - angle -(int) game->fov->deg * i_rotate));
		// printf(BOLD_PURPLE"game->line->x_dest: %i"RESET"\t\t", game->line->x_dest);
		// printf(BOLD_PURPLE"game->line->y_dest: %i"RESET"\t\t", game->line->y_dest);
		// printf(PURPLE"len_vision: %i"RESET"\n", len_vision);

		game->fov->lines_vision[i_rotate + 15] = draw_line_vision(game, get_color(0, 255 / (game->fov->nbr_ray / 2) * ((game->fov->nbr_ray / 2) - i_rotate), 255));
		i_rotate++;
	}

	game->line->x_dest = save_x;
	game->line->y_dest = save_y;
	// int j = 0;
	// while(j < 31)
	// {
	// 	printf("game->fov->lines_vision[%i]: %i\n", j, game->fov->lines_vision[j]);
	// 	j++;
	// }
	// printf(PURPLE"height: %i"RESET"\n", game->img_size * game->map->height);
	// save = game->line->x_dest;
	// save_2 = game->line->y_dest;
	// vision(game, save, save_2);
	// game->line->x_dest = save;
	// game->line->y_dest = save_2;
	mlx_put_image_to_window(game->mlibx, game->window, game->img->mlx_img, 0, 0);
	(void)i_rotate;
	(void)save;
	(void)save_2;
	printf("------------------------------\n");
	return (SUCCESS);
}

void	set_dest_e(t_game *game, int key, int len_side)
{
	if (game->fov->angle < 90)
	{
		if (key == 'd')
			game->line->y_dest = game->map->pos_y - len_side;
		else if (key == 'a')
			game->line->y_dest = game->map->pos_y - len_side;
	}
	else if (game->fov->angle >= 90)
	{
		if (key == 'd')
			game->line->y_dest = game->map->pos_y + len_side;
		else if (key == 'a')
			game->line->y_dest = game->map->pos_y + len_side;
	}
}

void	set_dest_s(t_game *game, int key, int len_side)
{
	if (game->fov->angle < 180)
	{
		if (key == 'd')
			game->line->x_dest = game->map->pos_x + len_side;
		else if (key == 'a')
			game->line->x_dest = game->map->pos_x + len_side;
	}
	else if (game->fov->angle >= 180)
	{
		if (key == 'd')
			game->line->x_dest = game->map->pos_x - len_side;
		else if (key == 'a')
			game->line->x_dest = game->map->pos_x - len_side;
	}
}

void	set_dest_w(t_game *game, int key, int len_side)
{
	if (game->fov->angle < 270)
	{
		if (key == 'd')
			game->line->y_dest = game->map->pos_y + len_side;
		else if (key == 'a')
			game->line->y_dest = game->map->pos_y + len_side;
	}
	else if (game->fov->angle >= 270)
	{
		if (key == 'd')
			game->line->y_dest = game->map->pos_y - len_side;
		else if (key == 'a')
			game->line->y_dest = game->map->pos_y - len_side;
	}
}

void	set_dest_n(t_game *game, int key, int len_side)
{
	if (game->fov->angle >= 0 && game->fov->angle < 180)
	{
		if (key == 'd')
			game->line->x_dest = game->map->pos_x + len_side;
		else if (key == 'a')
			game->line->x_dest = game->map->pos_x + len_side;
	}
	else if (game->fov->angle < 360 && game->fov->angle > 180)
	{
		if (key == 'd')
			game->line->x_dest = game->map->pos_x - len_side;
		else if (key == 'a')
			game->line->x_dest = game->map->pos_x - len_side;
	}
}
