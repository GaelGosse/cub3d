/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:55:01 by mael              #+#    #+#             */
/*   Updated: 2023/07/31 16:20:05 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	deg_to_radian(double deg)
{
	double	rad;

	rad = 0;
	rad = deg * M_PI / 180;
	return (rad);
}

int	hex_to_dec(char *hexa)
{
	char	*base;
	int		i_hex;
	int		i_base;
	int		res;
	int		power;

	power = ft_strlen(hexa) - 1;
	res = 0;
	base = "0123456789abcdef";
	i_base = -1;
	i_hex = -1;
	while (hexa[++i_hex])
	{
		i_base = -1;
		while (base[++i_base])
		{
			if (base[i_base] == ft_tolower(hexa[i_hex]))
				res += i_base * pow(16, power);
		}
		power--;
	}
	free(hexa);
	
	return (res);
}
