/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:22:38 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/08 22:08:32 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_do_push_swap(int *args, int amount_args)
{
	if (ft_args_is_already_sorted(args, amount_args))
	{
		free (args);
		return ;
	}
	else
	{
		if (amount_args > 5)
			ft_push_swap(args, amount_args);
		else
			ft_mini_push_swap(args, amount_args);
	}
}

int	ft_args_is_already_sorted(int *args, int amount_args)
{
	int	i;

	i = 0;
	while (i < amount_args - 1)
	{
		if (args[i] > args[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_push_swap(int *args_nums, int size_args_num)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_initialize_a(args_nums, size_args_num);
	b = ft_initialize_b();
	ft_sort(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
}

void	ft_mini_push_swap(int *args_nums, int size_args_num)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_initialize_a(args_nums, size_args_num);
	b = ft_initialize_b();
	if (size_args_num == 2)
	{
		if (a->tab[0] > a->tab[1])
			ft_sa(a);
	}
	else if (size_args_num == 3)
		ft_sort_3(a);
	else
		ft_mini_sort(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
}
