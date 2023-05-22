/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:24:19 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/22 11:03:19 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3.h"

int	ft_strlen(char *str)
{
	int	ite;

	ite = 0;
	if (!str)
		return (0);
	while (str[ite])
		ite++;
	return (ite);
}

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	res = malloc(sizeof (char) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
