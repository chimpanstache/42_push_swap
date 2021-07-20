/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:17:17 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 21:07:13 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	t_data data; 

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
	// for (int i = 0 ; i < data.size_a ; i++)
	// {
	// 	printf("ind[%d]| begin stack a sorted == %d | stack a value == %d\n", data.stack_a[i].index, data.stack_a[i].sorted, data.stack_a[i].value);
	// }  
	if (arraySortedOrNot(&data) == 1)
	{
		return 0;
	}	
	push_swap(&data);
	// for (int i = 0 ; i < data.size_a ; i++)
	// {
	// 	printf("ind[%d]| final stack a sorted == %d | stack a value == %d\n", data.stack_a[i].index, data.stack_a[i].sorted, data.stack_a[i].value);
	// }
	free(data.stack_a);
	free(data.stack_b);	
    return 0;
}
