/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:34:36 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/21 19:40:24 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3.h"

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