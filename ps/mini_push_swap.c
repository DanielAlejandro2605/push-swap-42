/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:08:11 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/28 23:02:33 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_first_step(t_stack *a, t_stack *b)
{
	int		*max_5_values;

	max_5_values = ft_get_max_values_first_step(a);
	if (max_5_values)
	{
		while (b->length < 2 && a->length > 5)
		{
			if (ft_check_not_max_value(max_5_values, a->top))
				ft_ra(a, 0);
			else
			{
				if (ft_pb(a, b, 0))
				{
					free(max_5_values);
					return (NULL);
				}	
			}
		}
		return (max_5_values);
	}
	return (NULL);
}

int	ft_sort_5(t_stack *a, t_stack *b)
{
	int		*max_3_values;

	max_3_values = ft_get_max_values_sort_5(a);
	if (max_3_values)
	{
		while (a->length > 3)
		{
			if (a->top == max_3_values[0]
				|| a->top == max_3_values[1]
				|| a->top == max_3_values[2])
				ft_ra(a, 0);
			else
			{
				if (ft_pb(a, b, 0))
				{
					ft_free_tab(max_3_values);
					return (1);
				}	
			}
		}
		ft_free_tab(max_3_values);
		return (0);
	}
	return (1);
}

int	ft_sort_4(t_stack *a, t_stack *b)
{
	int		*tab_sorted;

	tab_sorted = ft_get_tab_sorted(a);
	if (!tab_sorted)
		return (1);
	while (a->top != tab_sorted[0])
		ft_ra(a, 0);
	free(tab_sorted);
	if (ft_pb(a, b, 0))
		return (1);
	ft_sort_3(a);
	if (ft_pa(a, b, 0))
		return (1);
	return (0);
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
