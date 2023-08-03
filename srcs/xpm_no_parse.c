/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_no_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:49:54 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 12:51:06 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xpm_no_parse(t_game *game)
{
	xpm_no_read(game, game->map->wall_no);
	if (xpm_no_correct(game) == FAIL)
		return (FAIL);
	if (xpm_no_read_1line(game) == FAIL)
		return (FAIL);
	if (xpm_no_check_wh(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	xpm_no_split_buf(int fd, t_game *game)
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
	xpm_no_get_content_xpm(game, fd, ret, buf);
	game->xpm->no_tab_file = ft_split(game->xpm->no_file_content, '\n');
	return (SUCCESS);
}

int	xpm_no_read(t_game *game, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (free_parsing(game, "file does not exist\n"), FAIL);
	if (access(filename, F_OK) != 0)
		return (free_parsing(game, \
			"you must use a file to contain the map\n"), FAIL);
	if (xpm_no_split_buf(fd, game) == FAIL)
		return (FAIL);
	if (close(fd) == -1)
		return (free_parsing(game, "close err\n"), FAIL);
	return (SUCCESS);
}

int	xpm_no_get_content_xpm(t_game *game, int fd, int ret, char *buf)
{
	while (buf[0] != '\0')
	{
		ret = read(fd, buf, 1);
		if (ret < 0)
			return (free_parsing(game, "Something wrong with args"), FAIL);
		buf[ret] = '\0';
		buf[1] = '\0';
		if (!game->xpm->no_file_content)
			game->xpm->no_file_content = ft_strdup(buf);
		else
			game->xpm->no_file_content = \
			ft_strjoin_lfree(game->xpm->no_file_content, buf);
	}
	return (SUCCESS);
}
