
#ifndef CHECKER_H
# define CHECKER_H


# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../includes/stack.h"

/*Function to check the arguments
File : arguments_checker.c*/
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
/*
Main functions:
File : checker.c
*/
int		ft_checker(int *args_nums, int size_args_num);
char	*ft_get_list_instructions(void);
// void	ft_exec_function(char *operation_name, l_stack *a, l_stack *b);
// int		ft_stack_is_sort(l_stack **s);
// int		ft_stack_is_empty(l_stack **b);

// /*Utils for the develop of the program
// File : develop_functions.c*/
// void    ft_print_stack_a(l_stack *a);
// void    ft_print_stack_b(l_stack *b);
// void    ft_print_stack(l_stack *begin_list);
// void    ft_print_args(char **args);
// void	ft_print_stacks(l_stack *a, l_stack *b);

#endif