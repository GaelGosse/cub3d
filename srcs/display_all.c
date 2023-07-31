/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:04:13 by gael              #+#    #+#             */
/*   Updated: 2023/07/31 17:31:59 by gael             ###   ########.fr       */
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

	// if (game->fov->toggle == 'E' && game->line->x_dest >= game->map->width * game->img_size)
	// 	set_dest_e(game, key, len_side);
	// else if (game->fov->toggle == 'S' && game->line->y_dest >= game->map->height * game->img_size)
	// 	set_dest_s(game, key, len_side);
	// else if (game->fov->toggle == 'W' && game->line->x_dest <= 0)
	// 	set_dest_w(game, key, len_side);
	// else if (game->fov->toggle == 'N' && game->line->y_dest <= 0)
	// 	set_dest_n(game, key, len_side);
	move_straight(game);
	rotate_new(game);
	printf(BACK_YELLOW"game->fov->toggle: %c"RST"\n", game->fov->toggle);
	printf(YELLOW"(%i, %i)"RST"\n", game->line->x_dest, game->line->y_dest);
	printf(BOLD_YELLOW"game->fov->angle: %i"RST"\n", game->fov->angle);
	printf("\n");
	printf(BLUE"(%i, %i)"RST"\n", game->line->x_dest, game->line->y_dest);
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
		// printf(RED"game->fov->lines_vision[%i]: %i\n"RST, i_rotate, game->fov->lines_vision[i_rotate]);
		if (game->fov->lines_vision[i_rotate] == 0)
			game->fov->lines_vision[i_rotate] = 1;
