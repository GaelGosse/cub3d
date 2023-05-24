/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_low.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:27:29 by ggosse            #+#    #+#             */
/*   Updated: 2022/07/05 00:13:34 by gael             ###   ########.fr       */
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

	base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar_fd(base[nbr], 1);
	else
	{
		ft_print_base(nbr / 16);
		ft_putchar_fd(base[nbr % 16], 1);
	}
}

int	ft_putnbr_base_low(unsigned long long int nbr)
{
	ft_print_base(nbr);
	return (num_hexa_len(nbr));
}
