/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:38:48 by gael              #+#    #+#             */
/*   Updated: 2023/06/11 14:54:22 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	tab_len(char **arr)
{
	int	i_tablen;

	i_tablen = 0;
	while (arr[i_tablen])
		i_tablen++;
	return (i_tablen);
}

int	create_map(t_game *game, char *line, int fd)
{
	int	i_init_map;

	game->map->height = 0;
	i_init_map = -1;
	while (line && line[0] != '\0' && is_empty_line(line) == SUCCESS)
	{
		free(line);
		line = gnl(fd);
	}
	while (line && line[0] != '\0' && is_empty_line(line) == FAIL)
	{
		if (game->map->file_map == NULL)
			game->map->file_map = ft_strdup(line);
		else
			game->map->file_map = ft_strjoin(game->map->file_map, line);
		free(line);
		line = gnl(fd);
		game->map->height++;
	}
	while (line && line[0] != '\0' && is_empty_line(line) == SUCCESS)
	{
		free(line);
		line = gnl(fd);
	}
	if (line[0] == '\0')
	{
		game->map->map_org = malloc((sizeof (char *)) * (game->map->height + 1));
		while (++i_init_map < game->map->height)
			game->map->map_org[i_init_map] = NULL;
		game->map->map_org = ft_split(game->map->file_map, '\n');
		close(fd);
		return (SUCCESS);
	}
	return (FAIL);
}
/*
int	fill_map(t_game *game, char *line, int fd)
{
	printf("fill map\n");
	int	i_fill;

	i_fill = 0;
	while (line && line[0] != '\0' && is_empty_line(line) == SUCCESS)
	{
		free(line);
		line = gnl(fd);
	}
	while (game->map->map_org[i_fill])
		i_fill++;
	if (i_fill < game->map->height)
	{
		game->map->map_org[i_fill] = line;
		printf(GREEN"game->map->map_org[i_fill]: %s"RESET"\n", game->map->map_org[i_fill]);
		printf(YELLOW"game->map->map_org[i_fill][0]: %i"RESET"\n", game->map->map_org[i_fill][0]);
	}
	(void)game;
	(void)line;
	return (SUCCESS);
}
*/

/*
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

int	end_of_map(t_game *game, int ite_start)
{
	int	i_end_map;

	i_end_map = -1;
	while (game->map->tab_file[ite_start][++i_end_map])
	{
		if (game->map->tab_file[ite_start][i_end_map] != 32 \
		&& game->map->tab_file[ite_start][i_end_map] != 10 \
		&& game->map->tab_file[ite_start][i_end_map] != '\0')
			return (FAIL);
	}
	return (SUCCESS);
}

int	malloc_map(t_game *game, int ite_start)
{
	int	i_build;

	i_build = 0;
	if (game->map->map_org == NULL)
		game->map->map_org = malloc(sizeof(char *) * tab_len(game, ite_start));
	while (game->map->map_org[i_build])
	{
		game->map->map_org = ft_strdup_len(_, _, _);
		i_build++;
	}
	(void)game;
	(void)ite_start;
	return (SUCCESS);
}

int	build_map(t_game *game, int ite_start)
{
	// int	ite_build_map;

	// ite_build_map = -1;
	malloc_map(game, ite_start);
	while (game->map->tab_file[ite_start] && end_of_map(game, ite_start) == FAIL)
	{
		if (check_valid_chr_map(game->map->tab_file[ite_start]) == FAIL)
			return (FAIL);
		ite_start++;
	}
	return (SUCCESS);
}
*/

// int	map_len(t_game *game, int ite_start)
// {
// 	int	len;

// 	len = 0;
// 	while (game->map->tab_file == )
// 	{

// 	}
// 	(void)game;
// 	(void)ite_start;
// 	return (len);
// }

// int	build_map(t_game *game, int ite_start)
// {
// 	if (game->map->map_org == NULL)
// 	{
// 		printf("start\n");
// 		printf("map_len(game, ite_start): %i\n", map_len(game, ite_start));
// 		// game->map->map_org = malloc(sizeof(char *) * ())
// 	}
// 	else
// 	{
// 		printf("already_build\n");
// 	}
// 	(void)game;
// 	(void)ite_start;
// 	return (SUCCESS);
// }
