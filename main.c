/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:17:17 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 13:32:59 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi_push_swap(const char *str)
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
    int ind = 1;

    if (argc < 2)
    {
        write(1, "wrong number of arguments\n", 27);
        return (-1);    
    }
    while(argv[ind])
    {
        if (parse_input(argv[ind]) == -1)
        {    
            write(1, "arguments must be int exclusively\n", 35);
            return (-1);
        }
        ind++;
    }
	ind = 0;
    while(argv[ind])
    {
        if (ft_atoi(argv[ind]) == -1 && ft_strlen(argv[ind]) > 2)
        {    
            write(1, "arguments must be INT exclusively\n", 35);
            return (-1);
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
	
	data->size_a = ind; // set ind to what it is
	data->size_origin = ind; // set ind to what it is
	data->size_b = 0; // set ind to what it is
	if (!(data->stack_a = (t_stage*)malloc(sizeof(t_stage) * ind)))
	{
		write(1, "malloc pooped himself\n", 23);
		exit(-1);
	}
	if (!(data->stack_b = (t_stage*)malloc(sizeof(t_stage) * ind)))
	{
		write(1, "malloc pooped himself\n", 23);
		exit(-1);
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
				write(1, "Error\n", 6);
				return -1;
			}
		}	
	}
	return (0);
}

//premier params au sommet de la pile

int main(int argc, char **argv)
{
	t_data data; 

	data.inst_count = 0;
    if (parsing(argc, argv) == -1)
    {
        return (-1);
    }
	input_strtoint(&argv[1], &data);

	if (check_doublons(&data) == -1)
        return (-1);

      
	// printf("\n"); ///////////////////////////////////////	
	selectionSort(&data);
	index_attribution(&data);
	for (int i = 0 ; i < data.size_a ; i++)
	{
		printf("ind[%d]| begin stack a sorted == %d | stack a value == %d\n", data.stack_a[i].index, data.stack_a[i].sorted, data.stack_a[i].value);
	}  
	push_swap(&data);
	printf("\n"); ///////////////////////////////////////
	for (int i = 0 ; i < data.size_a ; i++)
	{
		printf("ind[%d]| final stack a sorted == %d | stack a value == %d\n", data.stack_a[i].index, data.stack_a[i].sorted, data.stack_a[i].value);
	}

	free(data.stack_a);
	free(data.stack_b);	
    return 0;
}
