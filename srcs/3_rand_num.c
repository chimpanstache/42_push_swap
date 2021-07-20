/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_rand_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:58:42 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 15:42:42 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void algo_3(t_data *data)
{	
	if (data->stack_a[0].value > data->stack_a[1].value &&
		data->stack_a[1].value < data->stack_a[2].value &&
		data->stack_a[2].value > data->stack_a[0].value)
	{
		sa(data);
	}
	else if (data->stack_a[0].value > data->stack_a[1].value &&
		data->stack_a[1].value > data->stack_a[2].value &&
		data->stack_a[2].value < data->stack_a[0].value)
	{
		sa(data);
		rra(data);
	}
	else if (data->stack_a[0].value > data->stack_a[1].value &&
		data->stack_a[1].value < data->stack_a[2].value &&
		data->stack_a[2].value < data->stack_a[0].value)
	{
		ra(data);
	}
	else if (data->stack_a[0].value < data->stack_a[1].value &&
		data->stack_a[1].value > data->stack_a[2].value &&
		data->stack_a[2].value > data->stack_a[0].value)
	{
		sa(data);
		ra(data);
	}
	else if (data->stack_a[0].value < data->stack_a[1].value &&
		data->stack_a[1].value > data->stack_a[2].value &&
		data->stack_a[2].value < data->stack_a[0].value)
	{
		rra(data);
	}
}

int find_smallest(t_data *data , int ind)
{
	for (int y = 1; y < data->size_a; y++)
	{
		if ( data->stack_a[ind].value > data->stack_a[y].value)
		{
			return ind;
		}
	} 
	return -1;
}

void pb_smallest(t_data *data , int ind)
{
	while (ind > 0)
	{
		ra(data);
		ind--;
	}
	pb(data);
}

void algo_4(t_data *data)
{
	int ind = 0;
	while(ind < data->size_a)
	{
		if (find_smallest(data, ind) == -1) 
			break;
		ind++;
	}
	pb_smallest(data, ind);
	algo_3(data);
	pa(data);
}

void algo_5(t_data *data)
{
	int ind = 0;
	while(ind < data->size_a)
	{
		if (find_smallest(data, ind) == -1) 
			break;
		ind++;
	}
	pb_smallest(data, ind);
	ind = 0;
	while(ind < data->size_a)
	{
		if (find_smallest(data, ind) == -1) 
			break;
		ind++;
	}
	pb_smallest(data, ind);	
	algo_3(data);
	pa(data);
	pa(data);
}