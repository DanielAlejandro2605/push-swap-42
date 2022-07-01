/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:37:22 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 10:37:22 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_better_case_for_take_top(t_stack *s, int value)
{
	int	i;

	if (ft_value_is_in_stack(s, value))
	{
		i = 0;
		while (i < s->length)
		{
			if (s->tab[i] == value)
				break ;
			i++;
		}
		if (i <= (s->length / 2))
			return (1);
		else
			return (2);
	}
	return (0);
}

int	ft_get_ideal_value_in_b(int value_to_push, t_stack *b)
{
	int	ideal_value;

	if (ft_value_is_biggest_than_all(value_to_push, b))
	{
		ideal_value = ft_search_biggest_in_b(b);
	}
	else
		ideal_value = ft_search_biggest_less_than_value(value_to_push, b);
	return (ideal_value);
}

int	ft_search_biggest_in_b(t_stack *b)
{
	int	biggest_b;
	int	i;

	i = 0;
	biggest_b = b->tab[0];
	while (i < b->length)
	{
		if (b->tab[i] > biggest_b)
			biggest_b = b->tab[i];
		i++;
	}
	return (biggest_b);
}

int	ft_value_is_biggest_than_all(int value, t_stack *b)
{
	int	i;

	i = 0;
	while (i < b->length)
	{
		if (value > b->tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_search_biggest_less_than_value(int value, t_stack *b)
{
	int	biggest_less;
	int	i;

	i = 0;
	biggest_less = '\0';
	while (i < b->length)
	{
		if (b->tab[i] < value)
		{
			if (biggest_less == '\0')
				biggest_less = b->tab[i];
			else
			{
				if (b->tab[i] > biggest_less)
					biggest_less = b->tab[i];
			}
		}
		i++;
	}
	return (biggest_less);
}
