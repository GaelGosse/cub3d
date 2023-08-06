/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:07:51 by ggosse            #+#    #+#             */
/*   Updated: 2022/06/14 19:17:04 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t			i;
	unsigned char	*new_src;
	unsigned char	*new_dest;

	new_dest = (unsigned char *)destination;
	new_src = (unsigned char *)source;
	i = 0;
	while (i < size)
	{
		new_dest[i] = new_src[i];
		i++;
	}
	return (new_dest);
}
