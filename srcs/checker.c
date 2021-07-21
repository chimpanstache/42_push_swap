/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:20:27 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 13:58:32 by ehafidi          ###   ########.fr       */
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
	{
		write(2, "Error\n", 6);								
		free(data->stack_a);
		free(data->stack_b);
		exit(EXIT_FAILURE);
	}

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
			free(data->stack_a);
			free(data->stack_b);
			exit(EXIT_FAILURE);
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
	char **tmp;
	int tmp_malloced = 0;

	tmp = &argv[1];
	data.inst_count = 0;
	if (argc == 2 && just_digit_and_space(argv[1]))
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
	if (arraySortedOrNot(&data) == 1)
	{
		write(1, "OK\n", 3);
		free(data.stack_a);
		free(data.stack_b);	
    	return 0;
	}	
	checker(&data);
	if (arraySortedOrNot(&data) == 1 && data.size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(data.stack_a);
	free(data.stack_b);	
    return 0;
}
