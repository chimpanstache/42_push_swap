/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:18:21 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 16:03:53 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void push_swap(t_data *data)
{
	if (data->size_a == 2)
	{
		if (data->stack_a[0].value > data->stack_a[1].value)
			sa(data);
	}
	else if (data->size_a == 3)
	{
		algo_3(data);
	}
	else if (data->size_a == 4)
	{		
		algo_4(data);
	}	
	else if (data->size_a == 5)
	{
		algo_5(data);
	}
	else if (data->size_a <= 500)
	{
		sort_big_stack(data);
	}
}

