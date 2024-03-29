/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:09:37 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/06/10 19:09:37 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	ft_rotate(t_stack *s)
{
	int	value_to_last;
	int	i;

	value_to_last = s->tab[0];
	if (s->length >= 2)
	{
		i = 1;
		while (i < s->length)
		{
			s->tab[i - 1] = s->tab[i];
			i++;
		}
		s->tab[i - 1] = value_to_last;
		s->top = s->tab[0];
	}
}

void	ft_ra(t_stack *a, int for_checker)
{
	ft_rotate(a);
	if (!for_checker)
		ft_printf("ra\n");
}

void	ft_rb(t_stack *b, int for_checker)
{
	ft_rotate(b);
	if (!for_checker)
		ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b, int for_checker)
{
	ft_rotate(a);
	ft_rotate(b);
	if (!for_checker)
		ft_printf("rr\n");
}
