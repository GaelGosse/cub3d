/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:04:13 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 15:47:18 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_all(t_game *g, int key)
{
	int	len_side;
	int	i_rotate;
	int	len_vision;

	len_vision = 0;
	i_rotate = 0;
	if (init_display_all(g, key, &len_side) == FAIL)
		return (FAIL);
	move_straight(g);
	rotate_new(g);
	mid_display_all(g, i_rotate, len_vision);
	g->display_all_save_src_x = g->line->x_src;
	g->display_all_save_src_y = g->line->y_src;
	g->line->x_dest = g->display_all_save_x;
	g->line->y_dest = g->display_all_save_y;
	last_correct_toggle(g);
	fill_ceil_floor(g);
	display_3d(g);
	g->line->x_dest = g->display_all_save_x;
	g->line->y_dest = g->display_all_save_y;
	g->line->x_src = g->display_all_save_src_x;
	g->line->y_src = g->display_all_save_src_y;
	mlx_put_image_to_window(g->mlibx, g->window, g->img->mlx_img, 0, 0);
	return (SUCCESS);
}

void	mid_display_all(t_game *game, int i_rotate, int len_vision)
{
	game->fov->lines_vision[game->fov->nbr_ray / 2] = draw_line_vision(game);
	game->fov->wall_witch[game->fov->nbr_ray / 2][0] = game->line->corr_x;
	game->fov->wall_witch[game->fov->nbr_ray / 2][1] = game->line->corr_y;
	game->fov->wall[game->fov->nbr_ray / 2][0] \
	= game->line->corr_x / game->img_size;
	game->fov->wall[game->fov->nbr_ray / 2][1] \
	= game->line->corr_y / game->img_size;
	game->display_all_save_x = game->line->x_dest;
	game->display_all_save_y = game->line->y_dest;
	game->display_all_angle = game->fov->angle;
	game->display_all_angle_2 = 0;
	display_all_red(game, i_rotate, len_vision);
	display_all_blue(game, i_rotate, len_vision);
}

void	set_toggle(t_game *g, int i_rotate)
{
	g->map->north = 0;
	g->map->south = 0;
	g->map->east = 0;
	g->map->west = 0;
	if (g->map->map_org[((int)roundf(g->line->corr_y) - 1) / \
	g->img_size][(int)roundf(g->line->corr_x) / g->img_size] == '1')
		g->map->south++;
	if (g->map->map_org[((int)roundf(g->line->corr_y) + 1) / \
	g->img_size][(int)roundf(g->line->corr_x) / g->img_size] == '1')
		g->map->north++;
	if (g->map->map_org[((int)roundf(g->line->corr_y)) / \
	g->img_size][((int)roundf(g->line->corr_x) + 1) / g->img_size] == '1')
		g->map->west++;
	if (g->map->map_org[((int)roundf(g->line->corr_y)) / \
	g->img_size][((int)roundf(g->line->corr_x) - 1) / g->img_size] == '1')
		g->map->east++;
	if (g->map->north > g->map->south)
		g->fov->toggle_vision[i_rotate] = 'N';
	else if (g->map->south > g->map->north)
		g->fov->toggle_vision[i_rotate] = 'S';
	else if (g->map->east > g->map->west)
		g->fov->toggle_vision[i_rotate] = 'E';
	else if (g->map->west > g->map->east)
		g->fov->toggle_vision[i_rotate] = 'W';
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
