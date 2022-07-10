/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:08:11 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/10 17:48:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_first_step(t_stack *a, t_stack *b)
{
	int		*max_5_values;
	int		*tab_sorted;
	int		i;
	int		temp;

	tab_sorted = ft_get_tab_sorted(a);
	max_5_values = (int *)malloc(sizeof(int) * (5));
	if (!max_5_values)
		return (NULL);
	temp = a->length - 5;
	i = 0;
	while (temp < a->length)
		max_5_values[i++] = tab_sorted[temp++];
	while (b->length < 2 && a->length > 5)
	{
		if (ft_check_not_max_value(max_5_values, a->top))
			ft_ra(a, 0);
		else
			ft_pb(a, b, 0);
	}
	ft_free_tab(tab_sorted);
	return (max_5_values);
}

void	ft_sort_5(t_stack *a, t_stack *b)
{
	int		*max_3_values;
	int		*tab_sorted;
	int		i;
	int		temp;

	tab_sorted = ft_get_tab_sorted(a);
	max_3_values = (int *)malloc(sizeof(int) * (3));
	if (!max_3_values)
		return ;
	temp = a->length - 3;
	i = 0;
	while (temp < a->length)
		max_3_values[i++] = tab_sorted[temp++];
	while (a->length > 3)
	{
		if (a->top == max_3_values[0]
			|| a->top == max_3_values[1]
			|| a->top == max_3_values[2])
			ft_ra(a, 0);
		else
			ft_pb(a, b, 0);
	}
	ft_free_tab(tab_sorted);
	ft_free_tab(max_3_values);
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
		ft_ra(s, 0);
		if (s->tab[0] > s->tab[1])
			ft_sa(s, 0);
	}
	else if (biggest_index == 1)
	{
		ft_rra(s, 0);
		if (s->tab[0] > s->tab[1])
			ft_sa(s, 0);
	}
	else if (biggest_index == 2)
	{
		if (s->tab[0] > s->tab[1])
			ft_sa(s, 0);
	}
}

int		ft_check_not_max_value(int *max_5_values, int value)
{
	if (value == max_5_values[0]
		|| value == max_5_values[1]
		|| value == max_5_values[2]
		|| value == max_5_values[3]
		|| value == max_5_values[4])
		return (1);
	return (0);
}
