/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:31:34 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/08 20:18:12 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../includes/stack.h"

/*Structures of the project: */
typedef struct list_instruction
{
	int		amt_ra;
	int		amt_rra;
	int		amt_rb;
	int		amt_rrb;
	int		amt_rr;
	int		amt_rrr;
	int		total_amt;
}			t_lsti;

typedef struct list_operations
{
	int						value;
	struct list_instruction	*list_inst;
	struct list_operations	*next;
}							t_lstop;

/*Function to check the arguments
File : arguments.c*/
int		ft_is_valid_format_args(char **args);
int		ft_is_valid_range(char **args);
int		*ft_check_arguments(char **args);
/*Utils functions for check the arguments
File : arguments_utils.c*/
int		ft_check_doubles(int *array, int size_array);
long	ft_atoi_overflow(const char *str);
int		ft_isvalid_char(int c);
int		ft_count_args(char **args);
int		ft_arg_have_only_one_sign(char *arg);
/*Main functions
File : push_swap.c*/
void	ft_do_push_swap(int *args, int amount_args);
int		ft_args_is_already_sorted(int *args, int amount_args);
void	ft_push_swap(int *args_nums, int size_args_num);
void	ft_mini_push_swap(int *args_nums, int size_args_num);
/*Functions to perform mini push swap
File : mini_push_swap.c*/
void	ft_mini_sort(t_stack *a, t_stack *b);
int		*ft_first_step(t_stack *a, t_stack *b);
void	ft_sort_3(t_stack *s);
void	ft_handle_biggest_index(int biggest_index, t_stack *s);
/*Function to sort elements
File : sort.c*/
void	ft_sort(t_stack *a, t_stack *b);
void	ft_send_to_stack_a(t_stack *a, t_stack *b);
void	ft_do_ops(t_lstop *op_list, t_stack *a, t_stack *b);
t_lstop	*ft_get_ops_to_do(t_lstop *op_list);
t_lstop	*ft_create_list_operations(t_stack *a, t_stack *b);
/*Utils functions to sort the elements:
File : sort_utils.c*/
int		ft_better_case_for_take_top(t_stack *s, int value);
int		ft_get_ideal_value_in_b(int value_to_push, t_stack *b);
int		ft_search_biggest_in_b(t_stack *b);
int		ft_value_is_biggest_than_all(int value, t_stack *b);
int		ft_search_biggest_less_than_value(int value, t_stack *b);
/*File of functions for respect the norme:
File : file_aux.c
*/
int		*ft_get_tab_sorted(t_stack *a);
int		*ft_get_tab_from_stack(t_stack *a, int size);
int		ft_value_is_in_stack(t_stack *s, int value);
void	ft_do_rrr(t_stack *a, t_stack *b, int number_rrr);
/*Function to do list operations: 
File : do_operations.c*/
void	ft_do_ra(t_stack *a, int number_ra);
void	ft_do_rb(t_stack *b, int number_rb);
void	ft_do_rra(t_stack *a, int number_rra);
void	ft_do_rrb(t_stack *b, int number_rrb);
void	ft_do_rr(t_stack *a, t_stack *b, int number_rr);
/*
Function to get the list of the operations and the main functions
for list of instructions
File : list_op_and_inst.c*/
t_lstop	*ft_new_element_lstop(int value, t_lsti *instructions);
void	ft_add_inst_to_lst_op(t_lstop **begin_list, t_lstop *elem);
t_lsti	*ft_initialize_lst_inst(void);
t_lsti	*ft_get_instructions_for_value(t_stack *a, t_stack *b, int value);
// void	ft_print_lst_op(list_op *begin_list);

/*Functions to get instruction for one element of stack and improve them
File : list_instruction.c*/
void	ft_get_inst_for_stack_a(t_lsti *inst_list, t_stack *a, int value);
void	ft_get_inst_for_stack_b(t_lsti *inst_list, t_stack *b, int value);
int		ft_take_top_a_reversing(t_stack *a, int value);
int		ft_take_top_a_rotating(t_stack *a, int value);

/*Functions utils for get instruction list
File : list_instruction_improve.c*/
void	ft_improve_rotate_op(t_lsti *lst);
void	ft_improve_reverse_op(t_lsti *lst);
void	ft_change_val(int *value1, int *value2, int *value3);
void	ft_improve_inst_for_value(t_lsti *inst_list);
/*
Functions to free the memory 
File: free.c
*/
void	ft_free_list_op(t_lstop *op_list);
void	ft_free_inst_list(t_lsti *list);
#endif