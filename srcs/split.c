/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:51:58 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 13:53:21 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strndup(const char *str, size_t len)
{
	unsigned int	i;
	char			*copy;

	if (!(copy = malloc(sizeof(*copy) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static size_t	wrdnb(char const *s, char c)
{
	size_t		i;
	size_t		wrdnb;

	i = 0;
	wrdnb = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		wrdnb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wrdnb);
}

static char		**liberate(char **arr, int ind)
{
	int i;

	i = 0;
	while (i < ind)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void free_tmp(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

char			**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	if (!(arr = malloc(sizeof(char*) * (wrdnb(s, c) + 1))))
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = 0;
		if (*s)
		{
			while (s[i] && s[i] != c)
				i++;
			if (!(arr[j++] = ft_strndup(s, i)))
				return (liberate(arr, (int)(j - 1)));
			s += i;
		}
	}
	arr[j] = NULL;
	return (arr);
}
