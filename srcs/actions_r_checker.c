/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_r_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:56:16 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 19:16:55 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ra_c(t_data *data)
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
}

void rb_c(t_data *data)
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
}

void rr_c(t_data *data)
{
	ra_c(data);
	rb_c(data);	
}
