/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_rand_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:58:42 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 17:34:59 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	algo_3_2nd_part(t_data *data)
{
	if (data->stack_a[0].value < data->stack_a[1].value
		&& data->stack_a[1].value > data->stack_a[2].value
		&& data->stack_a[2].value > data->stack_a[0].value)
	{
		sa(data);
		ra(data);
	}
	else if (data->stack_a[0].value < data->stack_a[1].value
		&& data->stack_a[1].value > data->stack_a[2].value
		&& data->stack_a[2].value < data->stack_a[0].value)
		rra(data);
}

void	algo_3(t_data *data)
{	
	if (data->stack_a[0].value > data->stack_a[1].value
		&& data->stack_a[1].value < data->stack_a[2].value
		&& data->stack_a[2].value > data->stack_a[0].value)
	{
		sa(data);
		return ;
	}
	else if (data->stack_a[0].value > data->stack_a[1].value
		&& data->stack_a[1].value > data->stack_a[2].value
		&& data->stack_a[2].value < data->stack_a[0].value)
	{
		sa(data);
		rra(data);
		return ;
	}
	else if (data->stack_a[0].value > data->stack_a[1].value
		&& data->stack_a[1].value < data->stack_a[2].value
		&& data->stack_a[2].value < data->stack_a[0].value)
	{
		ra(data);
		return ;
	}
	algo_3_2nd_part(data);
}
