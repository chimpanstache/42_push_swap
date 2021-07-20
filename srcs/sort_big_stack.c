/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:04:42 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 15:12:50 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sort_big_stack(t_data *data)
{
	int max_num = data->size_a - 1;

	int max_bits = 0;

	int size = data->size_a;

	while ((max_num >> max_bits) != 0) 
		++max_bits;

	for (int i = 0 ; i < max_bits ; ++i)
	{
		for(int j = 0 ; j < size ; ++j)
		{
			int num = data->stack_a[0].index;
			if ( ((num >> i) & 1) == 1) 
				ra(data); 
			else 
				pb(data);
		}
		while (data->size_b != 0)	 
			pa(data); 
	}	
}