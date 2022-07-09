/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:16:33 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/09 19:44:34 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	ft_pa(t_stack *a, t_stack *b, int for_checker)
{
	ft_push(b, a);
	if (!for_checker)
		ft_printf("pa\n");
}

void	ft_pb(t_stack *a, t_stack *b, int for_checker)
{
	ft_push(a, b);
	if (!for_checker)
		ft_printf("pb\n");
}

void	ft_push(t_stack *s1, t_stack *s2)
{
	int	value_push;

	if (s1->length > 0)
	{
		value_push = s1->tab[0];
		ft_update_from_push(s1);
		ft_update_to_push(s2, value_push);
	}
}

void	ft_update_from_push(t_stack *s)
{
	int		*new_tab;
	int		i;

	if ((s->length - 1) == 0)
	{
		s->top = -1;
		s->length = 0;
		ft_free_tab(s->tab);
		s->tab = 0;
		return ;
	}
	new_tab = (int *)malloc(sizeof(int) * (s->length - 1));
	if (!new_tab)
		return ;
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
}

void	ft_update_to_push(t_stack *s, int value)
{
	int		*new_tab;
	int		i;

	if (!s->tab)
	{
		new_tab = (int *)malloc(sizeof(int) * 1);
		if (!new_tab)
			return ;
		ft_create_tab_for_first_push(s, new_tab, value);
	}
	else
	{
		new_tab = (int *)malloc(sizeof(int) * (s->length + 1));
		if (!new_tab)
			return ;
		new_tab[0] = value;
		i = 1;
		while (i <= s->length)
		{
			new_tab[i] = s->tab[i - 1];
			i++;
		}
		ft_free_tab_and_assign(new_tab, s);
	}
}
