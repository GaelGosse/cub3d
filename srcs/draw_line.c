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

void	draw_line_vision(t_game *game)
{
	game->line->dx = game->line->x_dest - game->line->x_src;
	game->line->dy = game->line->y_dest - game->line->y_src;

	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);

	game->line->xite = game->line->dx / (float)game->line->steps;
	game->line->yite = game->line->dy / (float)game->line->steps;

	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	
	int i = 0;
	int y_check;
	int	x_check;

	y_check = FAIL;
	x_check = FAIL;
	while (i <= game->line->steps)
	{
		img_pix_put(game, round(game->line->corr_x), round(game->line->corr_y), get_color(255, 255, 0));
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		y_check = (int)(game->line->corr_y / game->img_size);
		x_check = (int)(game->line->corr_x / game->img_size);
		if (game->map->map_org[y_check][x_check] == '1')
			break ;
		i++;
	}
	//return (absolute_value((int)(game->line->corr_y - game->line->y_src)));
}

