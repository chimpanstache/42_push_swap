/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:25:08 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/22 12:09:13 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parse_input(char *input)
{
	int	ind;

	ind = 0;
	if (input[ind] != '-' && ft_isdigit(input[ind]) == 0)
		return (-1);
	ind++;
	while (input[ind])
	{
		if (ft_isdigit(input[ind]) == 0)
			return (-1);
		ind++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	int	ind;

	ind = 0;
	if (argc < 2)
		return (-1);
	while (argv[ind])
	{
		if (parse_input(argv[ind]) == -1)
			exit_nice();
		ind++;
	}
	ind = 0;
	while (argv[ind])
	{
		if (ft_atoi_push_swap(argv[ind]) == -1 && ft_strlen(argv[ind]) > 2)
			exit_nice();
		ind++;
	}
	return (0);
}

void	input_strtoint(char **argvs, t_data *data)
{
	int	ind;
	int	i;

	ind = 0;
	while (argvs[ind])
		ind++;
	data->size_a = ind;
	data->size_origin = ind;
	data->size_b = 0;
	data->stack_a = (t_stage *)malloc(sizeof(t_stage) * ind);
	if (!data->stack_a)
		exit_nice();
	data->stack_b = (t_stage *)malloc(sizeof(t_stage) * ind);
	if (!data->stack_b)
		exit_nice();
	i = -1;
	while (++i < ind)
	{
		data->stack_a[i].value = ft_atoi_push_swap(argvs[i]);
		data->stack_a[i].sorted = data->stack_a[i].value;
		data->stack_a[i].index = -1;
	}
}

int	check_doublons(t_data *data)
{
	int	i;
	int	y;

	i = -1;
	while (++i < data->size_a)
	{
		y = -1;
		while (++y < i)
		{
			if (data->stack_a[i].value == data->stack_a[y].value)
			{
				free(data->stack_a);
				free(data->stack_b);
				write(2, "Error\n", 6);
				return (-1);
			}
		}
	}
	return (0);
}

int	arraySortedOrNot(t_data *data)
{
	int	i;

	i = 0;
	while (++i < data->size_a)
	{
		if (data->stack_a[i - 1].value > data->stack_a[i].value)
			return (0);
	}
	return (1);
}
