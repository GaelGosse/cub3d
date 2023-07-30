/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:47:24 by mael              #+#    #+#             */
/*   Updated: 2023/07/28 16:38:14 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	init_fov(t_game *game)
{
	int	i;

	i = 0;
	game->fov = malloc(sizeof(t_fov));
	if (!game->fov)
		return (printf("Init fov failed \n"), FAIL);
	game->fov->nbr_ray = 60 * 5;
	// game->fov->angle_view = 60;
	game->fov->deg = 0.2; //60 / game->fov->nbr_ray;
	// game->fov->proj_plane = (game->win_height / 2) / tan(deg_to_radian(30));
	game->fov->proj_plane = 300;
	game->fov->lines_vision = malloc(sizeof(int) * game->fov->nbr_ray + 1);
	if (!game->fov->lines_vision)
		return (printf("lines_visions failed\n"), FAIL);
	game->fov->toggle_vision = malloc(sizeof(int) * game->fov->nbr_ray + 1);
	if (!game->fov->toggle_vision)
		return (printf("toggle_visions failed\n"), FAIL);
	while (i < game->fov->nbr_ray + 1)
	{
		game->fov->lines_vision[i] = 0;
		game->fov->toggle_vision[i] = 0;
		i++;
	}
	game->fov->toggle = game->perso;
	if (init_fov_wall(game) == FAIL)
		return (FAIL);
	if (init_fov_wall_witch(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	init_fov_wall(t_game *game)
{
	int i;

	i = 0;
	game->fov->wall = malloc(sizeof(int *) * game->fov->nbr_ray);
	if (!game->fov->wall)
		return (printf("init_wall double failed\n"), FAIL);
	while (i <= game->fov->nbr_ray)
	{
		game->fov->wall[i] = malloc(sizeof(int) * 2);
		if (!game->fov->wall[i])
			return (printf("init_wall simple failed\n"), FAIL);
		game->fov->wall[i][0] = FAIL;
		game->fov->wall[i][1] = FAIL;
		i++;
	}
	return (SUCCESS);
}

int	init_fov_wall_witch(t_game *game)
{
	int i;

	i = 0;
	game->fov->wall_witch = malloc(sizeof(double *) * game->fov->nbr_ray);
	if (!game->fov->wall_witch)
		return (printf("init witch double failed\n"), FAIL);
	while (i <= game->fov->nbr_ray)
	{
		game->fov->wall_witch[i] = malloc(sizeof(double) * 2);
		if (!game->fov->wall_witch[i])
			return (printf("init witch simple failed\n"), FAIL);
		game->fov->wall_witch[i][0] = FAIL;
		game->fov->wall_witch[i][1] = FAIL;
		i++;
	}
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

int	first_calcul(t_game *game, double angle)
{
	int	op_side;

	if (game->fov->toggle == 'N' && game->line->y_dest == 0)
	{
		game->line->y_dest = 0;
		if (angle < 360 && angle > 180)
			op_side = tan(deg_to_radian(360 - angle)) * game->map->pos_y;
		else
			op_side = tan(deg_to_radian(angle)) * game->map->pos_y;
	}
	if (game->fov->toggle == 'E' && \
		game->line->x_dest >= game->map->width * game->img_size)
	{
		game->line->x_dest = game->map->width * game->img_size;
		op_side = tan(deg_to_radian(absolute_value(90 - angle))) * \
			(game->map->width * game->img_size - game->map->pos_x);
	}
	return (op_side);
}

int	second_calcul(t_game *game, double angle)
{
	int	op_side;

	if (game->fov->toggle == 'S' && game->line->y_dest >= \
		game->map->height * game->img_size)
	{
		game->line->y_dest = game->map->height * game->img_size;
		op_side = tan(deg_to_radian(absolute_value(180 - angle))) * \
			(game->map->height * game->img_size - game->map->pos_y);
	}
	if (game->fov->toggle == 'W' && game->line->x_dest <= 0)
	{
		game->line->x_dest = 0;
		op_side = tan(deg_to_radian(absolute_value(270 - angle))) * \
			(game->map->pos_x);
	}
	return (op_side);
}

int	calcul_opposite_side(t_game *game, double angle)
{
	int	op_side;

	if (game->fov->toggle == 'N' || game->fov->toggle == 'E')
		op_side = first_calcul(game, angle);
	else if (game->fov->toggle == 'S' || game->fov->toggle == 'W')
		op_side = second_calcul(game, angle);
	return (op_side);
}
