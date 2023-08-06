/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:12:45 by ggosse            #+#    #+#             */
/*   Updated: 2023/08/06 18:01:33 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int chr)
{
	if ((chr >= 'A') && (chr <= 'Z'))
	{
		chr += 32;
	}
	return (chr);
}

char	*ft_str_to_low(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = ft_tolower(str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_str_to_lowf(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = ft_tolower(str[i]);
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}
