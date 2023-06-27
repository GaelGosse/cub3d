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
	return (SUCCESS);
}

void	init_position(t_game *game)
{
	if (game->perso == 'S')
	{
		game->line->x_dest = game->map->pos_x;
		game->line->y_dest = game->map->height * game->img_size;
	}
	else if (game->perso == 'W')
	{
		game->line->x_dest = 0;
		game->line->y_dest = game->map->pos_y;
	}
	if (game->perso == 'N')
	{
		game->line->x_dest = game->map->pos_x;
		game->line->y_dest = 0;
	}
	else if (game->perso == 'E')
	{
		game->line->x_dest = game->map->width * game->img_size;
		game->line->y_dest = game->map->pos_y;
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


int	calcul_opposite_side(t_game *game, int i)
{
	int	op_side;
	double angle;

	angle = deg_to_radian(2);
//	printf("res line len = %d\n", game->fov->len_first_line);
	// if (i == 6 || i == 0)
	// 	op_side = atan(angle) * game->fov->len_first_line;
	// else 
	op_side = atan(angle) * game->fov->lines_vision[i];
//	printf("op_side: %i\n", op_side);
	// printf(" %f\n", sqrt(pow(op_side, 2) + pow(game->fov->len_first_line, 2)));
	return (op_side);
}
