/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:22:38 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 10:32:51 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_push_swap(int *args, int amount_args)
{
	if (ft_args_is_already_sorted(args, amount_args))
	{
		free (args);
		return ;
	}
	else
	{
		if (amount_args > 10)
			ft_push_swap(args, amount_args);
		else
			ft_mini_push_swap(args, amount_args);
	}
}

int ft_args_is_already_sorted(int *args, int amount_args)
{
	int	i;

	i = 0;
	while(i < amount_args - 1)
	{
		if (args[i] > args[i + 1])
            return (0);
		i++;
	}
	return(1);
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

t_stack	*ft_initialize_a(int *args_nums, int size_args_num)
{
    t_stack	*a;

    a = (t_stack *)malloc(sizeof(t_stack));
    if (!a)
        return (NULL);
    a->top = args_nums[0];
    a->length = size_args_num;
    a->tab = args_nums;
	return (a);
}

t_stack	*ft_initialize_b(void)
{
    t_stack	*b;

    b = (t_stack *)malloc(sizeof(t_stack));
    if (!b)
        return (NULL);
    b->top = -1;
    b->length = 0;
    b->tab = NULL;
    return (b);
}
