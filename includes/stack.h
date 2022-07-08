/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:00:37 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/08 19:20:03 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
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
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
/*
Functions to push
File : push.c
*/
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_push(t_stack *s1, t_stack *s2);
void	ft_update_from_push(t_stack *s);
void	ft_update_to_push(t_stack *s, int value);
/*
Functions to rotate
File : rotate.c
*/
void	ft_rotate(t_stack *s);
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
void	ft_free_stack(t_stack *s);
void	ft_free_tab(int *tab);
void	ft_free_tab_and_assign(int *tab, t_stack *s);
void	ft_create_tab_for_first_push(t_stack *s, int *tab, int value);
#endif