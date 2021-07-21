/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_pa_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:56:08 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 18:28:35 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_data_pa(t_data *data)
{
	data->stack_a[0].value = data->stack_b[0].value;
	data->stack_a[0].index = data->stack_b[0].index;
	data->stack_a[0].sorted = data->stack_b[0].sorted;
}

void	set_size_pa(t_data *data)
{
	data->size_b--;
	data->size_a++;
}

void	pa_c_doing(t_data *data)
{
	int	i;

	if (data->size_a > 0)
	{
		i = data->size_a + 1;
		while ((--i) > 0)
		{
			data->stack_a[i].value = data->stack_a[i - 1].value;
			data->stack_a[i].index = data->stack_a[i - 1].index;
			data->stack_a[i].sorted = data->stack_a[i - 1].sorted;
		}
	}
	set_data_pa(data);
	if (data->size_b > 0)
	{
		i = -1;
		while ((++i) + 1 < data->size_b)
		{
			data->stack_b[i].value = data->stack_b[i + 1].value;
			data->stack_b[i].sorted = data->stack_b[i + 1].sorted;
			data->stack_b[i].index = data->stack_b[i + 1].index;
		}
	}
	set_size_pa(data);
}

void	pa_c(t_data *data)
{
	if (data->size_b == 0)
		return ;
	pa_c_doing(data);
}
