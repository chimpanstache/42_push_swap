/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:25:08 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 16:35:02 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi_push_swap(const char *str)
{
	long i;
	long nb;

	i = 0;
	nb = 0;
	while (*str == '\n' || *str == '\v' || *str == '\f' ||
			*str == '\r' || *str == '\t' || *str == ' ')
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
		if ((nb > (long)INT_MAX && (i % 2 == 0)) || (nb > (long)INT_MAX + 1 && (i % 2 != 0)))
		{	
			return -1;
		}

	}
	if (i % 2 != 0)
		nb = -nb;
	return (nb);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int		ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char *s_1;
	unsigned char *s_2;

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

int parse_input(char *input)
{
    int ind = 0;
    
    if (input[ind] != '-' && ft_isdigit(input[ind]) == 0)
    {
        return (-1);
    }

    ind++;
    while(input[ind])
    {
        if (ft_isdigit(input[ind]) == 0)
        {
			return (-1);
        } 
		ind++;       
    }

    return (0);
}

int parsing(int argc, char **argv)
{
    int ind = 0;

    if (argc < 2)
    {
        return (-1);    
    }
    while(argv[ind])
    {
     	if (parse_input(argv[ind]) == -1)
        {    
           	write(2, "Error\n", 6);
			            exit(EXIT_FAILURE);   
        }
        ind++;
    }
	ind = 0;
    while(argv[ind])
    {
		if (ft_atoi_push_swap(argv[ind]) == -1 && ft_strlen(argv[ind]) > 2)
        {    
			   write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        ind++;
    }	
    return (0);
}

void input_strtoint(char **argvs, t_data *data)
{
	int ind = 0;

	while (argvs[ind])
		ind++;
	
	data->size_a = ind; 
	data->size_origin = ind; 
	data->size_b = 0; 
	if (!(data->stack_a = (t_stage*)malloc(sizeof(t_stage) * ind)))
	{
		write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
	}
	if (!(data->stack_b = (t_stage*)malloc(sizeof(t_stage) * ind)))
	{
		write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
	}
	for (int i = 0; i < ind ; i++)
	{
		data->stack_a[i].value = ft_atoi_push_swap(argvs[i]);
		data->stack_a[i].sorted = data->stack_a[i].value;
		data->stack_a[i].index = -1;
	}
}

int check_doublons(t_data *data)
{
	for (int i = 0; i < data->size_a ; i++)
	{
		for (int y = 0; y < i ; y++)
		{
			if (data->stack_a[i].value == data->stack_a[y].value)
			{	
				free(data->stack_a);
				free(data->stack_b);				
				write(2, "Error\n", 6);
				return -1;
			}
		}	
	}
	return (0);
}

int arraySortedOrNot(t_data *data)
{
    for (int i = 1; i < data->size_a; i++)
    {
	    if (data->stack_a[i - 1].value > data->stack_a[i].value)
            return 0;
	}
    return 1;
}

int		just_digit_and_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((ft_isdigit(str[i]) == 0) && str[i] != ' ' && str[i] != '-')
			return (0);
	}
	return (1);
}
