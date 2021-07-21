/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:56:26 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 19:00:23 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_data *data)
{
	t_stage	tmp;

	tmp.value = data->stack_a[0].value;
	tmp.index = data->stack_a[0].index;
	tmp.sorted = data->stack_a[0].sorted;
	data->stack_a[0].value = data->stack_a[1].value;
	data->stack_a[0].index = data->stack_a[1].index;
	data->stack_a[0].sorted = data->stack_a[1].sorted;
	data->stack_a[1].value = tmp.value;
	data->stack_a[1].index = tmp.index;
	data->stack_a[1].sorted = tmp.sorted;
	write(1, "sa\n", 3);
	data->inst_count++;
}

void	sb(t_data *data)
{
	t_stage	tmp;

	tmp.value = data->stack_b[0].value;
	tmp.index = data->stack_b[0].index;
	tmp.sorted = data->stack_b[0].sorted;
	data->stack_b[0].value = data->stack_b[1].value;
	data->stack_b[0].index = data->stack_b[1].index;
	data->stack_b[0].sorted = data->stack_b[1].sorted;
	data->stack_b[1].value = tmp.value;
	data->stack_b[1].index = tmp.index;
	data->stack_b[1].sorted = tmp.sorted;
	write(1, "sb\n", 3);
	data->inst_count++;
}

void	ss(t_data *data)
{
	sb(data);
	sa(data);
}
