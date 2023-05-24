/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:28:53 by gael              #+#    #+#             */
/*   Updated: 2022/06/14 19:21:16 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		i;
	size_t		j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	result = (char *)malloc(len * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (i < (start + len))
	{
		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
