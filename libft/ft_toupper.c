/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:53:52 by ggosse            #+#    #+#             */
/*   Updated: 2023/08/06 18:01:09 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int chr)
{
	if ((chr >= 'a') && (chr <= 'z'))
		chr -= 32;
	return (chr);
}

char	*ft_str_to_up(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_str_to_upf(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}
