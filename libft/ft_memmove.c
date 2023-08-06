/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:08:09 by ggosse            #+#    #+#             */
/*   Updated: 2022/05/30 02:02:33 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dst[n - 1] = src[n - 1];
			n--;
		}
	}
	return (dst);
}
