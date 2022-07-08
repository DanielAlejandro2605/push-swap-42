/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lstop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:50:14 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 10:50:14 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lstop	*ft_new_element_lstop(int value, t_lsti *instructions)
{
	t_lstop	*new;

	new = (t_lstop *)malloc(sizeof(t_lstop));
	if (!new)
		return (NULL);
	new->value = value;
	new->list_inst = instructions;
	new->next = NULL;
	return (new);
}

void	ft_add_inst_to_lst_op(t_lstop **begin_list, t_lstop *elem)
{
	t_lstop	*tmp;

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

t_lsti	*ft_initialize_t_lstit(void)
{
	t_lsti	*new_elem;

	new_elem = (t_lsti *)malloc(sizeof(t_lsti));
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

t_lsti	*ft_get_instructions_for_value(t_stack *a, t_stack *b, int value)
{
	t_lsti	*instructions;

	instructions = ft_initialize_t_lstit();
	if (!instructions)
		return (NULL);
	ft_get_inst_for_stack_a(instructions, a, value);
	ft_get_inst_for_stack_b(instructions, b, value);
	ft_improve_inst_for_value(instructions);
	return (instructions);
}
