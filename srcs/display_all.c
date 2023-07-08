/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:04:13 by gael              #+#    #+#             */
/*   Updated: 2023/07/07 19:58:26 by mael             ###   ########.fr       */
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
	game->fov->lines_vision[0] = draw_line_vision(game);
	save = game->line->x_dest;
	save_2 = game->line->y_dest;
	vision(game, save, save_2);
	game->line->x_dest = save;
	game->line->y_dest = save_2;
	mlx_put_image_to_window(game->mlibx, game->window, game->img->mlx_img, 0, 0);
	(void)i_rotate;
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
