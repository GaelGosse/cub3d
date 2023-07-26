/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:00:18 by gael              #+#    #+#             */
/*   Updated: 2023/07/25 00:33:13 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// char	*keep_metadata_xpm(char **tmp, char *str, int tab_len_flag)
// {
// 	int		i;
// 	int		end;
// 	char	*line;
// 	int		tab_len_check;

// 	tab_len_check = tab_len(tmp);
// 	if (str[0] != '"')
// 		return (NULL);
// 	printf("here\n");
// 	i = ft_strlen(str) - 1;
// 	if ((str[i] != ',' && str[i - 1] != '"'))// || str[i] != '"')
// 		return (printf("salut\n"),  NULL);
// 	else if (str[i] != '"' && tab_len_flag == tab_len_check)
// 		return (NULL);
// 	end = i - 1;
// 	printf(PURPLE"end: %i"RESET"\n", end);
// 	line = ft_strdup_len(str, 1, end);
// 	return (line);
// }

char	*keep_metadata_xpm(char **tmp, int i_tmp)
{
	int	end;
	int	len_line;

	len_line = ft_strlen(tmp[i_tmp]) - 1;
	end = FAIL;
	if (tmp[i_tmp][len_line] == ',' && tmp[i_tmp][len_line - 1] == '"')
		end = len_line - 1;
	else if (tmp[i_tmp][len_line] == '"')
		end = len_line - 2;
	return (ft_strdup_len(tmp[i_tmp], 1, end));
}
