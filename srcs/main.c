/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:17:17 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 17:12:17 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	doing_push_swap(t_data *data)
{
	if (arraySortedOrNot(data) == 1)
	{
		free(data->stack_a);
		free(data->stack_b);
		exit(1);
	}
	push_swap(data);
	free(data->stack_a);
	free(data->stack_b);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**tmp;
	int		tmp_malloced;

	tmp_malloced = 0;
	tmp = &argv[1];
	data.inst_count = 0;
	if (argc == 2 && just_digit_and_space(argv[1]) != 0)
	{
		tmp = ft_split(argv[1], ' ');
		tmp_malloced++;
	}
	if (parsing(argc, tmp) == -1)
		return (-1);
	input_strtoint(tmp, &data);
	if (check_doublons(&data) == -1)
		return (-1);
	selectionSort(&data);
	index_attribution(&data);
	if (tmp_malloced != 0)
		free_tmp(tmp);
	doing_push_swap(&data);
	return (0);
}
