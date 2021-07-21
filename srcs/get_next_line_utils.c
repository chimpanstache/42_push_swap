/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:37:35 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 19:37:37 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest1 = (char *)dest;
	src1 = (char *)src;
	while (n > 0)
	{
		*dest1 = *src1;
		dest1++;
		src1++;
		n--;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	i = 0;
	if (!s)
	{
		copy = (char *)malloc(sizeof(*copy) * (1));
		if (!copy)
			return (NULL);
		copy[i] = '\0';
		return (copy);
	}
	copy = (char *)malloc(sizeof(*copy) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		s1_l;
	size_t		s2_l;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	arr = malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (!arr)
		return (NULL);
	ft_memcpy(arr, s1, s1_l);
	ft_memcpy(arr + s1_l, s2, s2_l);
	arr[s1_l + s2_l] = '\0';
	free((char *)s1);
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		arr[i] = s[start];
		i++;
		start++;
	}
	arr[i] = '\0';
	free((char *)s);
	return (arr);
}
