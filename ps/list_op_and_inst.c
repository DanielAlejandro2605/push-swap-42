/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:50:14 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 10:50:14 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

list_op	*ft_new_element_list_op(int value, lst_ins *instructions)
{
	list_op	*new;

	new = (list_op *)malloc(sizeof(list_op));
	if (!new)
		return (NULL);
	new->value = value;
	new->list_inst = instructions;
	new->next = NULL;
	return (new);
}

void	ft_add_inst_to_lst_op(list_op **begin_list, list_op *elem)
{
	list_op	*tmp;

	if (elem)
	{
		if (*begin_list == NULL)
			*begin_list = elem;
		else
		{
			tmp = *begin_list;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = elem;
		}
	}
}

lst_ins	*ft_initialize_lst_inst(void)
{
	lst_ins	*new_elem;

	new_elem = (lst_ins *)malloc(sizeof(lst_ins));
	if (!new_elem)
		return (NULL);
	new_elem->amt_ra = 0;
	new_elem->amt_rra = 0;
	new_elem->amt_rb = 0;
	new_elem->amt_rrb = 0;
	new_elem->amt_rr = 0;
	new_elem->amt_rrr = 0;
	new_elem->total_amt = 0;
	return (new_elem);
}

lst_ins	*ft_get_instructions_for_value(t_stack *a, t_stack *b, int value)
{
	lst_ins	*instructions;

	instructions = ft_initialize_lst_inst();
	if (!instructions)
		return (NULL);
	ft_get_inst_for_stack_a(instructions, a, value);
	ft_get_inst_for_stack_b(instructions, b, value);
	ft_improve_inst_for_value(instructions);
	return (instructions);
}

void	ft_improve_inst_for_value(lst_ins *inst_list)
{
	ft_improve_reverse_op(inst_list);
	ft_improve_rotate_op(inst_list);
	inst_list->total_amt += inst_list->amt_ra;
	inst_list->total_amt += inst_list->amt_rb;
	inst_list->total_amt += inst_list->amt_rra;
	inst_list->total_amt += inst_list->amt_rrb;
	inst_list->total_amt += inst_list->amt_rr;
	inst_list->total_amt += inst_list->amt_rrr;
}

/*void	ft_print_lst_op(list_op *begin_list)
{
	list_op	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		printf("Value %d\n", tmp->value);
		ft_print_lst_inst(tmp->list_inst);
		tmp = tmp->next;
	}	
}*/