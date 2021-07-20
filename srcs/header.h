/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:17:03 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/20 21:07:48 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

# define BUFFER_SIZE 40

typedef struct		s_stage
{
	int value;
	int index;
	int sorted;
}					t_stage;

typedef struct		s_data
{
	t_stage *stack_a;
	t_stage *stack_b;
	int size_a;
	int size_b;
	int size_origin;
	int n_chunk;
	int size_chunk;
	int biggest_chunk;
	int inst_count;	
}					t_data;

void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
int					get_next_line(int fd, char **line);

void selectionSort(t_data *data);
void index_attribution(t_data *data);

// int get_array_size(int *arr);
void push_swap(t_data *data);
void ss(t_data *data);
void sb(t_data *data);
void sa(t_data *data);

void ra(t_data *data);
void rb(t_data *data);
void rr(t_data *data);

void rra(t_data *data);
void rrb(t_data *data);
void rrr(t_data *data);

void pa(t_data *data);
void pb(t_data *data);

void ss_c(t_data *data);
void sb_c(t_data *data);
void sa_c(t_data *data);

void ra_c(t_data *data);
void rb_c(t_data *data);
void rr_c(t_data *data);

void rra_c(t_data *data);
void rrb_c(t_data *data);
void rrr_c(t_data *data);

void pa_c(t_data *data);
void pb_c(t_data *data);

void algo_3(t_data *data);
void algo_4(t_data *data);
void algo_5(t_data *data);
void algo_100(t_data *data);

int determine_nearest_from_top(t_data *data, int top_of_chunk);
int determine_nearest_from_bottom(t_data *data, int top_of_chunk);

int nb_of_rrb(t_data *data, int index);
int nb_of_rb(t_data *data, int index);

void sort_big_stack(t_data *data);

int	ft_atoi_push_swap(const char *str);

size_t	ft_strlen(const char *str);
int arraySortedOrNot(t_data *data);

int		ft_isdigit(int c);

int parsing(int argc, char **argv);
void input_strtoint(char **argvs, t_data *data);
int check_doublons(t_data *data);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

#endif 