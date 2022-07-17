/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:00:37 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/17 18:21:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../includes/utils.h"
# define ERROR_MESSAGE "Error\n"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct stack
{
	int		top;
	int		length;
	int		*tab;
}			t_stack;
/*Functions to initialize both stacks
File : init.c*/
t_stack	*ft_initialize_a(int *args_nums, int size_args_num);
t_stack	*ft_initialize_b(void);
/*
Functions to swap
File : swap.c
*/
void	ft_swap(t_stack *s);
void	ft_sa(t_stack *a, int for_checker);
void	ft_sb(t_stack *b, int for_checker);
void	ft_ss(t_stack *a, t_stack *b, int for_checker);
/*
Functions to push
File : push.c
*/
void	ft_pa(t_stack *a, t_stack *b, int for_checker);
void	ft_pb(t_stack *a, t_stack *b, int for_checker);
void	ft_push(t_stack *s1, t_stack *s2);
void	ft_update_from_push(t_stack *s);
void	ft_update_to_push(t_stack *s, int value);
/*
Functions to rotate
File : rotate.c
*/
void	ft_rotate(t_stack *s);
void	ft_ra(t_stack *a, int for_checker);
void	ft_rb(t_stack *b, int for_checker);
void	ft_rr(t_stack *a, t_stack *b, int for_checker);
/*
Functions to reverse
File : reverse.c
*/
void	ft_reverse(t_stack *s);
void	ft_rra(t_stack *a, int for_checker);
void	ft_rrb(t_stack *b, int for_checker);
void	ft_rrr(t_stack *a, t_stack *b, int for_checker);
/*
Functions for free
File : free.c
*/
void	ft_free_stack(t_stack *s);
void	ft_free_tab(int *tab);
void	ft_free_tab_and_assign(int *tab, t_stack *s);
void	ft_create_tab_for_first_push(t_stack *s, int *tab, int value);

#endif