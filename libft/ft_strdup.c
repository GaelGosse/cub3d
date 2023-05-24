/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:55:59 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/24 23:07:48 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup_len(char *str, int start, int end)
{
	char	*res;
	int		ite_str;
	int		ite_res;

	ite_res = 0;
	ite_str = 0;
	while (str[ite_str])
		ite_str++;
	if (end > ite_str)
		return (NULL);
	res = malloc(sizeof (char) * (end - start + 1));
	if (!res)
		return (NULL);
	ite_str = start;
	while (ite_str < end)
	{
		res[ite_res] = str[ite_str];
		ite_res++;
		ite_str++;
	}
	res[ite_res] = '\0';
	return (res);
}
