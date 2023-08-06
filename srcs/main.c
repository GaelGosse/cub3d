/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:15:08 by ggosse            #+#    #+#             */
/*   Updated: 2023/08/03 17:05:43 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	init_struct(t_game *game)
{
	game->img_size = 48;
	game->mlibx = NULL;
	game->window = NULL;
	game->perso = '\0';
	game->map->file_content = NULL;
	game->map->file_map = NULL;
	game->map->tab_file = NULL;
	game->map->map_tmp = NULL;
	game->map->map_org = NULL;
	game->map->wall_no = NULL;
	game->map->wall_ea = NULL;
	game->map->wall_so = NULL;
	game->map->wall_we = NULL;
	game->map->ceil = NULL;
	game->map->floor = NULL;
	game->map->height = FAIL;
	game->map->width = FAIL;
	game->map->pos_y = FAIL;
	game->map->pos_x = FAIL;
	game->map->count_step = FAIL;
	game->map->fd_map = FAIL;
}

int	open_fd(t_game *game, int *fd, char **argv)
{
	(*fd) = open(argv[1], O_RDONLY);
	if ((*fd) == -1)
		return (free_parsing(game, "file does not exist\n"), FAIL);
	if (access(argv[1], F_OK) != 0)
		return (free_parsing(game, \
			"you must use a file to contain the map\n"), FAIL);
	return (SUCCESS);
}

int	ft_parsing(t_game *game, char **argv)
{
	int		count;
	int		fd;

	count = 0;
	fd = -1;
	if (check_ext(argv[1], 'c', 'u', 'b') == FAIL)
		return (free_parsing(game, "wrong filename extension\n"), FAIL);
	if (ft_read_file(game, argv[1]) == FAIL)
		return (FAIL);
	if (build_map(game, argv, count, fd) == FAIL)
		return (FAIL);
	if (xpm_parse(game) == FAIL)
		return (FAIL);
	if (check_letters_map(game) == FAIL)
		return (FAIL);
	if (check_perso(game) == FAIL)
		return (FAIL);
	while (is_propa_finished(game) == FAIL)
	{
		if (flooding(game) == FAIL)
			return (FAIL);
	}
	if (hole_in_wall(game) == FAIL)
		return (FAIL);
	return (check_corner(game), SUCCESS);
}

void	init_main(t_game *game)
{
	game->display_all_save_src_x = 0;
	game->display_all_save_src_y = 0;
	game->display_all_save_x = 0;
	game->display_all_save_y = 0;
	game->display_all_angle = 0;
	game->display_all_angle_2 = 0;
	game->display_all_i_rotate = 0;
	game->flag = 0;
	game->view_angle = 0;
	game->img_size = 0;
	game->perso = '\0';
	game->mlibx = NULL;
	game->window = NULL;
	game->win_height = 0;
	game->win_width = 0;
	game->map = NULL;
	game->img = NULL;
	game->xpm = NULL;
	game->line = NULL;
	game->fov = NULL;
	game->line_3d = NULL;
	game->temp = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_game	game;

	if (check_env(envp) == FAIL)
		return (ft_putstr_fd("Error\nyou must have env. variables\n", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Error\nyou must called one arg\n", 2), 1);
	init_main(&game);
	game.map = malloc(sizeof(t_map));
	if (!game.map)
		return (printf("game map alloc failed\n"), FAIL);
	init_struct(&game);
	if (ft_parsing(&game, argv) == FAIL)
		return (free_all(&game), FAIL);
	if (start_3d(&game) == FAIL)
		return (free_all(&game), FAIL);
	free_all(&game);
	(void)argv;
	(void)envp;
	return (0);
}
