/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:15:08 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/01 17:09:42 by ggosse           ###   ########.fr       */
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
	game->map->map_chck = NULL;
	game->map->wall_no = NULL;
	game->map->wall_ea = NULL;
	game->map->wall_so = NULL;
	game->map->wall_we = NULL;
	game->map->ceil = NULL;
	game->map->floor = NULL;
	game->map->h = FAIL;
	game->map->w = FAIL;
	game->map->p_y = FAIL;
	game->map->p_x = FAIL;
	game->map->count_step = FAIL;
	game->map->fd_map = FAIL;
}


int	is_empty_line(char *line)
{
	int	ite_empty;

	ite_empty = 0;
	while (line[ite_empty])
	{
		if ((int)line[ite_empty] != 32 && (int)line[ite_empty] != 9)
			return (FAIL);
		ite_empty++;
	}
	return (SUCCESS);
}

int	check_valid_chr_map(char *line)
{
	int	i_chck_chr;

	i_chck_chr = -1;
	while (line[++i_chck_chr])
	{
		if (line[i_chck_chr] != ' ' && line[i_chck_chr] != '0' \
		&& line[i_chck_chr] != '1' && line[i_chck_chr] != 'W' \
		&& line[i_chck_chr] != 'E' && line[i_chck_chr] != 'N' \
		&& line[i_chck_chr] != 'S')
		{
			if (line[i_chck_chr - 1])
				printf("%i %c\n", line[i_chck_chr - 1], line[i_chck_chr - 1]);
			printf("%i %c\n", line[i_chck_chr], line[i_chck_chr]);
			if (line[i_chck_chr + 1])
				printf("%i %c\n", line[i_chck_chr + 1], line[i_chck_chr + 1]);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

int	end_of_map(t_game *game)
{
	int	i_end_map;

	i_end_map = -1;
	while (game->map->tab_file[++i_end_map])
	{

	}
}

int	tab_len(t_game *game, int ite_start)
{
	int	i_tablen;

	i_tablen = 0;
	while (game->map->tab_file[ite_start])
	{
		i_tablen++;
		ite_start++;
	}
	return (i_tablen);
}

int	malloc_map(t_game *game, int ite_start)
{
	// game->map->map_org = malloc(sizeof(char *) * ft_tablen());
	(void)game;
	(void)ite_start;
	return (SUCCESS);
}

int	build_map(t_game *game, int ite_start)
{
	// int	ite_build_map;

	// ite_build_map = -1;
	malloc_map(game, ite_start);
	while (game->map->tab_file[ite_start])
	{
		if (check_valid_chr_map(game->map->tab_file[ite_start]) == FAIL)
			return (FAIL);
		ite_start++;
	}
	return (SUCCESS);
}

int	ft_parsing(t_game *game, char **argv)
{
	int	ite_each_line;
	int	count;

	count = 0;
	ite_each_line = -1;
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (FAIL);
	init_struct(game);
	if (ft_check_ext(argv[1], 'c', 'u', 'b') == FAIL)
		return (ft_free_parsing(game, "wrong filename extension\n"), FAIL);
	if (ft_read_file(game, argv[1]) == FAIL)
		return (FAIL);
	while (game->map->tab_file[++ite_each_line])
	{
		if (is_empty_line(game->map->tab_file[ite_each_line]) == FAIL && count < 4)
		{
			printf(GREEN"%s"RESET"\n", game->map->tab_file[ite_each_line]);
			if (texture_part(game, game->map->tab_file[ite_each_line]) == FAIL)
				return (FAIL);
			count++;
		}
		else if (is_empty_line(game->map->tab_file[ite_each_line]) == FAIL && count < 6)
		{
			printf(BLUE"%s"RESET"\n", game->map->tab_file[ite_each_line]);
			if (floor_ceil_part(game, game->map->tab_file[ite_each_line]) == FAIL)
				return (FAIL);
			count++;
		}
		else if (is_empty_line(game->map->tab_file[ite_each_line]) == FAIL)
		{
			printf(CYAN"%s"RESET"\n", game->map->tab_file[ite_each_line]);
			if (build_map(game, ite_each_line) == FAIL)
				return (FAIL);
			count++;
		}
		else
			printf(BACK_RED" "RESET"\n");
		// if (floor_ceil_part(game) == FAIL)
		// 	return (FAIL);
		// if (build_map_part(game) == FAIL)
		// 	return (FAIL);
	}
	// if (ft_create_map(game, argv[1]) == FAIL)
	// 	return (FAIL);
	// if (ft_single_player(game) == FAIL)
	// 	return (ft_free_parsing(game, "wrong filename extension\n"), FAIL);
	// if (ft_valid_path(game) == FAIL)
	// 	return (FAIL);
	return (SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	t_game	game;

	if (ft_check_env(envp) == FAIL)
		return (ft_putstr_fd("Error\nyou must have env. variables\n", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Error\nyou must called one arg\n", 2), 1);
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
