/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:22:38 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/28 22:21:32 by dnieto-c         ###   ########.fr       */
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
		if (ft_push_swap(args, amount_args))
			write(2, "Error\n", 6);
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

int	ft_push_swap(int *args_nums, int size_args_num)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_initialize_a(args_nums, size_args_num);
	if (!a)
		return (1);
	b = ft_initialize_b();
	if (!b)
		return (ft_free_stack(a));
	if (a->length <= 3)
		ft_sort_3(a);
	else if (a->length == 4)
	{
		if (ft_sort_4(a, b))
			write(2, "Error\n", 6);
	}
	else
	{
		if (ft_begin_sort(a, b))
			write(2, "Error\n", 6);
	}
	ft_free_stacks(a, b);
	return (0);
}
