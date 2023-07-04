#include "../incs/cub3D.h"

int	init_fov(t_game *game)
{
	int i;

	i = 0;
	game->fov = malloc(sizeof(t_fov));
	if (!game->fov)
		return (printf("Init fov failed \n"), FAIL);
	game->fov->lines_vision = malloc(sizeof(int) * 31);
	if (!game->fov->lines_vision)
		return (printf("lines_visions failed\n"), FAIL);
	while (i < 31)
	{
		game->fov->lines_vision[i] = 0;
		i++;
	}
	game->fov->len_first_line = 0;
	game->fov->toggle = game->perso;
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

void	calcul_len_first_line(t_game *game)
{
	if (game->perso == 'N' || game->perso == 'S')
		game->fov->len_first_line = absolute_value((int)(game->line->corr_y - \
			game->map->pos_y));
	else if (game->perso == 'E' || game->perso == 'W')
		game->fov->len_first_line = absolute_value((int)(game->line->corr_x - \
			game->map->pos_x));
}

// int	fill_tab_lines_vision(t_game *game)
// {

// }

int	calcul_opposite_side(t_game *game, int i, double angle)
{
	int	op_side;
	// double angle;

	// angle =
	//	printf("res line len = %d\n", game->fov->len_first_line);
	// if (i == 6 || i == 0)
	// 	op_side = atan(angle) * game->fov->len_first_line;
	// else
	// if (angle > 180)
	// 	angle = absolute_value(360 - angle);

	// op_side = atan(deg_to_radian(angle)) * game->fov->len_first_line;

	if (game->fov->toggle == 'N' && game->line->y_dest == 0) // N
	{
		game->line->y_dest = 0;
		if (angle < 360 && angle > 180)
		{
			op_side = tan(deg_to_radian(360 - angle)) * game->map->pos_y;
			printf("< 360 op_side: %i\n", op_side);
		}
		else
		{
			op_side = tan(deg_to_radian(angle)) * game->map->pos_y;
			printf("> 0 op_side: %i\n", op_side);
		}
	}
	if (game->fov->toggle == 'E' && game->line->x_dest >= game->map->width * game->img_size) // E
	{
		game->line->x_dest = game->map->width * game->img_size;
		op_side = tan(deg_to_radian(absolute_value(90 - angle))) * (game->map->width * game->img_size - game->map->pos_x);
	}
	if (game->fov->toggle == 'S' && game->line->y_dest >= game->map->height * game->img_size) // S
	{
		game->line->y_dest = game->map->height * game->img_size;
		op_side = tan(deg_to_radian(absolute_value(180 - angle))) * (game->map->height * game->img_size - game->map->pos_y);
	}
	if (game->fov->toggle == 'W' && game->line->x_dest <= 0) // W
	{
		game->line->x_dest = 0;
		op_side = tan(deg_to_radian(absolute_value(270 - angle))) * (game->map->pos_x);
	}
	// if (game->line->x_dest >= game->map->width * game->img_size)
	// {
	// 	game->line->x_dest = game->map->width * game->img_size;
	// 	op_side = tan(deg_to_radian(absolute_value(90 - angle))) * (game->map->width * game->img_size - game->map->pos_x);
	// }

	// int ite = 0;
	// while (ite++ < game->map->pos_y)
	// {
	// 	if (ite >= game->map->height * game->img_size)
	// 		break ;
	// 	img_pix_put(game, game->map->pos_x, ite, get_color(255, 0, 0));
	// }
	(void)i;
	//	printf("op_side: %i\n", op_side);
	// printf(" %f\n", sqrt(pow(op_side, 2) + pow(game->fov->len_first_line, 2)));
	return (op_side);
}

int	calcul_move_sw(t_game *game)
{
	int	side;

	side = acos(deg_to_radian(game->fov->angle)) * 5;
	return (side);
 }