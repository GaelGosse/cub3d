/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:18:06 by mael              #+#    #+#             */
/*   Updated: 2023/07/08 22:31:14 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


// int	calcul_op_side_for_vison(t_game *game, int i)
// {
// 	int op_side;

// 	op_side = tan(deg_to_radian(2)) * game->fov->lines_vision[i];
// 	return (op_side);
// }

// void	toggle_vision(t_game *game, int op_side)
// {
// 	if (game->fov->toggle == 'N')
// 		{
// 			game->line->x_dest = game->line->x_dest + op_side;
// 			game->line->y_dest = 0;
// 			//if (game->line->x_dest > game->map->width * game->img_size)
// 			// {
// 			// 	printf("entre\n");
// 			// 	game->line->x_dest = game->map->width * game->img_size;
// 			// 	//game->fov->toggle = 'E';
// 			// 	game->line->y_dest = game->line->y_dest + op_side;
// 			// 	printf("y_dest: %i\n", game->line->y_dest);
// 			// }
// 		}
// 		if (game->fov->toggle == 'E')
// 		{
// 			game->line->x_dest = game->map->width * game->img_size;
// 			game->line->y_dest = game->line->y_dest + op_side;
// 			// if (game->line->y_dest > game->map->height * game->img_size)
// 			// {
// 			// 	game->line->y_dest = game->map->height * game->img_size;
// 			// 	game->line->x_dest = game->line->x_dest - op_side;
// 			// 	//game->fov->toggle = 'S';
// 			// }
// 		}
// 		if (game->fov->toggle == 'S')
// 		{
// 			game->line->x_dest = game->line->x_dest - op_side;
// 			game->line->y_dest = game->map->height * game->img_size;
// 			// if (game->line->x_dest < 0)
// 			// {
// 			// 	game->line->x_dest = 0;
// 			// 	game->line->y_dest = game->line->y_dest - op_side;
// 			// 	//game->fov->toggle = 'W';
// 			// }
// 		}
// 		if (game->fov->toggle == 'W')
// 		{
// 			game->line->x_dest = 0;
// 			game->line->y_dest = game->line->y_dest - op_side;
// 			// if (game->line->y_dest < 0)
// 			// {
// 			// 	game->line->y_dest = 0;
// 			// 	game->line->x_dest = game->line->x_dest + op_side;
// 			// 	//game->fov->toggle = 'N';
// 			// 	//toggle_vision(game, op_side);
// 			// }
// 		}
// }

// void	vision(t_game *game, int save, int save_2)
// {
// 	int i;
// 	int op_side;
// 	int x_dest;
// 	int y_dest;

// 	i = 0;
// 	while (i < 15)
// 	{
// 		op_side = calcul_op_side_for_vison(game, i);
// 		toggle_vision(game, op_side);
// 		// printf(BACK_PURPLE"x_dest: %i"RST"\n", x_dest);
// 		// printf(BACK_PURPLE"y_dest: %i"RST"\n", y_dest);
// 		(void)y_dest;
// 		(void)x_dest;
// 		i++;
// 		game->fov->lines_vision[i] = draw_line_vision(game);
// 	}
// 	game->line->x_dest = save;
// 	game->line->y_dest = save_2;
// 	// i = 0;
// 	// while (i < 15)
// 	// {
// 	// 	if (i == 0)
// 	// 		op_side = calcul_op_side_for_vison(game, i);
// 	// 	else
// 	// 		op_side = calcul_op_side_for_vison(game, i + 15);
// 	// 	if (game->fov->toggle == 'N')
// 	// 	{
// 	// 		game->line->x_dest = game->line->x_dest - op_side;
// 	// 		game->line->y_dest = 0;
// 	// 	}
// 	// 	else if (game->fov->toggle == 'S')
// 	// 	{
// 	// 		game->line->x_dest = game->line->x_dest + op_side;
// 	// 		game->line->y_dest = game->map->height * game->img_size;
// 	// 	}
// 	// 	else if (game->fov->toggle == 'E')
// 	// 	{
// 	// 		game->line->x_dest = game->map->width * game->img_size;
// 	// 		game->line->y_dest = game->line->y_dest - op_side;
// 	// 	}
// 	// 	else if (game->fov->toggle == 'W')
// 	// 	{
// 	// 		game->line->x_dest = 0;
// 	// 		game->line->y_dest = game->line->y_dest + op_side;
// 	// 	}
// 	// 	printf(BACK_PURPLE"x_dest: %i"RST"\n", game->line->x_dest);
// 	// 	printf(BACK_PURPLE"y_dest: %i"RST"\n", game->line->y_dest);
// 	// 	printf("\n");
// 	// 	(void)y_dest;
// 	// 	(void)x_dest;
// 	// 	i++;
// 	// 	game->fov->lines_vision[i + 15] = draw_line_vision(game);
// 	// }
// }




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