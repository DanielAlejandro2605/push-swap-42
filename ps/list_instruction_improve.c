/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instruction_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:01:50 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 11:01:50 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_improve_rotate_op(t_lsti *lst)
{
	if (lst->amt_rra > 0 && lst->amt_rrb > 0)
	{
		if ((lst->amt_rra - lst->amt_rrb) == 0)
		{
			lst->amt_rrr = lst->amt_rra;
			lst->amt_rra = 0;
			lst->amt_rrb = 0;
		}
		else
		{
			if (lst->amt_rra > lst->amt_rrb)
				ft_change_val(&lst->amt_rrb, &lst->amt_rra, &lst->amt_rrr);
			else
				ft_change_val(&lst->amt_rra, &lst->amt_rrb, &lst->amt_rrr);
		}
	}
}

void	ft_improve_reverse_op(t_lsti *lst)
{
	if (lst->amt_ra > 0 && lst->amt_rb > 0)
	{
		if ((lst->amt_ra - lst->amt_rb) == 0)
		{
			lst->amt_rr = lst->amt_ra;
			lst->amt_ra = 0;
			lst->amt_rb = 0;
		}
		else
		{
			if (lst->amt_ra > lst->amt_rb)
				ft_change_val(&lst->amt_rb, &lst->amt_ra, &lst->amt_rr);
			else
				ft_change_val(&lst->amt_ra, &lst->amt_rb, &lst->amt_rr);
		}
	}
}

void	ft_change_val(int *value1, int *value2, int *value3)
{
	value3 = value1;
	value2 = (int *)(value2 - value1);
	value1 = 0;
	(void)value3;
}

void	ft_improve_inst_for_value(t_lsti *inst_list)
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
