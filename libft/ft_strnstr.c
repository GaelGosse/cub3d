/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:05:30 by ggosse            #+#    #+#             */
/*   Updated: 2022/06/15 16:50:25 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;
	char	*conv_big;

	b = 0;
	l = 0;
	conv_big = (char *)big;
	if (ft_strlen(little) == 0)
		return ((char *)conv_big);
	if (little[0] == '\0')
		return (conv_big);
	while (big[b] && b < len)
	{
		l = 0;
		if (big[b] == little[l])
		{
			if (!ft_strncmp(big + b, little + l, ft_strlen(little))
				&& ((b + ft_strlen(little)) <= len))
				return (conv_big + b);
			l++;
		}
		b++;
	}
	return (NULL);
}
