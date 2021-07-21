/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:17:17 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 20:08:59 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_data *data, int min_idx, int i)
{
	int	temp;

	temp = data->stack_a[min_idx].sorted;
	data->stack_a[min_idx].sorted = data->stack_a[i].sorted;
	data->stack_a[i].sorted = temp;
}

void	selectionSort(t_data *data)
{
	int	i;
	int	j;
	int	min_idx;

	i = -1;
	while (++i < data->size_a - 1)
	{
		min_idx = i;
		j = i;
		while (++j < data->size_a)
		{
			if (data->stack_a[j].sorted < data->stack_a[min_idx].sorted)
				min_idx = j;
		}
		swap(data, min_idx, i);
	}
}

void	index_attribution(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->size_a)
	{
		j = -1;
		while (++j < data->size_a)
		{
			if (data->stack_a[i].value == data->stack_a[j].sorted)
			{
				data->stack_a[i].index = j;
			}
		}	
	}
}
