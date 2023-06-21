#include "../incs/cub3D.h"

int	init_img(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return (printf("fail to alloc image\n"), FAIL);
	game->img->mlx_img = NULL;
	game->img->addr = NULL;
	game->img->bpp = 0;
	game->img->line_len = 0;
	game->img->endian = 0;
	return (SUCCESS);
}

int	 create_image_and_get_adrr(t_game *game)
{
	game->img->mlx_img = mlx_new_image(game->mlibx, game->map->width * game->img_size, game->map->height * game->img_size);
	if (!game->img->mlx_img)
		return (printf("fail to create image\n"), FAIL);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp, &game->img->line_len, &game->img->endian);
	if (!game->img->addr)
		return (printf("addr failed\n"), FAIL);
	return (SUCCESS);
}
