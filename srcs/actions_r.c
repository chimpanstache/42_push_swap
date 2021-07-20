/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:56:16 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/19 11:00:18 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ra(t_data *data)
{
	t_stage tmp1;
	
	tmp1.value = data->stack_a[0].value;
	tmp1.index = data->stack_a[0].index;
	tmp1.sorted = data->stack_a[0].sorted;

	int y;
	for (int i = 0; (i + 1) < data->size_a; i++)
	{
		data->stack_a[i].value = data->stack_a[i + 1].value;
		data->stack_a[i].index = data->stack_a[i + 1].index;
		data->stack_a[i].sorted = data->stack_a[i + 1].sorted;
	
		y = i;
	}
	data->stack_a[y + 1].value = tmp1.value;
	data->stack_a[y + 1].index = tmp1.index;	
	data->stack_a[y + 1].sorted = tmp1.sorted;	
	
	data->inst_count++;		
	write(1, "ra\n", 3);
}

void rb(t_data *data)
{
	t_stage tmp1;

	tmp1.value = data->stack_b[0].value;
	tmp1.index = data->stack_b[0].index;
	tmp1.sorted = data->stack_b[0].sorted;	

	int y;
	for (int i = 0; (i + 1) < data->size_b; i++)
	{
		data->stack_b[i].value = data->stack_b[i + 1].value;
		data->stack_b[i].index = data->stack_b[i + 1].index;
		data->stack_b[i].sorted = data->stack_b[i + 1].sorted;
		y = i;
	}
	data->stack_b[y + 1].value = tmp1.value;
	data->stack_b[y + 1].index = tmp1.index;
	data->stack_b[y + 1].sorted = tmp1.sorted;

	data->inst_count++;		
	write(1, "rb\n", 3);	
}

void rr(t_data *data)
{
	ra(data);
	rb(data);	
}
