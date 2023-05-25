/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:34:36 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/25 21:38:32 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_ext(char *filename, char one, char two, char three)
{
	int	len;

	len = (ft_strlen(filename) - 1);
	if (filename[len] == three
		&& filename[len - 1] == two
		&& filename[len - 2] == one
		&& filename[len - 3] == '.')
		return (SUCCESS);
	return (FAIL);
}

int	ft_check_env(char **envp)
{
	int	ite_env;
	int	is_path;

	is_path = 0;
	ite_env = 0;
	while (envp[ite_env])
	{
		if (ft_strncmp(envp[ite_env], "PATH=", 5) == 0)
			is_path++;
		ite_env++;
	}
	if (is_path)
		return (SUCCESS);
	return (FAIL);
}

int	wrong_letter_tx(char *line)
{
	if (line[0] == 'N' && line[0 + 1] == 'O')
		return (SUCCESS);
	if (line[0] == 'E' && line[0 + 1] == 'A')
		return (SUCCESS);
	if (line[0] == 'S' && line[0 + 1] == 'O')
		return (SUCCESS);
	if (line[0] == 'W' && line[0 + 1] == 'E')
		return (SUCCESS);
	return (printf(RED"Err: %c wrong letter for textures \n"RST, \
	line[0]), FAIL);
}
