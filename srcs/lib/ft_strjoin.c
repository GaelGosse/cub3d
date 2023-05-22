/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:24:19 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/22 10:59:35 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../incs/cub3.h"

char    *ft_strjoin(char *s1, char *s2)
{
	char                    *str;
	unsigned int    i;
	unsigned int    j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!str)
			return (NULL);
	while (s1[i])
	{
			str[i] = s1[i];
			i++;
	}
	while (s2[j])
	{
			str[i] = s2[j];
			i++;
			j++;
	}
	str[i] = '\0';
	return (str);
}

char    *ft_strjoin_dfree(char *s1, char *s2)
{
	char                    *str;
	unsigned int    i;
	unsigned int    j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!str)
			return (NULL);
	while (s1[i])
	{
			str[i] = s1[i];
			i++;
	}
	while (s2[j])
	{
			str[i] = s2[j];
			i++;
			j++;
	}
	str[i] = '\0';
	return (free(s1), free(s2), str);
}

char    *ft_strjoin_lfree(char *s1, char *s2)
{
	char                    *str;
	unsigned int    i;
	unsigned int    j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!str)
			return (NULL);
	while (s1[i])
	{
			str[i] = s1[i];
			i++;
	}
	while (s2[j])
	{
			str[i] = s2[j];
			i++;
			j++;
	}
	str[i] = '\0';
	return (free(s1), str);
}

char    *ft_strjoin_rfree(char *s1, char *s2)
{
	char                    *str;
	unsigned int    i;
	unsigned int    j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!str)
			return (NULL);
	while (s1[i])
	{
			str[i] = s1[i];
			i++;
	}
	while (s2[j])
	{
			str[i] = s2[j];
			i++;
			j++;
	}
	str[i] = '\0';
	return (free(s2), str);
}