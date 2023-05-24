/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:06:34 by ggosse            #+#    #+#             */
/*   Updated: 2022/06/14 19:20:21 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while ((first[i] || second[i]) && i < length)
	{
		if (first[i] != second[i])
		{
			return ((unsigned char)(first[i]) - (unsigned char)(second[i]));
		}
		i++;
	}
	return (0);
}
