/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:20:27 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 21:07:33 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void move_compare_and_exec(t_data *data, char *line)
{
	if (ft_strncmp(line, "ss", 4) == 0)
		ss_c(data);
	else if (ft_strncmp(line, "sb", 4) == 0)
		sb_c(data);
	else if (ft_strncmp(line, "sa", 4) == 0)
		sa_c(data);
	else if (ft_strncmp(line, "rr", 4) == 0)
		rr_c(data);
	else if (ft_strncmp(line, "rb", 4) == 0)
		rb_c(data);
	else if (ft_strncmp(line, "ra", 4) == 0)
		ra_c(data);
	else if (ft_strncmp(line, "rra", 4) == 0)
		rra_c(data);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		rrb_c(data);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		rrr_c(data);
	else if (ft_strncmp(line, "pa", 4) == 0)
		pa_c(data);
	else if (ft_strncmp(line, "pb", 4) == 0)
		pb_c(data);
	else
		write(2, "Error\n", 6);								
}

void checker(t_data *data)
{
	char *line = NULL; 
	int ret = 1;

	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret < 0)
		{
           	write(2, "Error\n", 6);
		}
		else if (ret == 1)
		{
			move_compare_and_exec(data, line);
		}
		else if (ret == 0) 
		{
			free(line);
			return ;
		}
		free(line);
	}
}

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
	checker(&data);
	if (arraySortedOrNot(&data) == 1 && data.size_b == 0)
	{
		write(1, "OK\n", 3);
	}
	else
	{
		write(1, "KO\n", 3);
	}

	free(data.stack_a);
	free(data.stack_b);	
    return 0;
}
