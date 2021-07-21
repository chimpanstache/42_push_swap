# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 11:42:06 by ehafidi           #+#    #+#              #
#    Updated: 2021/07/21 18:26:15 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PS = srcs/main.c srcs/split.c srcs/push_swap.c srcs/actions_s.c srcs/actions_r.c srcs/utils.c\
	srcs/actions_rr.c srcs/actions_pa.c srcs/actions_pb.c srcs/3_rand_num.c srcs/algo_4_5.c srcs/selection_sort.c \
	srcs/sort_big_stack.c \

SRC_CH = srcs/checker.c srcs/split.c srcs/utils.c srcs/get_next_line.c srcs/get_next_line_utils.c \
	srcs/actions_rr_checker.c srcs/actions_pa_checker.c srcs/actions_pb_checker.c srcs/actions_s_checker.c \
	srcs/actions_r_checker.c srcs/selection_sort.c \

OBJ_PS = $(SRC_PS:.c=.o)

OBJ_CH = $(SRC_CH:.c=.o)

CC = gcc 
CCFLAGS = -g -Wall -Wextra -Werror

MAKE = make

NAME_PS = push_swap
NAME_CH = checker

RM = rm -rf

all	: $(OBJ_PS) $(NAME_PS) $(OBJ_CH) $(NAME_CH)

$(NAME_PS):
	$(CC) $(CCFLAGS) -o $(NAME_PS) $(OBJ_PS)

$(NAME_CH):
	$(CC) $(CCFLAGS) -o $(NAME_CH) $(OBJ_CH)

clean: 
	$(RM) $(OBJ_PS) $(OBJ_CH)

%.o: %.c
		$(CC) $(CCFLAGS) -o $@ -c $<

fclean: clean
	$(RM) $(NAME_PS) $(NAME_CH)
	$(RM) *.dSYM
	$(RM) values

re: fclean all
	
