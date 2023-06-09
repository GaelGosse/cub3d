/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:55:47 by gael              #+#    #+#             */
/*   Updated: 2023/06/04 17:16:48 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl(int fd)
{
	char	buf[2];
	int		ret;
	char	*result;

	result = NULL;
	buf[0] = 'X';
	buf[1] = '\0';
	if (fd < 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (printf("Something wrong with args"), NULL);
	while (buf[0] && buf[0] != '\0' && buf[0] != '\n')
	{
		ret = read(fd, buf, 1);
		if (ret < 0)
			return (printf("Something wrong with args"), NULL);
		buf[ret] = '\0';
		buf[1] = '\0';
		if (!result)
			result = ft_strdup(buf);
		else
			result = ft_strjoin_lfree(result, buf);
	}
	return (result);
}
