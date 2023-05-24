/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:06:54 by ggosse            #+#    #+#             */
/*   Updated: 2022/06/14 19:19:02 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen((const char *)(str)))
	{
		if (str[i] == (unsigned char)(search))
		{
			return ((char *)(&str[i]));
		}
		i++;
	}
	return (NULL);
}
