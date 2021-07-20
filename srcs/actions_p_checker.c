/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:56:08 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 19:16:02 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void pa_c(t_data *data)
{
	if (data->size_b == 0)
		return ;

	if (data->size_a > 0)
	{
		for (int i = data->size_a; (i) > 0 ; i--)
		{
			data->stack_a[i].value = data->stack_a[i - 1].value;
			data->stack_a[i].index = data->stack_a[i - 1].index;
			data->stack_a[i].sorted = data->stack_a[i - 1].sorted;
		}
	}

	data->stack_a[0].value = data->stack_b[0].value; 
	data->stack_a[0].index = data->stack_b[0].index; 
	data->stack_a[0].sorted = data->stack_b[0].sorted; 

	if (data->size_b > 0)
	{
		for (int i = 0; (i + 1) < data->size_b; i++)
		{
			data->stack_b[i].value = data->stack_b[i + 1].value;
			data->stack_b[i].sorted = data->stack_b[i + 1].sorted;
			data->stack_b[i].index = data->stack_b[i + 1].index;						
		}
	}
	data->size_b--;
	data->size_a++;

	data->inst_count++;	
}

void pb_c(t_data *data)
{
	if (data->size_a == 0)
		return ;

	if (data->size_b > 0)
	{
		for (int i = data->size_b; (i) > 0 ; i--)
		{
			data->stack_b[i].value = data->stack_b[i - 1].value;
			data->stack_b[i].sorted = data->stack_b[i - 1].sorted;
			data->stack_b[i].index = data->stack_b[i - 1].index;			
		}
	}

	data->stack_b[0].value = data->stack_a[0].value; 
	data->stack_b[0].index = data->stack_a[0].index; 
	data->stack_b[0].sorted = data->stack_a[0].sorted; 
	
	if (data->size_a > 0)
	{
		for (int i = 0; (i + 1) < data->size_a; i++)
		{
			data->stack_a[i].value = data->stack_a[i + 1].value;
			data->stack_a[i].sorted = data->stack_a[i + 1].sorted;
			data->stack_a[i].index = data->stack_a[i + 1].index;						
		}
	}
	data->size_a--;
	data->size_b++;

	data->inst_count++;		
}