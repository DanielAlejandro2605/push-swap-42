/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:45:40 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 10:45:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_do_ra(t_stack *a, int number_ra)
{
	int	i;

	i = 0;
	while (i < number_ra)
	{
		ft_ra(a);
		i++;
	}
}

void	ft_do_rb(t_stack *b, int number_rb)
{
	int	i;

	i = 0;
	while (i < number_rb)
	{
		ft_rb(b);
		i++;
	}
}

void	ft_do_rra(t_stack *a, int number_rra)
{
	int	i;

	i = 0;
	while (i < number_rra)
	{
		ft_rra(a);
		i++;
	}
}

void	ft_do_rrb(t_stack *b, int number_rrb)
{
	int	i;

	i = 0;
	while (i < number_rrb)
	{
		ft_rrb(b);
		i++;
	}
}

void	ft_do_rr(t_stack *a, t_stack *b, int number_rr)
{
	int	i;

	i = 0;
	while (i < number_rr)
	{
		ft_rr(a, b);
		i++;
	}
}
