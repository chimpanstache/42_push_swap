/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:34:45 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 17:34:54 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_smallest(t_data *data, int ind)
{
	int	y;

	y = 1;
	while (y < data->size_a)
	{
		if (data->stack_a[ind].value > data->stack_a[y].value)
		{
			return (ind);
		}
		y++;
	}
	return (-1);
}

void	pb_smallest(t_data *data, int ind)
{
	int	value_to_be_on_top;

	value_to_be_on_top = data->stack_a[ind].index;
	if (ind > (data->size_origin / 2))
	{
		while (data->stack_a[0].index != value_to_be_on_top)
		{
			rra(data);
		}
	}
	else
	{
		while (data->stack_a[0].index != value_to_be_on_top)
			ra(data);
	}
	pb(data);
}

void	algo_4(t_data *data)
{
	int	ind;

	ind = 0;
	while (ind < data->size_a)
	{
		if (find_smallest(data, ind) == -1)
			break ;
		ind++;
	}
	pb_smallest(data, ind);
	algo_3(data);
	pa(data);
}

void	algo_5(t_data *data)
{
	int	ind;

	ind = 0;
	while (ind < data->size_a)
	{
		if (find_smallest(data, ind) == -1)
			break ;
		ind++;
	}
	pb_smallest(data, ind);
	ind = 0;
	while (ind < data->size_a)
	{
		if (find_smallest(data, ind) == -1)
			break ;
		ind++;
	}
	pb_smallest(data, ind);
	algo_3(data);
	pa(data);
	pa(data);
}
