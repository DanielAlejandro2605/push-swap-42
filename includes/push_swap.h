/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:31:34 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/02 19:06:51 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define ERROR_MESSAGE "Error here\n"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/*Structures of the project: */
typedef struct stack
{
    int     top;
    int     length;
    int     *tab;
}           t_stack;

typedef struct  list_instruction
{
    int     amt_ra;
    int     amt_rra;
    int     amt_rb;
    int     amt_rrb;
    int     amt_rr;
    int     amt_rrr;
    int     total_amt;
}			lst_ins;

typedef struct list_operations
{
    int                     value;
	struct list_instruction *list_inst;
    struct list_operations	*next;
}               			list_op;

/*Function to check the arguments
File : arguments.c*/
int     ft_is_valid_format_args(char **args);
int     ft_is_valid_range(char **args);
int     *ft_check_arguments(char **args);
/*Utils functions for check the arguments
File : arguments_utils.c*/
int		    ft_check_doubles(int *array, int size_array);
long int	ft_atoi_overflow(const char *str);
int			ft_isvalid_char(int c);
int			ft_count_args(char **args);
int			ft_arg_have_only_one_sign(char *arg);
/*Main functions
File : push_swap.c*/
void	ft_do_push_swap(int *args, int amount_args);
int		ft_args_is_already_sorted(int *args, int amount_args);
void    ft_push_swap(int *args_nums, int size_args_num);
t_stack *ft_initialize_a(int *args_nums, int size_args_num);
t_stack	*ft_initialize_b(void);
/*Functions to perform mini push swap
File : mini_push_swap.c*/
void	ft_mini_push_swap(int *args_nums, int size_args_num);
void	ft_mini_sort(t_stack *a, t_stack *b);
int     *ft_first_step(t_stack *a, t_stack *b);
void	ft_sort_3(t_stack *s);
int     *ft_get_tab_sorted(t_stack *a);
int     *ft_get_tab_from_stack(t_stack *a, int size);
/*Function to sort elements
File : sort.c*/
void	ft_sort(t_stack *a, t_stack *b);
void	ft_send_to_stack_a(t_stack *a, t_stack *b);
void	ft_do_ops(list_op *op_list, t_stack *a, t_stack *b);
list_op	*ft_get_ops_to_do(list_op *op_list);
list_op	*ft_create_list_operations(t_stack *a, t_stack *b);
/*Utils functions to sort the elements:
File : sort_utils.c*/
/*
Function utils for sort the elements
File : sort_utils.c
*/
int	ft_better_case_for_take_top(t_stack *s, int value);
int	ft_get_ideal_value_in_b(int value_to_push, t_stack *b);
int	ft_search_biggest_in_b(t_stack *b);
int	ft_value_is_biggest_than_all(int value, t_stack *b);
int	ft_search_biggest_less_than_value(int value, t_stack *b);

/*File of functions for respect the norme:
int	    ft_value_is_in_stack(t_stack *s, int value) for utils functions for sort
void    ft_do_rrr(t_stack *a, t_stack *b, int number_rrr) for do_operations
File : file_aux.c
*/
int		ft_value_is_in_stack(t_stack *s, int value);
void    ft_do_rrr(t_stack *a, t_stack *b, int number_rrr);
/*Function to do list operations: 
File : do_operations.c*/
void    ft_do_ra(t_stack *a, int number_ra);
void    ft_do_rb(t_stack *b, int number_rb);
void    ft_do_rra(t_stack *a, int number_rra);
void    ft_do_rrb(t_stack *b, int number_rrb);
void    ft_do_rr(t_stack *a, t_stack *b, int number_rr);
void    ft_do_rrr(t_stack *a, t_stack *b, int number_rrr);
void	ft_add_inst_to_lst_op(list_op **begin_list, list_op *elem);
/*
Function to get the list of the operations and the main functions
for list of instructions
File : list_op_and_inst.c*/
list_op	*ft_new_element_list_op(int value, lst_ins *instructions);
void	ft_add_inst_to_lst_op(list_op **begin_list, list_op *elem);
lst_ins	*ft_initialize_lst_inst(void);
lst_ins	*ft_get_instructions_for_value(t_stack *a, t_stack *b, int value);
void	ft_improve_inst_for_value(lst_ins *inst_list);
// void	ft_print_lst_op(list_op *begin_list);

/*Functions to get instruction for one element of stack and improve them
File : list_instruction.c*/
void	ft_get_inst_for_stack_a(lst_ins *inst_list, t_stack *a, int value);
void	ft_get_inst_for_stack_b(lst_ins *inst_list, t_stack *b, int value);
void	ft_improve_rotate_op(lst_ins *inst_list);
void	ft_improve_reverse_op(lst_ins *inst_list);
/*Functions utils for get instruction list
File : list_instruction_utils.c*/
int		ft_take_top_a_reversing(t_stack *a, int value);
int		ft_take_top_a_rotating(t_stack *a, int value);
// void	ft_print_lst_inst(lst_ins *inst_list); // To delete

/*
Functions to free the memory 
File: free.c
*/
void	ft_free_list_op(list_op *op_list);
void    ft_free_inst_list(lst_ins *list);
/*
Functions to swap
File : swap.c
*/
void    ft_swap(t_stack *s);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
/*
Functions to push
File : push.c
*/
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void    ft_push(t_stack *s1, t_stack *s2);
void    ft_update_from_push(t_stack *s);
void    ft_update_to_push(t_stack *s, int value);
/*
Functions to rotate
File : rotate.c
*/
void    ft_rotate(t_stack *s);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
/*
Functions to reverse
File : reverse.c
*/
void	ft_reverse(t_stack *s);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
/*
Functions for free
File : free.c
*/
void    ft_free_stack(t_stack *s);
void    ft_free_tab(int *tab);
void    ft_free_tab_and_assign(int *tab, t_stack *s);
void	ft_create_tab_for_first_push(t_stack *s, int *tab, int value);

int		ft_strlen(char *s);
int		ft_atoi(const char *str);
// /*
// Utils functions of LIBFT
// File : libft_functions.c
// */
// char	*get_next_line(int fd);
// void	ft_get_next_line(char *buffer_aux, char buffer_static[]);
// char	*ft_read_file(int fd, char buffer_static[], char *buffer_aux);
// char	*ft_concatenation(char *buffer_aux, char *buffer_file);
// char	*ft_get_line(char *buffer_aux);
// int		ft_atoi(const char *str);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// char	*ft_strdup(char *s);
// int		ft_strlen(char *s);
// void	*ft_calloc(size_t nmemb, size_t size);
// void	ft_bzero(void *s, size_t n);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char *s1, char *s2);

/*
Functions for develop the program
File : develop_functions.c
*/
void	ft_print_stack_a(t_stack *s);
void	ft_print_stack_b(t_stack *s);
#endif