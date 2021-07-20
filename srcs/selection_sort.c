/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:17:17 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/18 14:29:04 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(t_data *data, int min_idx, int i)
{
    int temp = data->stack_a[min_idx].sorted;
    data->stack_a[min_idx].sorted = data->stack_a[i].sorted;
    data->stack_a[i].sorted = temp;
}

// Function to perform Selection Sort
void selectionSort(t_data *data)
{
    int i; 
	int j; 
	int min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < data->size_a - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < data->size_a; j++)
            if (data->stack_a[j].sorted < data->stack_a[min_idx].sorted)
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(data, min_idx, i);
    }
}

void index_attribution(t_data *data)
{
	for (int i = 0; i < data->size_a; i++)
	{
		for (int j = 0; j < data->size_a; j++)
		{
			if (data->stack_a[i].value == data->stack_a[j].sorted)
			{
				data->stack_a[i].index = j;
			}
		}	
	}
}
