/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:48:06 by ggosse            #+#    #+#             */
/*   Updated: 2023/02/05 18:01:56 by ggosse           ###   ########.fr       */
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

int	ft_putnbr_fd(int nbr, int fd)
{
	int	len;

	len = num_len(nbr);
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (nbr < 0 && nbr != -2147483648)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	return (len);
}
