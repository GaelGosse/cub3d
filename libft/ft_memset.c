/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:02:09 by ggosse            #+#    #+#             */
/*   Updated: 2022/06/14 19:17:25 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void	*str, int value, size_t len)
{
	unsigned char	*p;
	int				i;

	p = str;
	i = 0;
	while (len--)
	{
		*(p + i) = (unsigned char)value;
		i++;
	}
	return (p);
}
