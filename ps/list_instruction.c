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

void	ft_improve_rotate_op(lst_ins *inst_list)
{
	if (inst_list->amt_rra > 0 && inst_list->amt_rrb > 0)
	{
		if ((inst_list->amt_rra - inst_list->amt_rrb) == 0)
		{
			inst_list->amt_rrr = inst_list->amt_rra;
			inst_list->amt_rra = 0;
			inst_list->amt_rrb = 0;
		}
		else
		{
			if (inst_list->amt_rra > inst_list->amt_rrb)
			{
				inst_list->amt_rrr = inst_list->amt_rrb;
				inst_list->amt_rra = inst_list->amt_rra - inst_list->amt_rrb;
				inst_list->amt_rrb = 0;
			}
			else
			{
				inst_list->amt_rrr = inst_list->amt_rra;
				inst_list->amt_rrb = inst_list->amt_rrb - inst_list->amt_rra;
				inst_list->amt_rra = 0;
			}
		}
	}
}

void	ft_improve_reverse_op(lst_ins *inst_list)
{
	if (inst_list->amt_ra > 0 && inst_list->amt_rb > 0)
	{
		if ((inst_list->amt_ra - inst_list->amt_rb) == 0)
		{
			inst_list->amt_rr = inst_list->amt_ra;
			inst_list->amt_ra = 0;
			inst_list->amt_rb = 0;
		}
		else
		{
			if (inst_list->amt_ra > inst_list->amt_rb)
			{
				inst_list->amt_rr = inst_list->amt_rb;
				inst_list->amt_ra = inst_list->amt_ra - inst_list->amt_rb;
				inst_list->amt_rb = 0;
			}
			else
			{
				inst_list->amt_rr = inst_list->amt_ra;
				inst_list->amt_rb = inst_list->amt_rb - inst_list->amt_ra;
				inst_list->amt_ra = 0;
			}
		}
	}
}

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
