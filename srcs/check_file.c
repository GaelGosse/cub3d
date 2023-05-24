/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:34:36 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/24 18:07:52 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_ext(char *filename)
{
	int	len;

	len = (ft_strlen(filename) - 1);
	if (filename[len] == 'b'
		&& filename[len - 1] == 'u'
		&& filename[len - 2] == 'c'
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
