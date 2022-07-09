/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:53 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/09 19:45:34 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	ft_swap(t_stack *s)
{
	int	tmp;

	if (s && s->length > 1)
	{
		tmp = s->tab[0];
		s->tab[0] = s->tab[1];
		s->tab[1] = tmp;
		s->top = s->tab[0];
	}
}

void	ft_sa(t_stack *a, int for_checker)
{
	ft_swap(a);
	if (!for_checker)
		ft_printf("sa\n");
}

void	ft_sb(t_stack *b, int for_checker)
{
	ft_swap(b);
	if (!for_checker)
		ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b, int for_checker)
{
	ft_swap(a);
	ft_swap(b);
	if (!for_checker)
		ft_printf("ss\n");
}
