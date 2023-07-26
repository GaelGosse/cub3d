/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:49:54 by gael              #+#    #+#             */
/*   Updated: 2023/07/25 16:39:22 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_parse(t_game *game)
{
	printf(BACK_GREEN"%s"RESET"\n", game->map->wall_no);
	read_xpm(game, "sprites/exit.xpm");
	xpm_correct(game);
	read_first_line_xpm(game);
	return (SUCCESS);
}

int	buf_split_xpm(int fd, t_game *game)
{
	char	buf[2];
	int		ret;

	buf[0] = 'X';
	buf[1] = '\0';
	if (fd < 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (free_parsing(game, "Something wrong with args"), FAIL);
	while (buf[0] != '\0')
	{
		ret = read(fd, buf, 1);
		if (ret < 0)
			return (free_parsing(game, "Something wrong with args"), FAIL);
		buf[ret] = '\0';
		buf[1] = '\0';
		if (buf[0] == '{')
			break ;
	}
	get_content_xpm(game, fd, ret, buf);
	game->xpm->tab_file = ft_split(game->xpm->file_content, '\n');
	return (SUCCESS);
}

int	init_xpm(t_game *game)
{
	game->xpm = malloc(sizeof(t_xpm));
	if (!game->xpm)
		return (printf("Init fov failed \n"), FAIL);
	game->xpm->file_content = NULL;
	game->xpm->file_map = NULL;
	game->xpm->tab_file = NULL;
	game->xpm->tab_start = 0;
	return (SUCCESS);
}

int	read_xpm(t_game *game, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (free_parsing(game, "file does not exist\n"), FAIL);
	if (access(filename, F_OK) != 0)
		return (free_parsing(game, \
			"you must use a file to contain the map\n"), FAIL);
	if (init_xpm(game) == FAIL)
		return (FAIL);
	if (buf_split_xpm(fd, game) == FAIL)
		return (FAIL);
	if (close(fd) == -1)
		return (free_parsing(game, "close err\n"), FAIL);
	return (SUCCESS);
}

int	get_content_xpm(t_game *game, int fd, int ret, char *buf)
{
	while (buf[0] != '\0')
	{
		ret = read(fd, buf, 1);
		if (ret < 0)
			return (free_parsing(game, "Something wrong with args"), FAIL);
		buf[ret] = '\0';
		buf[1] = '\0';
		if (buf[0] == '}')
			break ;
		if (!game->xpm->file_content)
			game->xpm->file_content = ft_strdup(buf);
		else
			game->xpm->file_content = \
			ft_strjoin_lfree(game->xpm->file_content, buf);
	}
	return (SUCCESS);
}