//		printf(BACK_RED"middle red"RST"\n");
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

		if (n > s)// && (game->fov->toggle != 'N'))//(game->fov->toggle == 'S' || game->fov->toggle == 'W'))
		{
			game->fov->toggle_vision[i_rotate] = 'N';
		}
		else if (s > n) //&& (game->fov->toggle != 'S')) //(game->fov->toggle == 'N' || game->fov->toggle == 'E'))
		{
			game->fov->toggle_vision[i_rotate] = 'S';
		}
		else if (e > w) //&& game->fov->toggle != 'E') //(game->fov->toggle == 'W' || game->fov->toggle == 'N'))
		{
			game->fov->toggle_vision[i_rotate] = 'E';
		}
		else if (w > e) //&&  game->fov->toggle != 'W') //(game->fov->toggle == 'E' || game->fov->toggle == 'S'))
		{
			game->fov->toggle_vision[i_rotate] = 'W';
		}

		// printf(BACK_RED"game->fov->toggle_vision[%i]: %c"RST"\n", i_rotate, game->fov->toggle_vision[i_rotate]);
		i_rotate++;
	}
	// save_x = game->line->x_dest;
	// save_y = game->line->y_dest;
	// printf(BOLD_BLUE"(%i, %i)"RST"\n", game->line->x_dest, game->line->y_dest);


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
		// printf(CYAN"game->fov->lines_vision[%i]: %i\n"RST, i_rotate + game->fov->nbr_ray / 2, game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2]);
		// printf(BACK_PURPLE"game->line->corr_x[%i] / game->img_size: %f"RST"\n\n", i_rotate + game->fov->nbr_ray / 2, round(game->line->corr_x / game->img_size));
		// printf(BACK_PURPLE"game->line->corr_y[%i] / game->img_size: %f"RST"\n\n", i_rotate + game->fov->nbr_ray / 2, round(game->line->corr_y / game->img_size));
		if (game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2] == 0)
			game->fov->lines_vision[i_rotate + game->fov->nbr_ray / 2] = 1;

		game->fov->wall_witch[i_rotate + game->fov->nbr_ray / 2][0] = game->line->corr_x;
		game->fov->wall[i_rotate + game->fov->nbr_ray / 2][0] = game->line->corr_x / game->img_size;
		// printf(BACK_PURPLE"game->fov->wall[%i][0]: %i"RST"\n", i_rotate + game->fov->nbr_ray / 2, game->fov->wall[i_rotate + game->fov->nbr_ray / 2][0]);
		game->fov->wall_witch[i_rotate + game->fov->nbr_ray / 2][1] = game->line->corr_y;
		game->fov->wall[i_rotate + game->fov->nbr_ray / 2][1] = game->line->corr_y / game->img_size;
		// printf(BACK_PURPLE"game->fov->wall[%i][1]: %i"RST"\n\n", i_rotate + game->fov->nbr_ray / 2, game->fov->wall[i_rotate + game->fov->nbr_ray / 2][1]);

			//printf(BACK_RED"middle blue"RST"\n");

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
		// if (i_rotate + game->fov->nbr_ray / 2 == 282)
		// {
		// 	printf(BACK_PURPLE"\t\t\t\t(corr_y - 1) : %i (%i)"RST"\n", (corr_y - 1), (corr_y - 1) / game->img_size);
		// 	printf(BACK_PURPLE"\t\t\t\t(corr_y + 1) : %i (%i)"RST"\n", (corr_y + 1), (corr_y + 1) / game->img_size);
		// 	printf(BACK_PURPLE"\t\t\t\t(corr_x - 1) : %i (%i)"RST"\n", (corr_x - 1), (corr_x - 1) / game->img_size);
		// 	printf(BACK_PURPLE"\t\t\t\t(corr_x + 1) : %i (%i)"RST"\n", (corr_x + 1), (corr_x + 1) / game->img_size);
		// 	printf(BACK_PURPLE"\t\t\t\t %i "RST"\n", n);
		// 	printf(BACK_PURPLE"\t\t\t\t%i %i"RST"\n", w, e);
		// 	printf(BACK_PURPLE"\t\t\t\t %i "RST"\n", s);
		// }

		if (n > s)// && (game->fov->toggle != 'N'))//(game->fov->toggle == 'S' || game->fov->toggle == 'W'))
		{
			game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2] = 'N';
			//printf("%i: Mon toggle est nord\n\n", i_rotate + game->fov->nbr_ray / 2);
		}
		else if (s > n)// && (game->fov->toggle != 'S')) //(game->fov->toggle == 'N' || game->fov->toggle == 'E'))
		{
			game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2] = 'S';
			//printf("%i: Mon toggle est sud\n\n", i_rotate + game->fov->nbr_ray / 2);
		}
		else if (e > w)// && game->fov->toggle != 'E') //(game->fov->toggle == 'W' || game->fov->toggle == 'N'))
		{
			game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2] = 'E';
			//printf("%i: Mon toggle est ESt\n\n", i_rotate + game->fov->nbr_ray / 2);
		}
		else if (w > e)// && game->fov->toggle != 'W') //(game->fov->toggle == 'E' || game->fov->toggle == 'S'))
		{
			game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2] = 'W';
			//printf("%i: Mon toggle est ouest\n\n", i_rotate + game->fov->nbr_ray / 2);
		}
		//printf(BACK_PURPLE"%i a un toggle : %c"RST"\n", i_rotate + game->fov->nbr_ray / 2 , game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2]);
		// if (i_rotate + game->fov->nbr_ray / 2 > 279 && i_rotate + game->fov->nbr_ray / 2 < 286)
		// 	printf(BACK_BLUE"game->fov->toggle_vision[%i] = : %c"RST"\n", i_rotate + game->fov->nbr_ray / 2, game->fov->toggle_vision[i_rotate + game->fov->nbr_ray / 2]);
		i_rotate++;
	}
	int	save_src_x;
	int	save_src_y;

	save_src_x = game->line->x_src;
	save_src_y = game->line->y_src;
	game->line->x_dest = save_x;
	game->line->y_dest = save_y;
	// int i;
	// i = 0;
	// while (game->fov->toggle_vision[i])
	// {
	// 	printf(BACK_PURPLE"game->fov->toggle_vision[%i]: %c"RST"\n", i, game->fov->toggle_vision[i]);
	// 	i++;
	// }
	// print_tab_wall(game);
	fitter_2_blue(game);
	fitter_2_red(game);
	// i = 0;
	// while (game->fov->toggle_vision[i])
	// {
	// 	printf(BACK_YELLOW"game->fov->toggle_vision[%i]: %c"RST"\n", i, game->fov->toggle_vision[i]);
	// 	i++;
	// }
	// int	i = 1;
	// while (is_impur(game) == SUCCESS)
	// {
	// 	i = 1;
	// 	while (i < game->fov->nbr_ray)
	// 	{
	// 		if (game->fov->lines_vision[i] != game->fov->lines_vision[i + 1] &&
	// 		game->fov->lines_vision[i] != game->fov->lines_vision[i - 1] &&
	// 		game->fov->lines_vision[i + 1] == game->fov->lines_vision[i - 1])
	// 			game->fov->lines_vision[i] = game->fov->lines_vision[i - 1];
	// 		if (game->fov->lines_vision[i] != game->fov->lines_vision[i + 2] &&
	// 		game->fov->lines_vision[i] != game->fov->lines_vision[i - 2] &&
	// 		game->fov->lines_vision[i + 2] == game->fov->lines_vision[i - 2])
	// 			game->fov->lines_vision[i] = game->fov->lines_vision[i - 2];
	// 		if (game->fov->lines_vision[i] != game->fov->lines_vision[i + 3] &&
	// 		game->fov->lines_vision[i] != game->fov->lines_vision[i - 3] &&
	// 		game->fov->lines_vision[i + 3] == game->fov->lines_vision[i - 3])
	// 			game->fov->lines_vision[i] = game->fov->lines_vision[i - 3];
	// 		i++;
	// 	}
	// }
	// if (game->fov->lines_vision[0] != game->fov->lines_vision[1])
	// 	game->fov->lines_vision[0] = game->fov->lines_vision[1];
	// i = 0;
	// while (i < game->fov->nbr_ray)
	// {
	// 	printf(BACK_PURPLE"game->fov->lines_vision[%i]: %i"RST"\n", i, game->fov->lines_vision[i]);
	// 	i++;
	// }
	//printf(BACK_RED"end"RST"\n");
	// printf(BACK_BLUE"(%i, %i)"RST"\n", game->line->x_dest, game->line->y_dest);
	display_3d_up(game);
	display_3d_down(game);
	// print_map(game->xpm->so_tab_file);
	game->line->x_dest = save_x;
	game->line->y_dest = save_y;
	game->line->x_src = save_src_x;
	game->line->y_src = save_src_y;
	mlx_put_image_to_window(game->mlibx, game->window, game->img->mlx_img, 0, 0);
	printf("\n.....................................\n\n");
	(void)i_rotate;
	(void)save;
	(void)save_2;
	(void)save_src_x;
	(void)save_src_y;
	return (SUCCESS);
}

