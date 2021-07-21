/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_r_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:56:16 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 18:43:41 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra_c(t_data *data)
{
	t_stage	tmp1;
	int		y;
	int		i;

	tmp1.value = data->stack_a[0].value;
	tmp1.index = data->stack_a[0].index;
	tmp1.sorted = data->stack_a[0].sorted;
	i = -1;
	while (((++i) + 1) < data->size_a)
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

void	rb_c(t_data *data)
{
	t_stage	tmp1;
	int		y;
	int		i;

	tmp1.value = data->stack_b[0].value;
	tmp1.index = data->stack_b[0].index;
	tmp1.sorted = data->stack_b[0].sorted;
	i = -1;
	while (((++i) + 1) < data->size_b)
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

void	rr_c(t_data *data)
{
	ra_c(data);
	rb_c(data);
}
