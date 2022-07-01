/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:40:12 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 12:57:43 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_value_is_in_stack(t_stack *s, int value)
{
	int	i;

	i = 0;
	while (i < s->length)
	{
		if (s->tab[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void    ft_do_rrr(t_stack *a, t_stack *b, int number_rrr)
{
    int i;

    i = 0;
    while (i < number_rrr)
    {
        ft_rrr(a, b);
        i++;
    }
}
