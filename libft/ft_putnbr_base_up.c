/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:14:28 by ggosse            #+#    #+#             */
/*   Updated: 2022/07/05 00:13:43 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_hexa_len(long long int nbr)
{
	long int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

static void	ft_print_base(unsigned long long int nbr)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar_fd(base[nbr], 1);
	else
	{
		ft_print_base(nbr / 16);
		ft_putchar_fd(base[nbr % 16], 1);
	}
}

int	ft_putnbr_base_up(unsigned long long int nbr)
{
	ft_print_base(nbr);
	return (num_hexa_len(nbr));
}
