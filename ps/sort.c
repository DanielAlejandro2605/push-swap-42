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

static void	ft_print_stack_a(t_stack *s)
{
	int     i;

	i = 0;
	ft_printf("*******************\n");
	ft_printf("    DATA OF A\n");
	ft_printf("   top    : %d\n", s->top);
	ft_printf("   length : %d\n", s->length);
	ft_printf("*******************\n");
	while (i < s->length)
    {
        ft_printf("         %d\n", s->tab[i]);
        i++;
    }
	ft_printf("        ---\n");
	ft_printf("         a ");
	ft_printf("\n");
}

static void	ft_print_stack_b(t_stack *s)
{
	int     i;

	i = 0;
	ft_printf("*******************\n");
	ft_printf("    DATA OF B\n");
	ft_printf("   top    : %d\n", s->top);
	ft_printf("   length : %d\n", s->length);
	ft_printf("*******************\n");
	// if(!s->tab)
	// 	ft_printf("No Inizializada");
	while (i < s->length)
    {
        ft_printf("         %d\n", s->tab[i]);
        i++;
    }
	ft_printf("        ---\n");
	ft_printf("         b ");
	ft_printf("\n");
}

void	ft_sort(t_stack *a, t_stack *b)
{
	t_lstop	*operation_lst;
	t_lstop	*to_do;
	int		*max_5_values;

	max_5_values = ft_first_step(a, b);
	while (a->length > 5)
	{
		operation_lst = ft_create_list_operations(a, b, max_5_values);
		to_do = ft_get_ops_to_do(operation_lst);
		ft_do_ops(to_do, a, b);
		ft_free_list_op(operation_lst);
	}
	ft_sort_5(a, b);
	ft_sort_3(a);
	if (b->tab[0] < b->tab[1])
		ft_sb(b, 0);
	ft_pa(a, b, 0);
	ft_pa(a, b, 0);
	ft_send_to_stack_a(a, b);
	ft_print_stack_a(a);
	ft_print_stack_b(b);
	ft_free_tab(max_5_values);
}

void	ft_send_to_stack_a(t_stack *a, t_stack *b)
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
		ft_pa(a, b, 0);
}

void	ft_do_ops(t_lstop *op_list, t_stack *a, t_stack *b)
{
	ft_do_ra(a, op_list->list_inst->amt_ra);
	ft_do_rra(a, op_list->list_inst->amt_rra);
	ft_do_rb(b, op_list->list_inst->amt_rb);
	ft_do_rrb(b, op_list->list_inst->amt_rrb);
	ft_do_rr(a, b, op_list->list_inst->amt_rr);
	ft_do_rrr(a, b, op_list->list_inst->amt_rrr);
	ft_pb(a, b, 0);
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
			aux = ft_new_element_lstop(a->tab[i], list_instruction);
			ft_add_inst_to_lst_op(&operation_lst, aux);
		}
		i++;
	}
	return (operation_lst);
}
