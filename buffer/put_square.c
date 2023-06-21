#include "../incs/cub3D.h"

void	set_pos_character(t_game *game)
{
	int y;
	int	x;

	y = 0;
	while (game->tab_img[y])
	{
		x = 0;
		while (game->tab_img[y][x])
		{
			if (game->map->map_org[y][x] == 'W' || game->map->map_org[y][x] == 'E'
				|| game->map->map_org[y][x] == 'N' || game->map->map_org[y][x] == 'S')
			{
				printf("x = %d\n", x);
				printf("y = %d\n", y);
				game->map->pos_x = (x * game->img_size) + (game->img_size / 2);
				printf("game->map->pos_x = %d\n", game->map->pos_x);
				game->map->pos_y = (y * game->img_size) + (game->img_size / 2);
				printf("game->map->pos_y = %d\n", game->map->pos_y);
			}
			x++;
		}
		y++;
	}
}

// // void	put_square(t_game *game)
// // {
// // 	int i;
// // 	int j;
// // 	int x;
// // 	int y;

// // 	i = 0;
// // 	while (game->tab_img[i])
// // 	{
// // 		j = 0;
// // 		// if (i == floor(game->map->pos_x / game->img_size))
// // 		// 	printf(GREEN"i = %d\n"RST, i);
// // 		// else if (i > 12)
// // 		// {
// // 		// 	printf(RED"i = %d\n"RST, i);
// // 		// 	printf(RED"game->map->pos_x: %i\n"RST, game->map->pos_x);
// // 		// 	printf(RED"floor(game->map->pos_x / game->img_size): %f\n"RST, floor(game->map->pos_x / game->img_size));
// // 		// }
// // 		while (game->tab_img[i][j])
// // 		{
// // 			if (i == floor(game->map->pos_x / game->img_size) && j == floor((game->map->pos_y / game->img_size)))
// // 			{
// // 				// printf("here\n");
// // 				y = game->map->pos_y - 5;
// // 				while (y < game->map->pos_y + 5)
// // 				{
// // 					x = game->map->pos_x - 5;
// // 					while (x < game->map->pos_x + 5)
// // 					{
// // 						img_pix_put(game, x % game->img_size, y % game->img_size, get_color(0, 255, 0), j, i);
// // 						x++;
// // 					}
// // 					y++;
// // 				}
// // 			}
// // 			j++;
// // 		}
// // 		i++;
// // 	}
// // 	// 	i = 0;
// // 	// while (game->tab_img[i])
// // 	// {
// // 	// 	j = 0;
// // 	// 	while (game->tab_img[i][j])
// // 	// 	{
// // 	// 		if (game->map->map_org[i][j] == '1')
// // 	// 			printf(BACK_RED"%c"RST, game->map->map_org[i][j]);
// // 	// 		else if (game->map->map_org[i][j] == '0' || game->map->map_org[i][j] == 'N'
// // 	// 			|| game->map->map_org[i][j] == 'S' || game->map->map_org[i][j] == 'W' 
// // 	// 			|| game->map->map_org[i][j] == 'E')
// // 	// 			printf(BACK_BLUE"%c"RST, game->map->map_org[i][j]);
// // 	// 		else
// // 	// 			printf(BACK_WHITE"%c"RST, game->map->map_org[i][j]);
// // 	// 		j++;
// // 	// 	}
// // 	// 	printf("\n");
// // 	// 	i++;
// // 	// }
// // 	printf("\n");

// // }


// void	put_sqr(t_game *game, int color, int i, int j)
// {
// 	int x;
// 	int y;

// 	y = game->map->pos_y - 5;
// 	while (y < game->map->pos_y + 5)
// 	{
// 		x = game->map->pos_x - 5;
// 		while (x < game->map->pos_x + 5)
// 		{
// 			// printf("%i / %i\n", x, y);
// 			img_pix_put(game, x, y, color, i, j);
// 			x++;
// 		}
// 		// printf("\n");
// 		y++;
// 	}
// 	img_pix_put(game, game->map->pos_x, game->map->pos_y, color, i, j);
// }

// void	put_square(t_game *game)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	while (game->tab_img[i])
// 	{
// 		j = 0;
// 		while (game->tab_img[i][j])
// 		{
// 			if (i == floor(game->map->pos_y / game->img_size) && j == floor((game->map->pos_x / game->img_size)))
// 			{
// 				// printf("salut\n");
// 				put_sqr(game, get_color(0, 255, 0), i, j);
// 				printf(BACK_GREEN"%c"RST, game->map->map_org[i][j]);
// 			}
// 			else
// 				printf(BACK_YELLOW"%c"RST, game->map->map_org[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	// printf("i = %d\n", i);
// 	// printf("j = %d\n", j);
// }


void	img_pix_put_2(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = game->square->addr + (y * game->square->line_len + x * (game->square->bpp / 8));
	*(int *)pixel = color;
}

int	init_square(t_game *game)
{
	game->square = malloc(sizeof(t_img));
	if (!game->square)
		return (FAIL);
	game->square->mlx_img = NULL;
	game->square->addr = NULL;
	game->square->bpp = 0;
	game->square->line_len = 0;
	game->square->endian = 0;
	return (SUCCESS);
}

int	create_square(t_game *game)
{
	// if (init_square(game) == FAIL)
	// 	return (FAIL);
	game->square->mlx_img = mlx_new_image(game->mlibx, 10, 10);
	if (!game->square->mlx_img)
		return (printf("creating image square fail"), FAIL);
	game->square->addr = mlx_get_data_addr(game->square->mlx_img, 
	&game->square->bpp, &game->square->line_len, &game->square->endian);
	return (SUCCESS);
}

int	draw_square(t_game *game)
{
	int	y;
	int	x;

	// if (create_square(game) == FAIL)
	// 	return (FAIL);
	y = 0;
	while (y < game->img_size)
	{
		x = 0;
		while (x < game->img_size)
		{
			img_pix_put_2(game, x, y, get_color(1, 255, 1));
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	put_square_in_window(t_game *game)
{
	int x;
	int y;
	
	// if (draw_square(game) == FAIL)
	// 	return (FAIL);
	y = 0;
	while (game->tab_img[y])
	{
		x = 0;
		while (game->tab_img[y][x])
		{
			// if (game->map->map_org[y][x] == 'S' || game->map->map_org[y][x] == 'N' 
			// || game->map->map_org[y][x] == 'E' || game->map->map_org[y][x] == 'W')
			// {
			// 	mlx_put_image_to_window((game->mlibx), (game->window),
			// 		game->square->mlx_img, game->map->pos_x, game->map->pos_y);
			// }
			if (y == floor(game->map->pos_y / game->img_size) && x == floor((game->map->pos_x / game->img_size)))
			{
				mlx_put_image_to_window((game->mlibx), (game->window),
					game->square->mlx_img, game->map->pos_x, game->map->pos_y);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}