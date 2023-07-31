/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:15:08 by ggosse            #+#    #+#             */
/*   Updated: 2023/07/31 17:11:00 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	print_map(char **arr)
{
	int	i_big;
	int	i_lil;

	i_big = -1;
	i_lil = -1;
	while (arr[++i_big])
	{
		i_lil = -1;
		while (arr[i_big][++i_lil])
		{
			// if (arr[i_big][i_lil] == ' ')
			// 	printf(BACK_BLACK"--"RESET);
			// else if (arr[i_big][i_lil] == '0')
			// 	printf(BACK_WHITE"  "RESET);
			// else if (arr[i_big][i_lil] == '1')
			// 	printf(BACK_YELLOW"  "RESET);
			// else if (arr[i_big][i_lil] == 'N' || arr[i_big][i_lil] == 'E'
			// 	|| arr[i_big][i_lil] == 'S' || arr[i_big][i_lil] == 'W')
			// 	printf(BACK_RED"  "RESET);
			printf(BACK_YELLOW"%c"RESET, arr[i_big][i_lil]);
		}
		printf("\n");
	}
	printf(PURPLE"i_big: %i"RESET"\n", i_big);
	printf(PURPLE"i_lil: %i"RESET"\n", i_lil);
}

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
	if (check_ext(argv[1], 'c', 'u', 'b') == FAIL)
		return (free_parsing(game, "wrong filename extension\n"), FAIL);
	if (ft_read_file(game, argv[1]) == FAIL)
		return (FAIL);
	if (build_map(game, argv) == FAIL)
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
	check_corner(game);
	return (SUCCESS);
}

void	init_main(t_game *game)
{
	game->mlibx = NULL;
	game->window = NULL;
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
	if (start_3D(&game) == FAIL)
		return ( FAIL);
	free_all(&game);
	(void)argv;
	(void)envp;
	return (0);
}
