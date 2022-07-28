/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ps_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:44:18 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/28 23:03:36 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_get_max_values_first_step(t_stack *a)
{
	int		*max_values;
	int		*tab_sorted;
	int		i;
	int		temp;

	tab_sorted = ft_get_tab_sorted(a);
	if (!tab_sorted)
		return (NULL);
	max_values = (int *)malloc(sizeof(int) * (5));
	if (!max_values)
	{
		ft_free_tab(tab_sorted);
		return (NULL);
	}
	if (a->length == 4)
		temp = a->length - 4;
	else
		temp = a->length - 5;
	i = 0;
	while (temp < a->length)
		max_values[i++] = tab_sorted[temp++];
	ft_free_tab(tab_sorted);
	return (max_values);
}

int	*ft_get_max_values_sort_5(t_stack *a)
{
	int		*max_3_values;
	int		*tab_sorted;
	int		i;
	int		temp;

	tab_sorted = ft_get_tab_sorted(a);
	if (!tab_sorted)
		return (NULL);
	max_3_values = (int *)malloc(sizeof(int) * (3));
	if (!max_3_values)
	{
		ft_free_tab(tab_sorted);
		return (NULL);
	}
	temp = a->length - 3;
	i = 0;
	while (temp < a->length)
		max_3_values[i++] = tab_sorted[temp++];
	ft_free_tab(tab_sorted);
	return (max_3_values);
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

int	ft_check_not_max_value(int *max_5_values, int value)
{
	if (value == max_5_values[0]
		|| value == max_5_values[1]
		|| value == max_5_values[2]
		|| value == max_5_values[3]
		|| value == max_5_values[4])
		return (1);
	return (0);
}
