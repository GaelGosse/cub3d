/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:15:08 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/09 16:19:35 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_game *game)
{
	game->img_size = FAIL;
	game->mlibx = NULL;
	game->window = NULL;
	game->map->file_content = NULL;
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

// void	copy_arr(char ***arr_src, char ***arr_dest)
// {
// 	int	i_src;

// 	i_src = 0;
// 	while ((*arr_src[i_src]))
// 	{
// 		(*arr_src[i_src]) = (*arr_dest[i_src]);
// 		i_src++;
// 	}
// }

void	copy_arr(t_game *game, char *line)
{
	int	i_src;

	i_src = 0;
	while (game->map->map_org[i_src])
	{
		game->map->map_tmp[i_src] = game->map->map_org[i_src];
		i_src++;
	}
	game->map->map_tmp[i_src] = ft_strdup(line);
	game->map->map_tmp[i_src + 1] = NULL;
	i_src = 0;
	// ft_free_tab_str(game->map->map_org);
	while (game->map->map_tmp[i_src])
	{
		game->map->map_org[i_src] = game->map->map_tmp[i_src];
		i_src++;
	}
}


int	ft_parsing(t_game *game, char **argv)
{
	int	count;
	int		fd;
	char	*line;
	// int	ite_each_line;

	count = 0;
	fd = -1;
	line = NULL;
	// ite_each_line = -1;
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
				while (line && line[0] != '\0' && is_empty_line(line) == SUCCESS)
				{
					free(line);
					line = gnl(fd);
				}
				game->map->map_org = (char **)malloc((sizeof(char *) * 2));
				game->map->map_org[0] = ft_strdup(line);
				game->map->map_org[1] = NULL;
				game->map->height = 1;
			}
			else if (is_empty_line(line) == FAIL)
			{
				if (game->map->map_tmp != NULL)
					free(game->map->map_tmp);
				game->map->map_tmp = malloc(sizeof(char *) * (tab_len(game->map->map_org) + 2));
				// copy_arr((&game->map->map_org), (&game->map->map_tmp));
				copy_arr(game, line);
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


	if (close(fd) == -1)
		return (ft_free_parsing(game, "close err\n"), FAIL);



	// while (game->map->tab_file[++ite_each_line])
	// {
	// 	if (is_empty_line(game->map->tab_file[ite_each_line]) == FAIL && count < 4)
	// 	{
	// 		printf(GREEN"%s"RESET"\n", game->map->tab_file[ite_each_line]);
	// 		if (texture_part(game, game->map->tab_file[ite_each_line]) == FAIL)
	// 			return (FAIL);
	// 		count++;
	// 	}
	// 	else if (is_empty_line(game->map->tab_file[ite_each_line]) == FAIL && count < 6)
	// 	{
	// 		printf(BLUE"%s"RESET"\n", game->map->tab_file[ite_each_line]);
	// 		if (floor_ceil_part(game, game->map->tab_file[ite_each_line]) == FAIL)
	// 			return (FAIL);
	// 		count++;
	// 	}
	// 	else if (is_empty_line(game->map->tab_file[ite_each_line]) == FAIL)
	// 	{
	// 		// printf(CYAN"%s"RESET"\n", game->map->tab_file[ite_each_line]);
	// 		if (build_map(game, ite_each_line) == FAIL)
	// 			return (FAIL);
	// 		count++;
	// 	}
	// 	else
	// 		printf(BACK_RED" "RESET"\n");
	// 	// if (floor_ceil_part(game) == FAIL)
	// 	// 	return (FAIL);
	// 	// if (build_map_part(game) == FAIL)
	// 	// 	return (FAIL);
	// }
	// if (ft_create_map(game, argv[1]) == FAIL)
	// 	return (FAIL);
	// if (ft_single_player(game) == FAIL)
	// 	return (ft_free_parsing(game, "wrong filename extension\n"), FAIL);
	// if (ft_valid_path(game) == FAIL)
	// 	return (FAIL);
	printf("\n");
	printf("------------------------------\n");
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
