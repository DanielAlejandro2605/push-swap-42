/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:50:10 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 10:50:10 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_inst_for_stack_a(lst_ins *inst_list, t_stack *a, int value)
{
	int		better_case;

	better_case = ft_better_case_for_take_top(a, value);
	if (better_case == 1)
	{
		inst_list->amt_ra = ft_take_top_a_reversing(a, value);
		inst_list->amt_rra = 0;
	}
	else if (better_case == 2)
	{
		inst_list->amt_ra = 0;
		inst_list->amt_rra = ft_take_top_a_rotating(a, value);
	}
}

void	ft_get_inst_for_stack_b(lst_ins *inst_list, t_stack *b, int value)
{
	int		value_guide;
	int		better_case;

	value_guide = ft_get_ideal_value_in_b(value, b);
	better_case = ft_better_case_for_take_top(b, value_guide);
	if (better_case == 1)
	{
		inst_list->amt_rb = ft_take_top_a_reversing(b, value_guide);
		inst_list->amt_rrb = 0;
	}
	else if (better_case == 2)
	{
		inst_list->amt_rb = 0;
		inst_list->amt_rrb = ft_take_top_a_rotating(b, value_guide);
	}
}

int	ft_take_top_a_reversing(t_stack *a, int value)
{
	int		op_ra;

	op_ra = 0;
	while (a->tab[op_ra] != value)
		op_ra++;
	return (op_ra);
}

int	ft_take_top_a_rotating(t_stack *a, int value)
{
	int		op_rra;

	op_rra = a->length - 1;
	while (a->tab[op_rra] != value)
		op_rra--;
	op_rra = a->length - op_rra;
	return (op_rra);
}
