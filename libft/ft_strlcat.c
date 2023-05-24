/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:06:47 by ggosse            #+#    #+#             */
/*   Updated: 2022/06/14 19:19:53 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i_dst;
	size_t	i_src;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i_src = 0;
	i_dst = dst_len;
	if (dst_len < size - 1 && size > 0)
	{
		while (*(src + i_src) && i_dst < size - 1)
		{
			*(dst + i_dst) = *(src + i_src);
			i_dst++;
			i_src++;
		}
		*(dst + i_dst) = '\0';
	}
	if (dst_len >= size)
		dst_len = size;
	return (dst_len + src_len);
}
