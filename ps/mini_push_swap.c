/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:08:11 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/05 15:20:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_mini_sort(t_stack *a, t_stack *b)
{
	list_op	*operation_lst;
	list_op	*to_do;
	int		*max_3_values;
	
	max_3_values = ft_first_step(a, b);
	while (a->length > 3)
	{
		if (a->top == max_3_values[0]
		|| a->top == max_3_values[1]
		|| a->top == max_3_values[2])
				ft_ra(a);
		else
		{
			operation_lst = ft_create_list_operations(a, b);
			to_do = ft_get_ops_to_do(operation_lst);
			ft_do_ops(to_do, a, b);
			ft_free_list_op(operation_lst);	
		}
	}
	ft_sort_3(a);
	ft_send_to_stack_a(a, b);
	ft_free_tab(max_3_values);
}

int	*ft_first_step(t_stack *a, t_stack *b)
{
	int		*max_3_values;
	int		*tab_sorted;
	int		i;
	int		temp;

	tab_sorted = ft_get_tab_sorted(a);
	max_3_values = (int *)malloc(sizeof(int) * (3));
	if (!max_3_values)
		return (NULL);
	temp = a->length - 3;
	i = 0;
	while (temp < a->length)
		max_3_values[i++] = tab_sorted[temp++];
	while (b->length < 2 && a->length > 3)
	{
		if (a->top == max_3_values[0] || a->top == max_3_values[1]
		|| a->top == max_3_values[2])
			ft_ra(a);
		else
			ft_pb(a, b);
	}
	ft_free_tab(tab_sorted);
	return (max_3_values);
}

void	ft_sort_3(t_stack *s)
{
	int	i;
	int	biggest;
	int	biggest_index;

	i = 0;
	biggest_index = i;
	biggest = s->tab[biggest_index];
	while (i < s->length)
	{
		if (s->tab[i] > biggest)
		{
			biggest_index = i;
			biggest = s->tab[i];
		}
		i++;
	}
	ft_handle_biggest_index(biggest_index, s);
}

void	ft_handle_biggest_index(int biggest_index, t_stack *s)
{
	if (biggest_index == 0)
	{
		ft_ra(s);
		if (s->tab[0] > s->tab[1])
			ft_sa(s);
	}
	else if(biggest_index == 1)
	{
		ft_rra(s);
		if (s->tab[0] > s->tab[1])
			ft_sa(s);
	}
	else if(biggest_index == 2)
	{
		if (s->tab[0] > s->tab[1])
			ft_sa(s);
	}
}
