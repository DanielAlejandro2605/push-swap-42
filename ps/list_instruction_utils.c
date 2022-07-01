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

// void	ft_print_lst_inst(lst_ins *inst_list)
// {
// 	printf("ra  : %d\n", inst_list->amt_ra);
// 	printf("rra : %d\n", inst_list->amt_rra);
// 	printf("rb  : %d\n", inst_list->amt_rb);
// 	printf("rrb : %d\n", inst_list->amt_rrb);
// 	printf("rr  : %d\n", inst_list->amt_rr);
// 	printf("rrr : %d\n", inst_list->amt_rrr);
// 	printf("total amount %d\n", inst_list->total_amt);
// }