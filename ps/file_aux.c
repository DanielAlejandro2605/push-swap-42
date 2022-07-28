/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:40:12 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/28 23:05:19 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_value_is_in_stack(t_stack *s, int value)
{
	int	i;

	i = 0;
	while (i < s->length)
	{
		if (s->tab[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	*ft_get_tab_sorted(t_stack *a)
{
	int		*tab_sorted;
	int		temp;
	int		i;

	tab_sorted = ft_get_tab_from_stack(a, a->length);
	if (!tab_sorted)
		return (NULL);
	i = -1;
	while (++i < (a->length - 1))
	{
		if (tab_sorted[i] > tab_sorted[i + 1])
		{
			temp = tab_sorted[i];
			tab_sorted[i] = tab_sorted[i + 1];
			tab_sorted[i + 1] = temp;
			i = -1;
		}
	}
	return (tab_sorted);
}

int	*ft_get_tab_from_stack(t_stack *a, int size)
{
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * (size));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = a->tab[i];
		i++;
	}
	return (tab);
}

int	ft_do_ops(t_lstop *op_list, t_stack *a, t_stack *b)
{
	ft_do_ra(a, op_list->list_inst->amt_ra);
	ft_do_rra(a, op_list->list_inst->amt_rra);
	ft_do_rb(b, op_list->list_inst->amt_rb);
	ft_do_rrb(b, op_list->list_inst->amt_rrb);
	ft_do_rr(a, b, op_list->list_inst->amt_rr);
	ft_do_rrr(a, b, op_list->list_inst->amt_rrr);
	if (ft_pb(a, b, 0))
		return (1);
	return (0);
}

void	ft_do_rrr(t_stack *a, t_stack *b, int number_rrr)
{
	int	i;

	i = 0;
	while (i < number_rrr)
	{
		ft_rrr(a, b, 0);
		i++;
	}
}
