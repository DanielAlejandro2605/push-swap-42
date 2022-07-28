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

#include "../includes/push_swap.h"

int	ft_begin_sort(t_stack *a, t_stack *b)
{
	t_lstop	*operation_lst;
	t_lstop	*to_do;
	int		*max_5_values;

	max_5_values = ft_first_step(a, b);
	if (!max_5_values)
		return (1);
	while (a->length > 5)
	{
		operation_lst = ft_create_list_operations(a, b, max_5_values);
		if (!operation_lst)
			return (ft_error_op_list(operation_lst, max_5_values));
		to_do = ft_get_ops_to_do(operation_lst);
		if (ft_do_ops(to_do, a, b))
			return (ft_error_op_list(operation_lst, max_5_values));
		ft_free_list_op(operation_lst);
	}
	ft_free_tab(max_5_values);
	if (ft_sort(a, b))
		return (1);
	return (0);
}

int	ft_sort(t_stack *a, t_stack *b)
{
	if (ft_sort_5(a, b))
		return (1);
	ft_sort_3(a);
	if (b->tab[0] < b->tab[1])
		ft_sb(b, 0);
	if (ft_pa(a, b, 0))
		return (1);
	if (b->length >= 1)
		if (ft_pa(a, b, 0))
			return (1);
	if (b->length > 0)
		if (ft_send_to_stack_a(a, b))
			return (1);
	return (0);
}

int	ft_send_to_stack_a(t_stack *a, t_stack *b)
{
	int		biggest_b;
	int		better_case_biggest_b;

	biggest_b = ft_search_biggest_in_b(b);
	better_case_biggest_b = ft_better_case_for_take_top(b, biggest_b);
	if (better_case_biggest_b == 1)
		while (b->top != biggest_b)
			ft_rb(b, 0);
	else if (better_case_biggest_b == 2)
		while (b->top != biggest_b)
			ft_rrb(b, 0);
	while (b->length > 0)
		if (ft_pa(a, b, 0))
			return (1);
	return (0);
}

t_lstop	*ft_get_ops_to_do(t_lstop *op_list)
{
	t_lstop	*tmp;
	t_lstop	*to_do;

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

t_lstop	*ft_create_list_operations(t_stack *a, t_stack *b, int *max_5_values)
{
	t_lstop	*operation_lst;
	t_lstop	*aux;
	t_lsti	*list_instruction;
	int		i;

	operation_lst = NULL;
	aux = NULL;
	i = 0;
	while (i < a->length)
	{
		if (!(ft_check_not_max_value(max_5_values, a->tab[i])))
		{
			list_instruction = ft_get_instructions_for_value(a, b, a->tab[i]);
			if (!list_instruction)
				return (NULL);
			aux = ft_new_element_lstop(a->tab[i], list_instruction);
			if (!aux)
				return (ft_free_inst_list(list_instruction));
			ft_add_inst_to_lst_op(&operation_lst, aux);
		}
		i++;
	}
	return (operation_lst);
}
