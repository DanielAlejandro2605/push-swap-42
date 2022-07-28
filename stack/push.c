/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:16:33 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/28 19:05:41 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	ft_pa(t_stack *a, t_stack *b, int for_checker)
{
	if (ft_push(b, a))
		return (1);
	if (!for_checker)
		ft_printf("pa\n");
	return (0);
}

int	ft_pb(t_stack *a, t_stack *b, int for_checker)
{
	if (ft_push(a, b))
		return (1);
	if (!for_checker)
		ft_printf("pb\n");
	return (0);
}

int	ft_push(t_stack *s1, t_stack *s2)
{
	int	value_push;

	if (s1->length > 0)
	{
		value_push = s1->tab[0];
		if (ft_update_from_push(s1))
			return (1);
		if (ft_update_to_push(s2, value_push))
			return (1);
		return (0);
	}
	return (0);
}

int	ft_update_from_push(t_stack *s)
{
	int		*new_tab;
	int		i;

	if ((s->length - 1) == 0)
	{
		s->top = -1;
		s->length = 0;
		ft_free_tab(s->tab);
		s->tab = 0;
		return (0);
	}
	new_tab = (int *)malloc(sizeof(int) * (s->length - 1));
	if (!new_tab)
		return (1);
	i = 1;
	while (i < s->length)
	{
		new_tab[i - 1] = s->tab[i];
		i++;
	}
	ft_free_tab(s->tab);
	s->tab = new_tab;
	s->top = s->tab[0];
	s->length = s->length - 1;
	return (0);
}

int	ft_update_to_push(t_stack *s, int value)
{
	int		*new_tab;
	int		i;

	if (!s->tab)
	{
		new_tab = (int *)malloc(sizeof(int) * 1);
		if (!new_tab)
			return (1);
		ft_create_tab_for_first_push(s, new_tab, value);
	}
	else
	{
		new_tab = (int *)malloc(sizeof(int) * (s->length + 1));
		if (!new_tab)
			return (1);
		new_tab[0] = value;
		i = 1;
		while (i <= s->length)
		{
			new_tab[i] = s->tab[i - 1];
			i++;
		}
		ft_free_tab_and_assign(new_tab, s);
	}
	return (0);
}
