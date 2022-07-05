
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
void	ft_checker(char **argv);
void    ft_exec_list_instructions(t_stack *a, t_stack *b);
void	ft_exec_one_operation(char *op, t_stack *a, t_stack *b);
int		ft_stack_is_sorted(t_stack *s);
int		ft_stack_is_empty(t_stack *s);
#endif