int	is_impur(t_game *game)
{
	int	i = 1;
	while (i < game->fov->nbr_ray)
	{
		if (game->fov->lines_vision[i] != game->fov->lines_vision[i + 1] && \
		game->fov->lines_vision[i] != game->fov->lines_vision[i - 1] && \
		game->fov->lines_vision[i + 1] == game->fov->lines_vision[i - 1])
			return (printf(GREEN"success"RST"\n"), SUCCESS);
		if (game->fov->lines_vision[i] != game->fov->lines_vision[i + 2] && \
		game->fov->lines_vision[i] != game->fov->lines_vision[i - 2] && \
		game->fov->lines_vision[i + 2] == game->fov->lines_vision[i - 2])
			return (printf(BOLD_GREEN"success"RST"\n"), SUCCESS);
		if (game->fov->lines_vision[i] != game->fov->lines_vision[i + 3] && \
		game->fov->lines_vision[i] != game->fov->lines_vision[i - 3] && \
		game->fov->lines_vision[i + 3] == game->fov->lines_vision[i - 3])
			return (printf(BACK_GREEN"success"RST"\n"), SUCCESS);
		i++;
	}
	return (printf(BACK_RED"fail"RST"\n"), FAIL);
}

void	set_dest_e(t_game *game, int key, int len_side)
{
	printf(BLUE"(%i, %i)"RST"\n", game->line->x_dest, game->line->y_dest);
	printf(BACK_PURPLE"game->fov->angle: %i"RST"\n", game->fov->angle);
	printf("\n");
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
	printf(BOLD_BLUE"(%i, %i)"RST"\n", game->line->x_dest, game->line->y_dest);
	printf(BACK_PURPLE"game->fov->angle: %i"RST"\n", game->fov->angle);
	printf("\n.....................................\n\n");
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
