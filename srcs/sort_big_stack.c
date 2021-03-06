/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:04:42 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/22 12:37:30 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_big_stack(t_data *data)
{
	int		i;
	int		j;
	t_sort	sort;

	sort.max_num = data->size_a - 1;
	sort.max_bits = 0;
	sort.size = data->size_a;
	while ((sort.max_num >> sort.max_bits) != 0)
		++sort.max_bits;
	i = -1;
	while (++i < sort.max_bits)
	{
		j = -1;
		while (++j < sort.size)
		{
			sort.num = data->stack_a[0].index;
			if (((sort.num >> i) & 1) == 1)
				ra(data);
			else
				pb(data);
		}
		while (data->size_b != 0)
			pa(data);
	}
}
