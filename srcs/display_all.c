/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:04:13 by gael              #+#    #+#             */
/*   Updated: 2023/08/02 15:16:21 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_all(t_game *game, int key)
{
	// printf("\033c");
	int len_side;
	int i_rotate;
	int save;
	int save_2;

	i_rotate = 0;
	if (init_display_all(game, key, &len_side) == FAIL)
		return (FAIL);

	move_straight(game);
	rotate_new(game);
	game->fov->lines_vision[game->fov->nbr_ray / 2] = draw_line_vision(game, get_color(0, 255, 0));
	game->fov->wall_witch[game->fov->nbr_ray / 2][0] = game->line->corr_x;
	game->fov->wall_witch[game->fov->nbr_ray / 2][1] = game->line->corr_y;
	game->fov->wall[game->fov->nbr_ray / 2][0] = game->line->corr_x / game->img_size;
	game->fov->wall[game->fov->nbr_ray / 2][1] = game->line->corr_y / game->img_size;
	double	angle;
	int		len_vision;
	int		save_x;
	int		save_y;

	save_x = game->line->x_dest;
	save_y = game->line->y_dest;
	angle = game->fov->angle;
	len_vision = 0;
	i_rotate = 0;
	// RED
	while (i_rotate < game->fov->nbr_ray / 2)
	{
		double	angle_2;

		angle_2 = 0;
		if (game->fov->angle >= 0 && game->fov->angle < 60)
		{
			angle_2 = angle + (game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs_dble(angle_2))) * game->map->pos_y;
			if (angle_2 > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle >= 330 && game->fov->angle < 360)
		{
			angle_2 = 360 - angle - (game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs_dble(angle_2))) * game->map->pos_y;
			if (angle_2 > 0)
				game->line->x_dest = game->map->pos_x - len_vision;
			else
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle < 330 && game->fov->angle >= 270)
		{
			angle_2 = 270 - angle - (game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs_dble(angle_2))) * game->map->pos_x;
			if (angle_2 > 0)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = 0;
		}
		if (game->fov->angle >= 60 && game->fov->angle < 150)
		{
			angle_2 = 90 - angle - (game->fov->deg * i_rotate);
			len_vision = tan( deg_to_radian(abs_dble(angle_2)) ) * (game->map->width * game->img_size - game->map->pos_x);
			if ((angle_2) > 0)
				game->line->y_dest = game->map->pos_y - len_vision;
			else
				game->line->y_dest = game->map->pos_y + len_vision;
			game->line->x_dest = game->map->width * game->img_size;
		}
		if (game->fov->angle >= 150 && game->fov->angle < 240)
		{
			angle_2 = 180 - angle - (game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs_dble(angle_2))) * (game->map->height * game->img_size - game->map->pos_y);
			if (angle_2 > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			else
				game->line->x_dest = game->map->pos_x - len_vision;
			game->line->y_dest = game->map->height * game->img_size;
		}
		if (game->fov->angle >= 240 && game->fov->angle < 270)
		{
			angle_2 = 270 - angle - (game->fov->deg * i_rotate);
			len_vision = tan(deg_to_radian(abs_dble(angle_2))) * game->map->pos_x;
			if (angle_2 > 0)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = 0;
		}
		game->fov->lines_vision[i_rotate] = draw_line_vision(game, get_color(255, 255 / (game->fov->nbr_ray / 2) * ((game->fov->nbr_ray / 2) - i_rotate), 0));
		game->fov->lines_vision[i_rotate] = abs_flt(cos(deg_to_radian(game->fov->deg * i_rotate))) * game->fov->lines_vision[i_rotate];

		if (game->fov->lines_vision[i_rotate] == 0)
			game->fov->lines_vision[i_rotate] = 1;

		game->fov->wall_witch[i_rotate][0] = game->line->corr_x;
		game->fov->wall_witch[i_rotate][1] = game->line->corr_y;
		game->fov->wall[i_rotate][0] = game->line->corr_x / game->img_size;
		game->fov->wall[i_rotate][1] = game->line->corr_y / game->img_size;
		int corr_y = round(game->line->corr_y);
		int corr_x = round(game->line->corr_x);
		int s = 0;
		int e = 0;
		int w = 0;
		int n = 0;

		if (game->map->map_org[(corr_y - 1) / game->img_size][corr_x / game->img_size] == '1')
			s++;
		if (game->map->map_org[(corr_y + 1) / game->img_size][corr_x / game->img_size] == '1')
			n++;
		if (game->map->map_org[(corr_y) / game->img_size][(corr_x + 1) / game->img_size] == '1')
			w++;
		if (game->map->map_org[(corr_y) / game->img_size][(corr_x - 1) / game->img_size] == '1')
			e++;

		if (n > s)
			game->fov->toggle_vision[i_rotate] = 'N';
		else if (s > n)
			game->fov->toggle_vision[i_rotate] = 'S';
		else if (e > w)
			game->fov->toggle_vision[i_rotate] = 'E';
		else if (w > e)
			game->fov->toggle_vision[i_rotate] = 'W';

		i_rotate++;
	}

	i_rotate = 1;
	if (angle > 180)
		angle = abs_dble(angle - 360);
	while (i_rotate <= game->fov->nbr_ray / 2)
	{
		if (game->fov->angle >= 0 && game->fov->angle < 90)
		{
			len_vision = tan(deg_to_radian(abs_dble(angle - (game->fov->deg * i_rotate)))) * game->map->pos_y;
			if (angle - (game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x + len_vision;
			else
				game->line->x_dest = game->map->pos_x - len_vision;
			game->line->y_dest = 0;
		}
		if (game->fov->angle >= 90 && game->fov->angle < 180)
		{
			len_vision = tan( deg_to_radian(abs_dble(angle - (game->fov->deg * i_rotate) - 90)) ) * (game->map->width * game->img_size - game->map->pos_x);
			if ((angle - (game->fov->deg * i_rotate)) > 90)
				game->line->y_dest = game->map->pos_y + len_vision;
			else
				game->line->y_dest = game->map->pos_y - len_vision;
			game->line->x_dest = game->map->width * game->img_size;
		}
		if (game->fov->angle >= 180 && game->fov->angle < 270)
		{
			len_vision = tan( deg_to_radian(abs_dble(180 - angle - (game->fov->deg * i_rotate))) ) * (game->map->height * game->img_size - game->map->pos_y);
			if (180 - angle - (game->fov->deg * i_rotate) > 0)
				game->line->x_dest = game->map->pos_x - len_vision;
			else
				game->line->x_dest = game->map->pos_x + len_vision;
			game->line->y_dest = game->map->height * game->img_size;
		}
		if (game->fov->angle >= 270 && game->fov->angle < 360)
		{
			len_vision = tan( deg_to_radian(abs_dble(90 - angle - (game->fov->deg * i_rotate))) ) * (game->map->pos_x);
			if (90 - angle - (game->fov->deg * i_rotate) > 0)
				game->line->y_dest = game->map->pos_y - len_vision;
			else
				game->line->y_dest = game->map->pos_y + len_vision;
			game->line->x_dest = 0;
		}
		game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2] = draw_line_vision(game, get_color(0, 255 / (game->fov->nbr_ray / 2) * ((game->fov->nbr_ray / 2) - i_rotate), 255));
		game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2] = abs_flt(cos(deg_to_radian(game->fov->deg * i_rotate))) * game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2];

		if (game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2] == 0)
			game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2] = 1;

		game->fov->wall_witch[i_rotate + game->fov->nbr_ray / 2][0] = game->line->corr_x;
		game->fov->wall[i_rotate + game->fov->nbr_ray / 2][0] = game->line->corr_x / game->img_size;

		game->fov->wall_witch[i_rotate + game->fov->nbr_ray / 2][1] = game->line->corr_y;
		game->fov->wall[i_rotate + game->fov->nbr_ray / 2][1] = game->line->corr_y / game->img_size;

		int corr_y = round(game->line->corr_y);
		int corr_x = round(game->line->corr_x);
		int s = 0;
		int e = 0;
		int w = 0;
		int n = 0;

		if (game->map->map_org[(corr_y - 1) / game->img_size][corr_x / game->img_size] == '1')
			s++;
		if (game->map->map_org[(corr_y + 1) / game->img_size][corr_x / game->img_size] == '1')
			n++;
		if (game->map->map_org[(corr_y) / game->img_size][(corr_x + 1) / game->img_size] == '1')
			w++;
		if (game->map->map_org[(corr_y) / game->img_size][(corr_x - 1) / game->img_size] == '1')
			e++;

		if (n > s)
			game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2] = 'N';
		else if (s > n)
			game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2] = 'S';
		else if (e > w)
			game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2] = 'E';
		else if (w > e)
			game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2] = 'W';
		i_rotate++;
	}
	int	save_src_x;
	int	save_src_y;

	save_src_x = game->line->x_src;
	save_src_y = game->line->y_src;
	game->line->x_dest = save_x;
	game->line->y_dest = save_y;
	last_correct_toggle(game);
	display_3d_up(game);
	display_3d_down(game);
	game->line->x_dest = save_x;
	game->line->y_dest = save_y;
	game->line->x_src = save_src_x;
	game->line->y_src = save_src_y;
	mlx_put_image_to_window(game->mlibx, game->window, game->img->mlx_img, 0, 0);
	printf("\n.....................................\n\n");
	(void)i_rotate;
	(void)save;
	(void)save_2;
	return (SUCCESS);
}

void	last_correct_toggle(t_game *game)
{
	int	w;

	w = -1;
	while (++w < game->fov->nbr_ray)
	{
		if (w > 0 && \
		game->fov->toggle_vision[w] != 'N' && \
		game->fov->toggle_vision[w] != 'E' && \
		game->fov->toggle_vision[w] != 'W' && \
		game->fov->toggle_vision[w] != 'S')
			game->fov->toggle_vision[w] = game->fov->toggle_vision[w - 1];
		else if (w == 0 && \
		game->fov->toggle_vision[w] != 'N' && \
		game->fov->toggle_vision[w] != 'E' && \
		game->fov->toggle_vision[w] != 'W' && \
		game->fov->toggle_vision[w] != 'S')
			game->fov->toggle_vision[w] = game->fov->toggle_vision[w + 1];
	}
}
