/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:52:12 by mael              #+#    #+#             */
/*   Updated: 2023/07/03 14:12:30 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	display_all(t_game *game, char key)
{
	int len_side;
	int i_rotate;

	i_rotate = 0;
	if (init_img(game) == FAIL)
		return (FAIL);
	if (create_image_and_get_adrr(game) == FAIL)
		return (FAIL);
	color_image(game);
	draw_player(game);
	game->line->x_src = game->map->pos_x;
	game->line->y_src = game->map->pos_y;
	// printf("calcul_move_sw(game): %i\n", calcul_move_sw(game));
	// game->line->x_dest = game->map->pos_x;
	// game->line->y_dest = 0;
	// printf("res draw line vison = %d\n" , draw_line_vision(game));
	updt_first_line(game);
	// game->fov->len_first_line = game->map->pos_y;
	len_side = calcul_opposite_side(game, 15, game->fov->angle);
	if (game->line->x_dest >= game->map->width * game->img_size)
	{
		//game->line->x_dest = 0;
		if (key == 'd')
			game->line->y_dest = game->map->pos_y + len_side;
		else if (key == 'a')
			game->line->y_dest = game->map->pos_y - len_side;
		printf("len_side: %i\n", len_side);
		printf("game->line->y_dest: %i\n", game->line->y_dest);
		printf("game->map->pos_y: %i\n", game->map->pos_y);
	}
	else
	{
		if (key == 'd')
			game->line->x_dest = game->map->pos_x + len_side;
		else if (key == 'a')
			game->line->x_dest = game->map->pos_x - len_side;
	}
	// if (game == )
	// {
	//
	// }
	game->fov->lines_vision[15] = draw_line_vision(game);




	// int	ite;

	// cross
	// ite = 0;
	// while (ite++ < 5)
	// 	img_pix_put(game, game->line->x_dest, ite, get_color(255, 0, 0));
	// ite = -6;
	// while (ite++ < 5)
	// 	img_pix_put(game, game->line->x_dest + ite, 0, get_color(255, 0, 0));

	// ite = game->map->pos_x;
	// while (ite++ < game->line->x_dest)
	// {
	// 	if (ite >= game->map->width * game->img_size)
	// 		break ;
	// 	img_pix_put(game, ite, 0, get_color(255, 0, 0));
	// }
	// printf(BOLD_RED"AB: %i\n"RST, game->line->x_dest - game->map->pos_x);
	// printf(YELLOW"draw_line: %i\n"RST, len_side);
	// (void)ite;





	// while (i < 15)
	// {
	// 	if (game->perso == 'N')
	// 	{
	// 		game->line->x_dest = game->line->x_dest + len_side;
	// 		game->line->y_dest = 0;
	// 	}
	// 	else if (game->perso == 'S')
	// 	{
	// 		game->line->x_dest = game->line->x_dest + len_side;
	// 		game->line->y_dest = game->map->height * game->img_size;
	// 	}
	// 	else if (game->perso == 'E')
	// 	{
	// 		game->line->x_dest = game->map->width * game->img_size;
	// 		game->line->y_dest = game->line->y_dest + len_side;
	// 	}
	// 	else if (game->perso == 'W')
	// 	{
	// 		game->line->x_dest = 0;
	// 		game->line->y_dest = game->line->y_dest + len_side;
	// 	}
	// 	game->fov->lines_vision[i] = draw_line_vision(game);
	// 	len_side = calcul_opposite_side(game, i, game->fov->angle);
	// 	i++;
	// }
	// i++;
	// //i = 0;
	// game->line->x_dest = game->map->pos_x;
	// game->line->y_dest = game->map->pos_y;
	// len_side = calcul_opposite_side(game, i, game->fov->angle);
	// while (i < 31)
	// {
	// 	if (game->perso == 'N')
	// 	{
	// 		game->line->x_dest = game->line->x_dest - len_side;
	// 		game->line->y_dest = 0;
	// 	}
	// 	else if (game->perso == 'S')
	// 	{
	// 		game->line->x_dest = game->line->x_dest - len_side;
	// 		game->line->y_dest = game->map->height * game->img_size;
	// 	}
	// 	else if (game->perso == 'E')
	// 	{
	// 		game->line->x_dest = game->map->width * game->img_size;
	// 		game->line->y_dest = game->line->y_dest - len_side;
	// 	}
	// 	else if (game->perso == 'W')
	// 	{
	// 		game->line->x_dest = 0;
	// 		game->line->y_dest = game->line->y_dest - len_side;
	// 	}
	// 	game->fov->lines_vision[i] = draw_line_vision(game);
	// 	len_side = calcul_opposite_side(game, i, game->fov->angle);
	// 	i++;
	// }
	mlx_put_image_to_window(game->mlibx, game->window, game->img->mlx_img, \
		0, 0);
	(void)len_side;
	(void)i_rotate;
	printf("\n.....................................\n\n");
	return (SUCCESS);
}

void	reset_img(t_game *game)
{
	mlx_destroy_image(game->mlibx, game->img->mlx_img);
	free(game->img);
}

int	first_time(t_game *game)
{
	init_line(game);
	set_pos_character(game);
	if (init_img(game) == FAIL)
		return (FAIL);
	if (create_image_and_get_adrr(game) == FAIL)
		return (FAIL);
	color_image(game);
	draw_player(game);
	game->line->x_src = game->map->pos_x;
	game->line->y_src = game->map->pos_y;
	init_fov(game);
	init_position(game);
	calcul_len_first_line(game);
	// draw_line_vision(game);
	// mlx_put_image_to_window(game->mlibx, game->window, game->img->mlx_img,
	// 	0, 0);
	return (SUCCESS);
}


int	start_3D(t_game *game)
{
	game->img_size = 48;
	game->mlibx = mlx_init();
	if (!game->mlibx)
		return (printf("mlx pointer issue\n"), FAIL);
	// game->map->width++;
	game->window = mlx_new_window(game->mlibx, (game->map->width) * game->img_size,
		game->map->height * game->img_size, "cub3D");
	if (!game->window)
		return (printf("Window failed\n"), FAIL);
	if (first_time(game) == FAIL)
		return (FAIL);
	if (display_all(game, '\0') == FAIL)
		return (FAIL);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &ft_destroy_and_free2, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &ft_event_listen, game);
	mlx_loop(game->mlibx);
	return (SUCCESS);
}

void	fill_wall(t_game *game, int i, int j)
{
	int x;
	int y;

	y = i * game->img_size;
	while (y < (i + 1) * game->img_size)
	{
		x = j * game->img_size;
		while (x < (j + 1) * game->img_size)
		{
			img_pix_put(game, x, y, get_color(255, 0, 230));
			x++;
		}
		y++;
	}
}

void	fill_void(t_game *game, int i, int j)
{
	int x;
	int y;

	y = i * game->img_size;
	while (y < (i + 1) * game->img_size)
	{
		x = j * game->img_size;
		while (x < (j + 1) * game->img_size)
		{
			img_pix_put(game, x, y, get_color(5, 15, 120));
			x++;
		}
		y++;
	}
}

void	do_quad(t_game *game, int i, int j)
{
	int y;
	int x;

	y = i * game->img_size;
	while (y < (i + 1) * game->img_size)
	{
		if (y % game->img_size ==  0)
		{
			x = j * game->img_size;
			while (++x < (j + 1) * game->img_size)
				img_pix_put(game, x, y, get_color(255, 255, 255));
		}
		else
		{
			x = j * game->img_size;
			while (x < (j + 1) * game->img_size)
			{
				if (x % game->img_size == 0)
					img_pix_put(game, x, y, get_color(255, 255, 255));
				x++;
			}
		}
		y++;
	}
}

void	color_image(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map->map_org[i])
	{
		j = 0;
		while (game->map->map_org[i][j])
		{
			if (game->map->map_org[i][j] == '1')
			{
				fill_wall(game, i, j);
				do_quad(game, i, j);
			}
			else
			{
				fill_void(game, i, j);
				do_quad(game, i, j);
			}
			j++;
		}
		i++;
	}
}
