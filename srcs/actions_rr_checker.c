/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:56:22 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 18:52:25 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rra_c(t_data *data)
{
	t_stage	tmp1;
	int		i;

	tmp1.value = data->stack_a[(data->size_a - 1)].value;
	tmp1.index = data->stack_a[(data->size_a - 1)].index;
	tmp1.sorted = data->stack_a[(data->size_a - 1)].sorted;
	i = data->size_a;
	while ((--i) > 0)
	{
		data->stack_a[i].value = data->stack_a[i - 1].value;
		data->stack_a[i].index = data->stack_a[i - 1].index;
		data->stack_a[i].sorted = data->stack_a[i - 1].sorted;
	}
	data->stack_a[0].value = tmp1.value;
	data->stack_a[0].index = tmp1.index;
	data->stack_a[0].sorted = tmp1.sorted;
	data->inst_count++;
}

void	rrb_c(t_data *data)
{
	t_stage	tmp1;
	int		i;

	tmp1.value = data->stack_b[(data->size_b - 1)].value;
	tmp1.index = data->stack_b[(data->size_b - 1)].index;
	tmp1.sorted = data->stack_b[(data->size_b - 1)].sorted;
	i = data->size_b;
	while ((--i) > 0)
	{
		data->stack_b[i].value = data->stack_b[i - 1].value;
		data->stack_b[i].index = data->stack_b[i - 1].index;
		data->stack_b[i].sorted = data->stack_b[i - 1].sorted;
	}
	data->stack_b[0].value = tmp1.value;
	data->stack_b[0].index = tmp1.index;
	data->stack_b[0].sorted = tmp1.sorted;
	data->inst_count++;
}

void	rrr_c(t_data *data)
{
	rra_c(data);
	rrb_c(data);
}
