/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_so_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:49:54 by gael              #+#    #+#             */
/*   Updated: 2023/07/30 21:48:11 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_so_parse(t_game *game)
{
	printf(BACK_GREEN"%s"RESET"\n", game->map->wall_so);
	xpm_so_read(game, game->map->wall_so);
	xpm_so_correct(game);
	xpm_so_read_1line(game);
	return (SUCCESS);
}

int	xpm_so_split_buf(int fd, t_game *game)
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
	xpm_so_get_content_xpm(game, fd, ret, buf);
	game->xpm->so_tab_file = ft_split(game->xpm->so_file_content, '\n');
	return (SUCCESS);
}

int	xpm_so_read(t_game *game, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (free_parsing(game, "file does not exist\n"), FAIL);
	if (access(filename, F_OK) != 0)
		return (free_parsing(game, \
			"you must use a file to contain the map\n"), FAIL);
	if (xpm_so_split_buf(fd, game) == FAIL)
		return (FAIL);
	if (close(fd) == -1)
		return (free_parsing(game, "close err\n"), FAIL);
	return (SUCCESS);
}

int	xpm_so_get_content_xpm(t_game *game, int fd, int ret, char *buf)
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
		if (!game->xpm->so_file_content)
			game->xpm->so_file_content = ft_strdup(buf);
		else
			game->xpm->so_file_content = \
			ft_strjoin_lfree(game->xpm->so_file_content, buf);
	}
	return (SUCCESS);
}
