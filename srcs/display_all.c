/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:04:13 by gael              #+#    #+#             */
/*   Updated: 2023/07/12 18:21:11 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_all(t_game *game, int key)
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
	game->fov->lines_vision[game->fov->nbr_ray / 2] = draw_line_vision(game, get_color(0, 255, 0));
	int	len_vision;
	int	angle;
	int	save_x;
	int	save_y;

	save_x = game->line->x_dest;
	save_y = game->line->y_dest;
	angle = game->fov->angle;
	len_vision = 0;
	i_rotate = 0;
	while (i_rotate < game->fov->nbr_ray / 2)
	{
		int	angle_2;

		angle_2 = 0;
		if (game->fov->angle >= 0 && game->fov->angle < 60)
		{
			angle_2 = angle + (int)(game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs(angle_2))) * game->map->pos_y;
			if (angle_2 > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle >= 330 && game->fov->angle < 360)
		{
			angle_2 = 360 - angle - (int)(game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs(angle_2))) * game->map->pos_y;
			if (angle_2 > 0)
				game->line->x_dest = game->map->pos_x - len_vision;
			else
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle < 330 && game->fov->angle >= 270)
		{
			angle_2 = 270 - angle - (int)(game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs(angle_2))) * game->map->pos_x;
			if (angle_2 > 0)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = 0;
		}
		if (game->fov->angle >= 60 && game->fov->angle < 150)
		{
			angle_2 = 90 - angle - (int)(game->fov->deg * i_rotate);
			len_vision = tan( deg_to_radian(abs(angle_2)) ) * (game->map->width * game->img_size - game->map->pos_x);
			if ((angle_2) > 0)
				game->line->y_dest = game->map->pos_y - len_vision;
			else
				game->line->y_dest = game->map->pos_y + len_vision;
			game->line->x_dest = game->map->width * game->img_size;
		}
		if (game->fov->angle >= 150 && game->fov->angle < 240)
		{
			angle_2 = 180 - angle - (int)(game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs(angle_2))) * (game->map->height * game->img_size - game->map->pos_y);
			if (angle_2 > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			else
				game->line->x_dest = game->map->pos_x - len_vision;
			game->line->y_dest = game->map->height * game->img_size;
		}
		if (game->fov->angle >= 240 && game->fov->angle < 270)
		{
			angle_2 = 270 - angle - (int)(game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs(angle_2))) * game->map->pos_x;
			if (angle_2 > 0)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = 0;
		}

		game->fov->lines_vision[i_rotate] = draw_line_vision(game, get_color(255, 255 / (game->fov->nbr_ray / 2) * ((game->fov->nbr_ray / 2) - i_rotate), 0));
		game->fov->lines_vision[i_rotate] = abs_flt(cos(deg_to_radian(game->fov->deg * i_rotate))) * game->fov->lines_vision[i_rotate];
		// printf(BACK_RED"game->fov->lines_vision[%i]: %i"RST"\n", i_rotate, game->fov->lines_vision[i_rotate]);
		i_rotate++;
	}


	i_rotate = 1;
	if (angle > 180)
		angle = abs(angle - 360);
	while (i_rotate <= game->fov->nbr_ray / 2)
	{
		if (game->fov->angle >= 0 && game->fov->angle < 90)
		{
			len_vision = tan(deg_to_radian(abs(angle - (int)(game->fov->deg * i_rotate)))) * game->map->pos_y;
			if (angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			else
				game->line->x_dest = game->map->pos_x - len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle >= 90 && game->fov->angle < 180)
		{
			len_vision = tan( deg_to_radian(abs(angle - (int)(game->fov->deg * i_rotate) - 90)) ) * (game->map->width * game->img_size - game->map->pos_x);
			if ((angle - (int)(game->fov->deg * i_rotate)) > 90)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = game->map->width * game->img_size;
		}
		if (game->fov->angle >= 180 && game->fov->angle < 270)
		{
			len_vision = tan( deg_to_radian(abs(180 - angle - (int)(game->fov->deg * i_rotate))) ) * (game->map->height * game->img_size - game->map->pos_y);
			if (180 - angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x - len_vision;
			else
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = game->map->height * game->img_size;
		}
		if (game->fov->angle >= 270 && game->fov->angle < 360)
		{
			len_vision = tan( deg_to_radian(abs(90 - angle - (int)(game->fov->deg * i_rotate))) ) * (game->map->pos_x);
			if (90 - angle - (int)(game->fov->deg * i_rotate) > 0)
				game->line->y_dest = game->map->pos_y - len_vision;
			else
				game->line->y_dest = game->map->pos_y + len_vision;
			game->line->x_dest = 0;
		}

		game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2] = draw_line_vision(game, get_color(0, 255 / (game->fov->nbr_ray / 2) * ((game->fov->nbr_ray / 2) - i_rotate), 255));
		game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2] = abs_flt(cos(deg_to_radian(game->fov->deg * i_rotate))) * game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2];
		i_rotate++;
	}
	display_3d(game);
	game->line->x_dest = save_x;
	game->line->y_dest = save_y;
	mlx_put_image_to_window(game->mlibx, game->window, game->img->mlx_img, 0, 0);
	printf("\n.....................................\n\n");
	(void)i_rotate;
	(void)save;
	(void)save_2;
	return (SUCCESS);
}

void	set_dest_e(t_game *game, int key, int len_side)
{
	if (game->fov->angle < 90)
	{
		if (key == 65363)
			game->line->y_dest = game->map->pos_y - len_side;
		else if (key == 65361)
			game->line->y_dest = game->map->pos_y - len_side;
	}
	else if (game->fov->angle >= 90)
	{
		if (key == 65363)
			game->line->y_dest = game->map->pos_y + len_side;
		else if (key == 65361)
			game->line->y_dest = game->map->pos_y + len_side;
	}
}

void	set_dest_s(t_game *game, int key, int len_side)
{
	if (game->fov->angle < 180)
	{
		if (key == 65363)
			game->line->x_dest = game->map->pos_x + len_side;
		else if (key == 65361)
			game->line->x_dest = game->map->pos_x + len_side;
	}
	else if (game->fov->angle >= 180)
	{
		if (key == 65363)
			game->line->x_dest = game->map->pos_x - len_side;
		else if (key == 65361)
			game->line->x_dest = game->map->pos_x - len_side;
	}
}

void	set_dest_w(t_game *game, int key, int len_side)
{
	if (game->fov->angle < 270)
	{
		if (key == 65363)
			game->line->y_dest = game->map->pos_y + len_side;
		else if (key == 65361)
			game->line->y_dest = game->map->pos_y + len_side;
	}
	else if (game->fov->angle >= 270)
	{
		if (key == 65363)
			game->line->y_dest = game->map->pos_y - len_side;
		else if (key == 65361)
			game->line->y_dest = game->map->pos_y - len_side;
	}
}

void	set_dest_n(t_game *game, int key, int len_side)
{
	if (game->fov->angle >= 0 && game->fov->angle < 180)
	{
		if (key == 65363)
			game->line->x_dest = game->map->pos_x + len_side;
		else if (key == 65361)
			game->line->x_dest = game->map->pos_x + len_side;
	}
	else if (game->fov->angle < 360 && game->fov->angle > 180)
	{
		if (key == 65363)
			game->line->x_dest = game->map->pos_x - len_side;
		else if (key == 65361)
			game->line->x_dest = game->map->pos_x - len_side;
	}
}
