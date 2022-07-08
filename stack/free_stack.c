/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:20:31 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/08 22:21:35 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	ft_free_stack(t_stack *s)
{
	free(s->tab);
	free(s);
}

void	ft_free_tab(int *tab)
{
	free(tab);
}

void	ft_free_tab_and_assign(int *tab, t_stack *s)
{
	free(s->tab);
	s->tab = tab;
	s->top = s->tab[0];
	s->length = s->length + 1;
}

void	ft_create_tab_for_first_push(t_stack *s, int *tab, int value)
{
	tab[0] = value;
	ft_free_tab(s->tab);
	s->tab = tab;
	s->top = s->tab[0];
	s->length = 1;
}
