/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:20:36 by ggosse            #+#    #+#             */
/*   Updated: 2023/01/03 12:35:54 by ggosse           ###   ########.fr       */
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

char	*ft_itoa(int nbr)
{
	char		*str;
	long int	len;
	long int	sign;
	long int	nb;

	sign = 0;
	len = num_len(nbr);
	nb = nbr;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		sign = 1;
	}
	str[len] = '\0';
	while (--len >= sign)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
