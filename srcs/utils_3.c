/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:25:08 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/22 12:42:36 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi_push_swap(const char *str)
{
	long	i;
	long	nb;

	i = 0;
	nb = 0;
	while (*str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\t' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i++;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
		if ((nb > (long)INT_MAX && (i % 2 == 0))
			|| (nb > (long)INT_MAX + 1 && (i % 2 != 0)))
			return (-1);
	}
	if (i % 2 != 0)
		nb = -nb;
	return (nb);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;

	s_1 = (unsigned char *)str1;
	s_2 = (unsigned char *)str2;
	while (n > 0 && (*s_1 || *s_2))
	{
		if (*s_1 < *s_2 || *s_1 == '\0')
			return (*s_1 - *s_2);
		if (*s_1 > *s_2 || *s_2 == '\0')
			return (*s_1 - *s_2);
		n--;
		s_1++;
		s_2++;
	}
	return (0);
}

void	exit_nice(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
