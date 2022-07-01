/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:09:43 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 13:08:02 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	ft_reverse(t_stack *s)
{
	int	i;
	int	value_to_first;

	if (s->length >= 2)
	{
		i = 0;
		while (i < s->length)
			i++;
		value_to_first = s->tab[i - 1];
		i = s->length - 1;
		while(i > 0)
		{
			s->tab[i] = s->tab[i - 1];
			i--;
		}
		s->tab[0] = value_to_first;
		s->top = s->tab[0];
	}
}

void	ft_rra(t_stack *a)
{
	ft_reverse(a);
	printf("rra\n");
}

void	ft_rrb(t_stack *b)
{
	ft_reverse(b);
	printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse(a);
	ft_reverse(b);
	printf("rrr\n");
}