/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:17:17 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 21:27:15 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.inst_count = 0;
	if (parsing(argc, argv) == -1)
	{
		return (-1);
	}
	input_strtoint(&argv[1], &data);
	if (check_doublons(&data) == -1)
		return (-1);
	selectionSort(&data);
	index_attribution(&data);
	if (arraySortedOrNot(&data) == 1)
	{
		return (0);
	}
	push_swap(&data);
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}
