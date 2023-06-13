/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:15:08 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/11 22:12:22 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_game *game)
{
	game->img_size = FAIL;
	game->mlibx = NULL;
	game->window = NULL;
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

int	is_empty_line(char *line)
{
	int	i_empty;

	i_empty = 0;
	while (line[i_empty])
	{
		if (line[i_empty] != 32 && line[i_empty] != 9 && line[i_empty] != 10)
			return (FAIL);
		i_empty++;
	}
	return (SUCCESS);
}

int	build_map(t_game *game, char **argv)
{
	int	count;
	int		fd;
	char	*line;

	count = 0;
	fd = -1;
	line = NULL;
	if (ft_check_ext(argv[1], 'c', 'u', 'b') == FAIL)
		return (ft_free_parsing(game, "wrong filename extension\n"), FAIL);
	if (ft_read_file(game, argv[1]) == FAIL)
		return (FAIL);

	fd = open("maps/map2.cub", O_RDONLY);
	if (fd == -1)
		return (ft_free_parsing(game, "file does not exist\n"), FAIL);
	if (access("maps/map2.cub", F_OK) != 0)
		return (ft_free_parsing(game, \
			"you must use a file to contain the map\n"), FAIL);


	line = gnl(fd);
	printf(RED"%s"RESET, line);

	while (line && line[0] != '\0')
	{
		if (is_empty_line(line) == FAIL && count < 4)
		{
			printf(GREEN"%s"RESET"\n", line);
			if (texture_part(game, line) == FAIL)
				return (FAIL);
			count++;
		}
		else if (is_empty_line(line) == FAIL && count < 6)
		{
			printf(BLUE"%s"RESET"\n", line);
			if (floor_ceil_part(game, line) == FAIL)
				return (FAIL);
			count++;
		}
		else if (count >= 6)
		{
			if (game->map->map_org == NULL)
			{
				if (create_map(game, line, fd) < 0)
					return (FAIL);
			}
			count++;
		}
		free(line);
		line = gnl(fd);
	}

	int	abc;

	abc = -1;
	while(game->map->map_org[++abc])
	{
		printf(RED"%s"RESET"\n", game->map->map_org[abc]);
	}

	return (SUCCESS);
}

int	ft_parsing(t_game *game, char **argv)
{
	if (build_map(game, argv) == FAIL)
		return (FAIL);
	if (hole_in_wall(game) == FAIL)
		return (FAIL);
	if (check_perso(game) == FAIL)
		return (FAIL);
	if (check_letters_map(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	t_game	game;

	if (ft_check_env(envp) == FAIL)
		return (ft_putstr_fd("Error\nyou must have env. variables\n", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Error\nyou must called one arg\n", 2), 1);

	game.map = malloc(sizeof(t_map));
	if (!game.map)
		return (FAIL);
	init_struct(&game);
	if (ft_parsing(&game, argv) == FAIL)
		return (1);

	// ft_create_game(&game);
	ft_free_parsing(&game, NULL);
	(void)game;
	(void)argc;
	(void)argv;
	(void)envp;
	return (0);
}
