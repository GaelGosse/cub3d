/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:10:50 by ggosse            #+#    #+#             */
/*   Updated: 2023/02/05 07:38:35 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long int nbr)
{
	long int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int	ft_putunbr(unsigned long long int nbr)
{
	int	len;

	len = num_len(nbr);
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', 1);
	}
	else
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	return (len);
}
