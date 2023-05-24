/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:28:21 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/24 18:19:17 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_buf_read(int fd, t_game *game)
{
	char	buf[2];
	int		ret;

	buf[0] = 'X';
	buf[1] = '\0';
	if (fd < 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (ft_free_parsing(game, "Something wrong with args"), FAIL);
	while (buf[0] != '\0')
	{
		ret = read(fd, buf, 1);
		if (ret < 0)
			return (ft_free_parsing(game, "Something wrong with args"), FAIL);
		buf[ret] = '\0';
		buf[1] = '\0';
		if (!game->map->file_content)
			game->map->file_content = ft_strdup(buf);
		else
			game->map->file_content = ft_strjoin(game->map->file_content, buf);
	}
	game->map->tab_file = ft_split(game->map->file_content, '\n');
	// free(game->map->file_content);
	// game->map->file_content = NULL;
	return (SUCCESS);
}

int	ft_read_file(t_game *game, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_free_parsing(game, "file does not exist\n"), FAIL);
	if (access(filename, F_OK) != 0)
		return (ft_free_parsing(game, \
			"you must use a file to contain the map\n"), FAIL);
	if (ft_buf_read(fd, game) == FAIL)
		return (FAIL);
	if (close(fd) == -1)
		return (ft_free_parsing(game, "close err\n"), FAIL);
	return (SUCCESS);
}
