/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:38:48 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 13:38:47 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	skip_empty_line(char **line, int fd)
{
	while ((*line) && (*line)[0] != '\0' && is_empty_line((*line)) == SUCCESS)
	{
		free((*line));
		(*line) = gnl(fd);
	}
}

void	build_content(t_game *game, char **line, int fd)
{
	if (game->map->file_map == NULL)
		game->map->file_map = ft_strdup((*line));
	else
		game->map->file_map = ft_strjoin_lfree(game->map->file_map, (*line));
	free(*line);
	(*line) = NULL;
	(*line) = gnl(fd);
	game->map->height++;
}

void	realloc_lines(t_game *game)
{
	int		i_realloc;
	int		len;
	char	*str_tmp;

	i_realloc = -1;
	len = 0;
	str_tmp = NULL;
	while (game->map->map_org[++i_realloc])
	{
		len = ft_strlen(game->map->map_org[i_realloc]);
		if (len < (int)game->map->width)
		{
			str_tmp = ft_strdup(game->map->map_org[i_realloc]);
			free(game->map->map_org[i_realloc]);
			free(game->map->map_tmp[i_realloc]);
			game->map->map_org[i_realloc] = \
			ft_strdup_pad(str_tmp, game->map->width, ' ');
			game->map->map_tmp[i_realloc] = \
			ft_strdup_pad(str_tmp, game->map->width, ' ');
			free(str_tmp);
		}
	}
}

int	create_map(t_game *game, char *line, int fd)
{
	if (game->map->ceil == NULL || game->map->floor == NULL)
		return (printf("wrong ceil floor\n"), FAIL);
	game->map->height = 0;
	skip_empty_line(&line, fd);
	while (line && line[0] != '\0' && is_empty_line(line) == FAIL)
		build_content(game, &line, fd);
	skip_empty_line(&line, fd);
	if (line && line[0] == '\0')
	{
		game->map->map_org = ft_split(game->map->file_map, '\n');
		game->map->map_tmp = ft_split(game->map->file_map, '\n');
		free(game->map->file_map);
		game->map->file_map = NULL;
		set_width(game);
		realloc_lines(game);
		free(line);
		return (close(fd), SUCCESS);
	}
	free(game->map->file_map);
	game->map->file_map = NULL;
	free(line);
	line = NULL;
	return (printf("something wrong with map\n"), FAIL);
}

int	build_map(t_game *game, char **argv, int count, int fd)
{
	char	*line;

	if (open_fd(game, &fd, argv) == FAIL)
		return (FAIL);
	line = gnl(fd);
	while (line && line[0] != '\0')
	{
		if (is_empty_line(line) == FAIL && count < 4)
		{
			if (texture_part(game, line) == FAIL)
				return (free(line), FAIL);
			count++;
		}
		else if (is_empty_line(line) == FAIL && count < 6)
		{
			if (floor_ceil_part(game, line) == FAIL)
				return (free(line), FAIL);
			count++;
		}
		else if (count >= 6 && game->map->map_org == NULL)
			return (create_map(game, line, fd));
		free(line);
		line = gnl(fd);
	}
	return (SUCCESS);
}
