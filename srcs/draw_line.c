#include "../incs/cub3D.h"

int	absolute_value(int nb)
{
	if (nb == 0)
		return (nb);
	else if (nb < 0)
		nb = nb * (-1);
	return (nb);
}

int	init_line(t_game *game)
{
	game->line = malloc(sizeof(t_line));
	if (!game->line)
		return (printf("Malloc failed\n"), FAIL);
	game->line->dx = 0; //x_dest - x_src
	game->line->dy = 0; //y_dest - y_src
	game->line->steps = 0;
	game->line->xite = 0;
	game->line->yite = 0;
	game->line->corr_x = 0;
	game->line->corr_y = 0;
	game->line->x_src = 0;
	game->line->y_src = 0;
	game->line->x_dest = 0;
	game->line->y_dest = 0;
	return (SUCCESS);
}

// int	put_line_in_img(t_game *game)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (game->tab_img[i])
// 	{
// 		j = 0;
// 		while (game->tab_img[i][j])
// 		{
// 			game->line->x_src = j * game->img_size;
// 			game->line->y_src = i * game->img_size;
// 			game->line->x_dest = (j + 1) * game->img_size;
// 			game->line->y_dest = i * game->img_size;
// 			draw_line(game, i, i);
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (game->tab_img[i])
// 	{
// 		j = 0;
// 		while (game->tab_img[i][j])
// 		{
// 			game->line->x_src = j * game->img_size;
// 			game->line->y_src = i * game->img_size;
// 			game->line->x_dest = j * game->img_size;
// 			game->line->y_dest = (i + 1) * game->img_size;
// 			draw_line(game, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }

int	draw_line_vision(t_game *game, int j)
{
	game->line->dx = game->line->x_dest - game->line->x_src;
	game->line->dy = game->line->y_dest - game->line->y_src;
	// printf("game->line->y_dest: %i\n", game->line->y_dest);
	// printf("game->line->y_src: %i\n", game->line->y_src);

	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);

	game->line->xite = game->line->dx / (float)game->line->steps;
	game->line->yite = game->line->dy / (float)game->line->steps;
	// printf("game->line->dx: %d\n", game->line->dx);
	// printf("(float)game->line->steps: %f\n", (float)game->line->steps);
	// printf("game->line->x_src: %f\n", game->line->x_src);
	// printf("game->line->xite: %f\n", game->line->xite);

	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;

	int i = 0;
	int	toggle = FAIL;
	int y_check = FAIL;
	int	x_check = FAIL;


	while (i <= game->line->steps)
	{
		if (toggle == FAIL && i == 0 && round(game->line->corr_x) > 0 && round(game->line->corr_y) > 0)
			img_pix_put(game, round(game->line->corr_x), round(game->line->corr_y), get_color(255, 0, 0));
		else if (toggle == FAIL && j < 15 && i > 0 && round(game->line->corr_x) > 0 && round(game->line->corr_y) > 0 && game->map->map_org[y_check][x_check] != '1')
			img_pix_put(game, round(game->line->corr_x), round(game->line->corr_y), get_color(0, 255, 255));
		else if (toggle == FAIL && j == 16 && i > 0 && round(game->line->corr_x) > 0 && round(game->line->corr_y) > 0 && game->map->map_org[y_check][x_check] != '1')
			img_pix_put(game, round(game->line->corr_x), round(game->line->corr_y), get_color(255, 0, 255));
		else if (toggle == FAIL && j > 16  && i > 0 && round(game->line->corr_x) > 0 && round(game->line->corr_y) > 0 && game->map->map_org[y_check][x_check] != '1')
			img_pix_put(game, round(game->line->corr_x), round(game->line->corr_y), get_color(0, 255, 0));
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		y_check = (int)(game->line->corr_y / game->img_size);
		x_check = (int)(game->line->corr_x / game->img_size);
		// if (((int)(game->line->corr_y / game->img_size) > game->map->height) ||
		// (int)(game->line->corr_x / game->img_size) > game->map->height)
		// 	break ;
		if (y_check >= 0 && x_check >= 0 && x_check < game->map->width && y_check < game->map->height && game->map->map_org[y_check][x_check] == '1')
			toggle = SUCCESS;
		i++;
	}

	double len;

	// printf("game->line->corr_x: %i\n", game->line->corr_x);
	// printf("game->line->corr_y: %i\n", game->line->corr_y);
	// printf("game->line->x_src: %i\n", game->line->x_src);
	// printf("game->line->>y_src %i\n", game->line->y_src);

	len = sqrt(pow(game->line->corr_x - game->line->x_src, 2) + pow(game->line->corr_y - game->line->y_src, 2));
	//printf("len = %f\n", len);
	return (len);
	//return (absolute_value((int)(game->line->corr_y - game->line->y_src)));
}

