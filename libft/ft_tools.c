/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:14:19 by gael              #+#    #+#             */
/*   Updated: 2023/07/25 08:48:44 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_hexa_len(unsigned long long int nbr)
{
	long int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

void	ft_putptr_hexa(unsigned long long int ptr)
{
	if (ptr >= 16)
	{
		ft_putptr_hexa(ptr / 16);
		ft_putptr_hexa(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
		{
			ft_putchar_fd(ptr - 10 + 'a', 1);
		}
	}
}

int	ft_putptr(unsigned long long int ptr)
{
	int	res;

	res = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putptr_hexa(ptr);
	res = num_hexa_len(ptr) + 2;
	return (res);
}
