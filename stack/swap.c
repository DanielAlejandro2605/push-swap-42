/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:53 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 12:58:32 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void    ft_swap(t_stack *s)
{   
    int tmp;

    if (s && s->length > 1)
    {
        tmp = s->tab[0];
        s->tab[0] = s->tab[1];
        s->tab[1] = tmp;
        s->top = s->tab[0];   
    }
}

void	ft_sa(t_stack *a, t_stack *b)
{
	ft_swap(a);
	(void)b;
}

void	ft_sb(t_stack *a, t_stack *b)
{
	(void)a;
	ft_swap(b);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
}