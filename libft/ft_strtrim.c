/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 08:22:28 by gael              #+#    #+#             */
/*   Updated: 2022/06/14 19:21:02 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char c, const char	*set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}	
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!str)
		return (NULL);
	if (!set)
		return (ft_strdup(str));
	start = 0;
	end = ft_strlen(str) - 1;
	while (ft_isset(str[start], set) && str[start])
		start++;
	if (start == ft_strlen(str))
	{
		res = ft_strdup("");
		if (!(res))
			return (NULL);
		else
			return (res);
	}
	while (ft_isset(str[end], set) && end > 0)
		end--;
	res = ft_substr(str, start, (end + 1) - start);
	return (res);
}
