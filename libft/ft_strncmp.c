/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:06:34 by ggosse            #+#    #+#             */
/*   Updated: 2023/07/29 00:25:11 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	// printf(BACK_GREEN"%s"RESET"\n", first);
	// printf(BACK_BLUE"%s"RESET"\n", second);
	while ((first[i] || second[i]) && i < length)
	{
		if (first[i] != second[i])
		{
			// printf(BACK_YELLOW"%c"RESET, first[i]);
			// printf(BACK_YELLOW"\t%i"RESET, first[i]);
			// printf("\n");
			// printf(BACK_YELLOW"%c"RESET, second[i]);
			// printf(BACK_YELLOW"\t%i"RESET, second[i]);
			// printf("\n\n");
			return ((unsigned char)(first[i]) - (unsigned char)(second[i]));
		}
		i++;
	}
	return (0);
}
