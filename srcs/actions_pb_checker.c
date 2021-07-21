/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:56:08 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 18:18:23 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_data_pb(t_data *data)
{
	data->stack_b[0].value = data->stack_a[0].value;
	data->stack_b[0].index = data->stack_a[0].index;
	data->stack_b[0].sorted = data->stack_a[0].sorted;
}

void	set_size_pb(t_data *data)
{
	data->size_a--;
	data->size_b++;
}

void	pb_c_doing(t_data *data)
{
	int	i;

	if (data->size_b > 0)
	{
		i = data->size_b + 1;
		while ((--i) > 0)
		{
			data->stack_b[i].value = data->stack_b[i - 1].value;
			data->stack_b[i].sorted = data->stack_b[i - 1].sorted;
			data->stack_b[i].index = data->stack_b[i - 1].index;
		}
	}
	set_data_pb(data);
	if (data->size_a > 0)
	{
		i = -1;
		while ((++i) + 1 < data->size_a)
		{
			data->stack_a[i].value = data->stack_a[i + 1].value;
			data->stack_a[i].sorted = data->stack_a[i + 1].sorted;
			data->stack_a[i].index = data->stack_a[i + 1].index;
		}
	}
	set_size_pb(data);
}

void	pb_c(t_data *data)
{
	if (data->size_a == 0)
		return ;
	pb_c_doing(data);
}
