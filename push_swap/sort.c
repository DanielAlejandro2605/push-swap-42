/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:33:34 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 10:33:34 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	list_op	*operation_lst;
	list_op	*to_do;

	ft_pb(a, b);
	ft_pb(a, b);
	while (a->length > 0)
	{
		operation_lst = ft_create_list_operations(a, b);
		to_do = ft_get_ops_to_do(operation_lst);
		ft_do_ops(to_do, a, b);
		ft_free_list_op(operation_lst);
	}
	ft_send_to_stack_a(a, b);
}

void	ft_send_to_stack_a(t_stack *a, t_stack *b)
{
	int		biggest_b;
	int		better_case_biggest_b;

	biggest_b = ft_search_biggest_in_b(b);
	better_case_biggest_b = ft_better_case_for_take_top(b, biggest_b);
	if (better_case_biggest_b == 1)
		while (b->top != biggest_b)
			ft_rb(b);
	else if (better_case_biggest_b == 2)
		while (b->top != biggest_b)
			ft_rrb(b);
	while (b->length > 0)
		ft_pa(a, b);
}

void	ft_do_ops(list_op *op_list, t_stack *a, t_stack *b)
{
	ft_do_ra(a, op_list->list_inst->amt_ra);
	ft_do_rra(a, op_list->list_inst->amt_rra);
	ft_do_rb(b, op_list->list_inst->amt_rb);
	ft_do_rrb(b, op_list->list_inst->amt_rrb);
	ft_do_rr(a, b, op_list->list_inst->amt_rr);
	ft_do_rrr(a, b, op_list->list_inst->amt_rrr);
	ft_pb(a, b);
}

list_op	*ft_get_ops_to_do(list_op *op_list)
{
	list_op	*tmp;
	list_op	*to_do;

	to_do = op_list;
	tmp = op_list;
	while (tmp)
	{
		if (tmp->list_inst->total_amt < to_do->list_inst->total_amt)
			to_do = tmp;
		tmp = tmp->next;
	}
	return (to_do);
}

list_op	*ft_create_list_operations(t_stack *a, t_stack *b)
{
	list_op	*operation_lst;
	list_op	*aux;
	lst_ins	*list_instruction;
	int		i;

	operation_lst = NULL;
	aux = NULL;
	i = 0;
	while (i < a->length)
	{
		list_instruction = ft_get_instructions_for_value(a, b, a->tab[i]);
		aux = ft_new_element_list_op(a->tab[i], list_instruction);
		ft_add_inst_to_lst_op(&operation_lst, aux);
		i++;
	}
	return (operation_lst);
}
