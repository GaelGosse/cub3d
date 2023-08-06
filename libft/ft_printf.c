/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:56:33 by ggosse            #+#    #+#             */
/*   Updated: 2023/02/05 07:36:46 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

int	ft_int(char chr, int var)
{
	int	i;

	i = 0;
	if (chr == 'c')
		i += ft_putchar_fd(var, 1);
	else if (chr == 'd')
		i += ft_putnbr_fd(var, 1);
	else if (chr == 'i')
		i += ft_putnbr_fd(var, 1);
	else if (chr == '%')
		i += ft_putchar_fd('%', 1);
	return (i);
}

int	ft_uns(char chr, unsigned long long int var)
{
	int	i;

	i = 0;
	if (chr == 'u')
		i += ft_putunbr(var);
	else if (chr == 'x')
		i += ft_putnbr_base_low(var);
	else if (chr == 'X')
		i += ft_putnbr_base_up(var);
	else if (chr == 'p')
		i += ft_putptr(var);
	return (i);
}

int	ft_conv(const char *str, int i, va_list args)
{
	int		len;

	len = 0;
	if (str[i] == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (str[i] == 'c' || str[i] == 'd' || str[i] == 'i')
		len += ft_int(str[i], va_arg(args, int));
	else if (str[i] == '%')
		len += ft_putchar_fd('%', 1);
	else if (str[i] == 'p')
		len += ft_putptr(va_arg(args, unsigned long long int));
	else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
		len += ft_uns(str[i], va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		ptr;

	va_start (ptr, str);
	i = -1;
	len = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_conv(str, i, ptr);
		}
		else
			len += ft_putchar_fd(str[i], 1);
	}
	return (va_end(ptr), len);
}
