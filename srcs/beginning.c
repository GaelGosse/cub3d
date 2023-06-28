/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:22:50 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/28 13:03:11 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	line_in_a_first_time(t_game *game, int len_side)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if (game->perso == 'N')
		{
			game->line->x_dest = game->line->x_dest + len_side;
			game->line->y_dest = 0;
		}
		else if (game->perso == 'S')
		{
			game->line->x_dest = game->line->x_dest + len_side;
			game->line->y_dest = game->map->height * game->img_size;
		}
		else if (game->perso == 'E')
		{
			game->line->x_dest = game->map->width * game->img_size;
			game->line->y_dest = game->line->y_dest + len_side;//
		}
		else if (game->perso == 'W')
		{
			game->line->x_dest = 0;
			game->line->y_dest = game->line->y_dest + len_side;
		}
		game->fov->lines_vision[i] = draw_line_vision(game, i);
		len_side = calcul_opposite_side(game, i);
		i++;
	}
	i++;
	//i = 0;
	game->line->x_dest = game->map->pos_x;
	game->line->y_dest = game->map->pos_y;
	len_side = calcul_opposite_side(game, i);
	while (i < 31)
	{
		if (game->perso == 'N')
		{
			game->line->x_dest = game->line->x_dest - len_side;
			game->line->y_dest = 0;
		}
		else if (game->perso == 'S')
		{
			game->line->x_dest = game->line->x_dest - len_side;
			game->line->y_dest = game->map->height * game->img_size;
		}
		else if (game->perso == 'E')
		{
			game->line->x_dest = game->map->width * game->img_size;
			game->line->y_dest = game->line->y_dest - len_side;
		}
		else if (game->perso == 'W')
		{
			game->line->x_dest = 0;
			game->line->y_dest = game->line->y_dest - len_side;
		}
		game->fov->lines_vision[i] = draw_line_vision(game, i);
		len_side = calcul_opposite_side(game, i);
		i++;
	}
	game->flag = 1;
}


void	put_line_during_the_game(t_game *game, int len_side)
{
	int i;

	printf("len_side = %d\n", len_side);
	i = 0;
	while (i < 15)
	{
		if (game->line->y_dest == 0 && game->line->x_dest > 0 && game->line->x_dest < (game->map->width) * game->img_size)
		{
			game->line->x_dest = game->line->x_dest + len_side;
			game->line->y_dest = 0;
		}
		else if ((game->line->y_dest == (game->map->height * game->img_size)) && game->line->x_dest > 0 && game->line->x_dest < (game->map->width) * game->img_size)
		{
			game->line->x_dest = game->line->x_dest + len_side;
			game->line->y_dest = game->map->height * game->img_size;
		}
		else if ((game->line->x_dest = (game->map->width * game->img_size)) && game->line->y_dest > 0 && game->line->y_dest < game->map->height * game->img_size)
		{
			printf("here\n");
			printf("y_dest_first_loop = %d\n", game->line->y_dest);
			game->line->x_dest = game->map->width * game->img_size;
			game->line->y_dest = game->line->y_dest + len_side;//
			printf("y_dest_first_loop = %d\n", game->line->y_dest);
		}
		else if ((game->line->x_dest = 0) && game->line->y_dest > 0 && game->line->y_dest < game->map->height * game->img_size)
		{
			game->line->x_dest = 0;
			game->line->y_dest = game->line->y_dest + len_side;
		}
		game->fov->lines_vision[i] = draw_line_vision(game, i);
		len_side = calcul_opposite_side(game, i);
		i++;
	}
	i++;
	//i = 0;
	game->line->x_dest = game->map->pos_x;
	game->line->y_dest = game->map->pos_y;
	len_side = calcul_opposite_side(game, i);
	while (i < 31)
	{
		if (game->line->y_dest == 0 && game->line->x_dest > 0 && game->line->x_dest < (game->map->width) * game->img_size)
		{
			game->line->x_dest = game->line->x_dest - len_side;
			game->line->y_dest = 0;
		}
		else if (game->line->y_dest == (game->map->height * game->img_size) && game->line->x_dest > 0 && game->line->x_dest < (game->map->width) * game->img_size)
		{
			game->line->x_dest = game->line->x_dest - len_side;
			game->line->y_dest = game->map->height * game->img_size;
		}
		else if ((game->line->x_dest = (game->map->width * game->img_size)) && game->line->y_dest > 0 && game->line->y_dest < game->map->height * game->img_size)
		{
			printf("y_dest_second_loop = %d\n", game->line->y_dest);
			game->line->x_dest = game->map->width * game->img_size;
			game->line->y_dest = game->line->y_dest - len_side;
			printf("y_dest_second_loop = %d\n", game->line->y_dest);
		}
		else if ((game->line->x_dest = 0) && game->line->y_dest > 0 && game->line->y_dest < game->map->height * game->img_size)
		{
			game->line->x_dest = 0;
			game->line->y_dest = game->line->y_dest - len_side;
		}
		game->fov->lines_vision[i] = draw_line_vision(game, i);
		len_side = calcul_opposite_side(game, i);
		i++;
	}
}